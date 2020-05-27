#ifndef SPEEKAJOUTER_H
#define SPEEKAJOUTER_H

#include <QDialog>

#include <QtWidgets/qmainwindow.h>
#include <QTextToSpeech>
#include "ui_speekajouter.h"

class SpeekAjouter : public QDialog
{
    Q_OBJECT

public:
    explicit SpeekAjouter(QWidget *parent = nullptr);
   // ~SpeekAjouter();
    void speak();

    void stop();

    void setRate(int);
    void setPitch(int);
    void setVolume(int volume);

    void stateChanged(QTextToSpeech::State state);
    void engineSelected(int index);
   // void languageSelected(int language);
    void voiceSelected(int index);

    void localeChanged(const QLocale &locale);



    void languageSelectedfr();
    void languageSelecteden();


    void categoriematerielfr();
    void categoriematerielen();
    void affectationfr();
    void affectationen();
    void materielfr();
    void materielen();
    void fournisseurfr();
    void fournisseuren();
    void historiquefr();
    void historiqueen();
    void english();
    void francais();
    void clicked();
    void selectionee();
    void trieCroissanten();
    void trieCroissantfr();
    void trieDeroissanten();
    void trieDeroissantfr();
    void trieCroissantena();
    void trieCroissantfra();
    void trieDecroissantena();
    void trieDecroissantfra();
    void rechercheen();
    void recherchefr();
    void ajouterimageen();
    void ajouterimagefr();
    void modifierimageen();
    void modifierimagefr();
    void Croissantprixen();
    void Croissantprixfr();
    void Decroissantprixen();
    void Decroissantprixfr();
    void Croissantstocken();
    void Croissantstockfr();
    void Decroissantstocken();
    void Decroissantstockfr();
    void Croissantmen();
    void Croissantmfr();
    void Decroissantemen();
    void Decroissantemfr();
    void creationpdfen();
    void creationpdffr();
    void clickedmen();
    void clickedmfr();
    void clickedena();
    void clickedfra();
    void trieCroissantenaff();
    void trieCroissantfraff();
    void trieDecroissantenaff();
    void trieDecroissantfraff();
    void trieCroissantenm();
    void trieCroissantfrm();
    void trieDecroissantenm();
    void trieDecroissantfrm();
    void trieCroissantenf();
    void trieCroissantfrf();
    void Decroissantenf();
    void Decroissantfrf();
    void Coissantageen();
    void Coissantagefr();
    void Decroissantageen();
    void Decroissantagefr();
    void statistiqueFen();
    void statistiqueFfr();
    void clickedmailen();
    void clickedmailfr();
    void phoneaffen();
    void phoneafffr();

    void ajouterclient(QString q);
    void ajouteravisclient(QString q);
    void supprimerclient();
    void supprimeravisclient();
    void afficherlisteclient();
    void affichelisteavisclient();
    void modifieravisclient();
    void modifierclient();
    void ajoutimage();
    void modifierimage();
    void capture();
    void statistique();
    void ouvrirhistorique();
    void imprimer();
private:
    Ui::SpeekAjouter ui;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;

};

#endif // SPEEKAJOUTER_H
