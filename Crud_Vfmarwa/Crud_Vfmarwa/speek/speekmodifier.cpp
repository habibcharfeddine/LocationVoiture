#include "speekmodifier.h"
#include "ui_speekmodifier.h"
#include <QLoggingCategory>
SpeekModifier::SpeekModifier(QWidget *parent) :
    QDialog(parent),
    m_speech(0)
{
    ui.setupUi(this);
    ui.engine->addItem("Default", QString("default"));
    const auto engines = QTextToSpeech::availableEngines();
    for (const QString &engine : engines)
        ui.engine->addItem(engine, engine);
    ui.engine->setCurrentIndex(0);
    engineSelected(0);

    connect(ui.speakButton, &QPushButton::clicked, this, &SpeekModifier::speak);
    connect(ui.pitch, &QSlider::valueChanged, this, &SpeekModifier::setPitch);
    connect(ui.rate, &QSlider::valueChanged, this, &SpeekModifier::setRate);
    connect(ui.volume, &QSlider::valueChanged, this, &SpeekModifier::setVolume);
    connect(ui.engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekModifier::engineSelected);
}

void SpeekModifier::speak()
{
    m_speech->say(ui.plainTextEdit->toPlainText());
}
void SpeekModifier::stop()
{
    m_speech->stop();
}

void SpeekModifier::setRate(int rate)
{
    m_speech->setRate(rate / 10.0);
}

void SpeekModifier::setPitch(int pitch)
{
    m_speech->setPitch(pitch / 10.0);
}

void SpeekModifier::setVolume(int volume)
{
    m_speech->setVolume(volume / 100.0);
}

void SpeekModifier::stateChanged(QTextToSpeech::State state)
{
    /*if (state == QTextToSpeech::Speaking) {
        ui.statusbar->showMessage("Speech started...");
    } else if (state == QTextToSpeech::Ready)
        ui.statusbar->showMessage("Speech stopped...", 2000);
    else if (state == QTextToSpeech::Paused)
        ui.statusbar->showMessage("Speech paused...");
    else
        ui.statusbar->showMessage("Speech error!");*/

    ui.pauseButton->setEnabled(state == QTextToSpeech::Speaking);
    ui.resumeButton->setEnabled(state == QTextToSpeech::Paused);
    ui.stopButton->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
}

void SpeekModifier::engineSelected(int index)
{
    QString engineName = ui.engine->itemData(index).toString();
    delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);
    disconnect(ui.language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekModifier::languageSelected);
    ui.language->clear();
    // Populate the languages combobox before connecting its signal.
    const QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    for (const QLocale &locale : locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        ui.language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;
    }
    setRate(ui.rate->value());
    setPitch(ui.pitch->value());
    setVolume(ui.volume->value());
    connect(ui.stopButton, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
    connect(ui.pauseButton, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
    connect(ui.resumeButton, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

    connect(m_speech, &QTextToSpeech::stateChanged, this, &SpeekModifier::stateChanged);
    connect(m_speech, &QTextToSpeech::localeChanged, this, &SpeekModifier::localeChanged);

    connect(ui.language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekModifier::languageSelected);
    localeChanged(current);
}

void SpeekModifier::languageSelected(int language)
{
    QLocale locale = ui.language->itemData(language).toLocale();
    m_speech->setLocale(locale);
}

void SpeekModifier::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void SpeekModifier::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    ui.language->setCurrentIndex(ui.language->findData(localeVariant));

    disconnect(ui.voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekModifier::voiceSelected);
    ui.voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    for (const QVoice &voice : qAsConst(m_voices)) {
        ui.voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          .arg(QVoice::genderName(voice.gender()))
                          .arg(QVoice::ageName(voice.age())));
        if (voice.name() == currentVoice.name())
            ui.voice->setCurrentIndex(ui.voice->count() - 1);
    }
    connect(ui.voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekModifier::voiceSelected);
}

