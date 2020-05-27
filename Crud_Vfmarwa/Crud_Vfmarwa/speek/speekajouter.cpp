#include "speekajouter.h"
#include "ui_speekajouter.h"
#include <QLoggingCategory>
#include <QString>
#include <QDebug>
SpeekAjouter::SpeekAjouter(QWidget *parent) :
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

    connect(ui.speakButton, &QPushButton::clicked, this, &SpeekAjouter::speak);
    connect(ui.pitch, &QSlider::valueChanged, this, &SpeekAjouter::setPitch);
    connect(ui.rate, &QSlider::valueChanged, this, &SpeekAjouter::setRate);
    connect(ui.volume, &QSlider::valueChanged, this, &SpeekAjouter::setVolume);
    connect(ui.engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekAjouter::engineSelected);
}

void SpeekAjouter::speak()
{
    m_speech->say(ui.plainTextEdit->toPlainText());
}
void SpeekAjouter::ajouterclient(QString q)
{m_speech->say( " Client " + q + " a étè ajouter avec succès");}
void SpeekAjouter::ajouteravisclient(QString q)
{m_speech->say( " Avis client " + q + " a étè ajouter avec succès");}

void SpeekAjouter::modifieravisclient()
{m_speech->say( " avis client  a étè modifier avec succès");}
void SpeekAjouter::modifierclient()
{m_speech->say( " client  a étè modifier avec succès");}

void SpeekAjouter::supprimerclient()
{m_speech->say( " client  a étè supprimer avec succès");}
void SpeekAjouter::supprimeravisclient()
{m_speech->say( " Avis client  a étè supprimer avec succès");}

void SpeekAjouter::afficherlisteclient()
{m_speech->say( " Liste des clients");}
void SpeekAjouter::affichelisteavisclient()
{m_speech->say( " Liste des avis clients ");}

void SpeekAjouter::ajoutimage()
{m_speech->say("Ajouter image ");}
void SpeekAjouter::modifierimage()
{m_speech->say("Modifier image");}
void SpeekAjouter::capture()
{m_speech->say("Capture camera ");}
void SpeekAjouter::statistique()
{m_speech->say("Statistique");}
void SpeekAjouter::ouvrirhistorique()
{m_speech->say("Historique des client");}
void SpeekAjouter::imprimer()
{m_speech->say("Imprimer historique");}
void SpeekAjouter::fournisseurfr()
{m_speech->say("Fournisseur");}
void SpeekAjouter::fournisseuren()
{m_speech->say("supplier");}

void SpeekAjouter::historiquefr()
{m_speech->say("Historique");}
void SpeekAjouter::historiqueen()
{m_speech->say("Historical");}

