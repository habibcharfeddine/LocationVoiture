#ifndef SPEEKMODIFIER_H
#define SPEEKMODIFIER_H

#include <QDialog>
#include <QtWidgets/qmainwindow.h>
#include <QTextToSpeech>
#include "ui_speekmodifier.h"


class SpeekModifier : public QDialog
{
    Q_OBJECT

public:
    explicit SpeekModifier(QWidget *parent = nullptr);
    //~SpeekModifier();
    void speak();

    void stop();

    void setRate(int);
    void setPitch(int);
    void setVolume(int volume);

    void stateChanged(QTextToSpeech::State state);
    void engineSelected(int index);
    void languageSelected(int language);
    void voiceSelected(int index);

    void localeChanged(const QLocale &locale);
private:
    Ui::SpeekModifier ui;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
};

#endif // SPEEKMODIFIER_H
