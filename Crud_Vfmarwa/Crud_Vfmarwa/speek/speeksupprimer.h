#ifndef SPEEKSUPPRIMER_H
#define SPEEKSUPPRIMER_H

#include <QDialog>
#include <QtWidgets/qmainwindow.h>
#include <QTextToSpeech>
#include "ui_speeksupprimer.h"


class SpeekSupprimer : public QDialog
{
    Q_OBJECT

public:
    explicit SpeekSupprimer(QWidget *parent = nullptr);
   // ~SpeekSupprimer();
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
    Ui::SpeekSupprimer ui;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
};

#endif // SPEEKSUPPRIMER_H