void SpeekAjouter::english()
{m_speech->say("you choose english like a language");}
void SpeekAjouter::francais()
{m_speech->say("vous avez choisie francais comme un langue");}
void SpeekAjouter::clicked()
{m_speech->say("Category has been Selected ");}
void SpeekAjouter::selectionee()
{m_speech->say("Catégorie Selectionnée");}
void SpeekAjouter::trieCroissanten()
{m_speech->say("Sort Ascending from IdCategory");}
void SpeekAjouter::trieCroissantfr()
{m_speech->say("Trier Croissant du IdCatégorie");}
void SpeekAjouter::trieDeroissanten()
{m_speech->say("Sort Descending from IdCategory");}
void SpeekAjouter::trieDeroissantfr()
{ m_speech->say("Trier Décroissant du IdCatégorie");}
void SpeekAjouter::trieCroissantena()
{m_speech->say("Sort by A-Z");}
void SpeekAjouter::trieCroissantfra()
{  m_speech->say("Trier A-Z");}
void SpeekAjouter::trieDecroissantena()
{m_speech->say("Sort by Z-A");}
void SpeekAjouter::trieDecroissantfra()
{m_speech->say("Trier Z-A");}
void SpeekAjouter::rechercheen()
{m_speech->say("Research");}
void SpeekAjouter::recherchefr()
{m_speech->say("Recherche");}
void SpeekAjouter::ajouterimageen()
{m_speech->say("Add picture");}
void SpeekAjouter::ajouterimagefr()
{m_speech->say("Ajouter image");}
void SpeekAjouter::modifierimageen()
{m_speech->say("Edit picture");}
void SpeekAjouter::modifierimagefr()
{m_speech->say("Modifier image");}
void SpeekAjouter::Croissantprixen()
{m_speech->say("Sort Ascending of Price");}
void SpeekAjouter::Croissantprixfr()
{m_speech->say("Tri Croissant du Prix");}
void SpeekAjouter::Decroissantprixen()
{m_speech->say("Sort Descending  of Price");}
void SpeekAjouter::Decroissantprixfr()
{m_speech->say("Tri Décroissant du Prix");}
void SpeekAjouter::Croissantstocken()
{m_speech->say("Sort Ascending of Stock");}
void SpeekAjouter::Croissantstockfr()
{m_speech->say("Tri Croissant du Stock");}
void SpeekAjouter::Decroissantstocken()
{m_speech->say("Sort Descending of Stock");}
void SpeekAjouter::Decroissantstockfr()
{m_speech->say("Tri Décroissant du Stock");}
void SpeekAjouter::Croissantmen()
{m_speech->say("Sort  Ascending of IdMaterial");}
void SpeekAjouter::Croissantmfr()
{m_speech->say("Tri Croissant d'IdMatériel");}
void SpeekAjouter::Decroissantemen()
{m_speech->say("Sort  Descending of IdMaterial");}
void SpeekAjouter::Decroissantemfr()
{m_speech->say("Tri Décroissant d'IdMatériel");}
void SpeekAjouter::creationpdfen()
{m_speech->say("PDF creation");}
void SpeekAjouter::creationpdffr()
{m_speech->say("Création PDF");}
void SpeekAjouter::clickedmen()
{m_speech->say("Selected Material");}
void SpeekAjouter::clickedmfr()
{m_speech->say("Matériel Sélectionée");}
void SpeekAjouter::clickedena()
{m_speech->say("Selected Assignment");}
void SpeekAjouter::clickedfra()
{m_speech->say("Affectation Sélectionnée");}
void SpeekAjouter::trieCroissantenaff()
{m_speech->say("Sort Ascending by idA");}
void SpeekAjouter::trieCroissantfraff()
{m_speech->say("Tri Croissant par idA ");}
void SpeekAjouter::trieDecroissantenaff()
{m_speech->say("Sort Descending by idA");}
void SpeekAjouter::trieDecroissantfraff()
{m_speech->say("Tri Décroissant par idA ");}
void SpeekAjouter::trieCroissantenm()
{m_speech->say("Sort Ascending by idM");}
void SpeekAjouter::trieCroissantfrm()
{m_speech->say("Tri Croissant par idM ");}
void SpeekAjouter::trieDecroissantenm()
{m_speech->say("Sort Descending by idM");}
void SpeekAjouter::trieDecroissantfrm()
{m_speech->say("Tri Décroissant par idM ");}
void SpeekAjouter::trieCroissantenf()
{m_speech->say("Sort Ascending by IdSupplier");}
void SpeekAjouter::trieCroissantfrf()
{m_speech->say("Trier Croissant d'IdFournisseur");}
void SpeekAjouter::Decroissantenf()
{m_speech->say("Sort Descending by IdSupplier");}
void SpeekAjouter::Decroissantfrf()
{m_speech->say("Trier Decroissant d'IdFournisseur");}
void SpeekAjouter::Coissantageen()
{m_speech->say("Sort Ascending  by Age");}
void SpeekAjouter::Coissantagefr()
{m_speech->say("Trier Croissant d'Age ");}
void SpeekAjouter::Decroissantageen()
{m_speech->say("Sort Descending  by Age");}
void SpeekAjouter::Decroissantagefr()
{m_speech->say("Trier Decroissant d'Age ");}
void SpeekAjouter::statistiqueFen()
{m_speech->say("Supplier Statistics");
}
void SpeekAjouter::statistiqueFfr()
{m_speech->say("Statistique Fournisseur ");
}
void SpeekAjouter::clickedmailen()
{m_speech->say("Mail Selected  ");
}
void SpeekAjouter::clickedmailfr()
{m_speech->say("Mail Selectionnée");
}
void SpeekAjouter::phoneaffen()
{m_speech->say("Show Phone Number Supplier ");
}
void SpeekAjouter::phoneafffr()
{m_speech->say("Lister les num tel des fournisseur");
}
void SpeekAjouter::stop()
{
    m_speech->stop();
}

void SpeekAjouter::setRate(int rate)
{
    m_speech->setRate(rate / 10.0);
}

void SpeekAjouter::setPitch(int pitch)
{
    m_speech->setPitch(pitch / 10.0);
}

void SpeekAjouter::setVolume(int volume)
{
    m_speech->setVolume(volume / 100.0);
}

void SpeekAjouter::stateChanged(QTextToSpeech::State state)
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

void SpeekAjouter::engineSelected(int index)
{
    QString engineName = ui.engine->itemData(index).toString();
    delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);
    //disconnect(ui.language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekAjouter::languageSelected);
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

    connect(m_speech, &QTextToSpeech::stateChanged, this, &SpeekAjouter::stateChanged);
    connect(m_speech, &QTextToSpeech::localeChanged, this, &SpeekAjouter::localeChanged);

    //connect(ui.language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekAjouter::languageSelected);
    localeChanged(current);
}

/*void SpeekAjouter::languageSelected(int language)
{
    QLocale locale = ui.language->itemData(language).toLocale();
    m_speech->setLocale(locale);
    qDebug() << language ;
}*/
void SpeekAjouter::languageSelectedfr()
{
    QLocale locale = ui.language->itemData(0).toLocale();
    m_speech->setLocale(locale);

}
void SpeekAjouter::languageSelecteden()
{
    QLocale locale = ui.language->itemData(1).toLocale();
    m_speech->setLocale(locale);

}
void SpeekAjouter::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void SpeekAjouter::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    ui.language->setCurrentIndex(ui.language->findData(localeVariant));

    disconnect(ui.voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekAjouter::voiceSelected);
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
    connect(ui.voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &SpeekAjouter::voiceSelected);
}
