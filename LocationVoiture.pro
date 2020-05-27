#-------------------------------------------------
#
# Project created by QtCreator 2020-04-01T15:52:29
#
#-------------------------------------------------

QT       += core gui network  printsupport
QT       +=sql
QT       += core gui sql charts network
QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Entraineur
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    AVIS_CLIENT.cpp \
    Assurance.cpp \
    AssuranceAfficher.cpp \
    AssuranceAjout.cpp \
    AssuranceGestion.cpp \
    CLIENT.cpp \
    ClientAvis.cpp \
    Departement.cpp \
    DepartementAfficher.cpp \
    DepartementAjout.cpp \
    DepartementGestion.cpp \
    EventGestion.cpp \
    GUI_AssuranceSociete.cpp \
    GUI_ClientAvis.cpp \
    GUI_EventPromo.cpp \
    GUI_LocationPointsF.cpp \
    GUI_PersonnelDepart.cpp \
    GUI_VoitureParking.cpp \
    Location.cpp \
    LocationAjout.cpp \
    LocationGestion.cpp \
    Personnel.cpp \
    PersonnelAfficher.cpp \
    PersonnelAjout.cpp \
    PersonnelGestion.cpp \
    Point.cpp \
    PointAjout.cpp \
    PointsGestion.cpp \
    PromoGestion.cpp \
    Societe.cpp \
    SocieteAfficher.cpp \
    SocieteAjout.cpp \
    SocieteGestion.cpp \
    VoitureParking.cpp \
    acceuil.cpp \
    capture.cpp \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    parking.cpp \
    qcustomplot.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp \
    statistique.cpp \
    stmp.cpp \
    voiture.cpp


HEADERS += \
    AVIS_CLIENT.h \
    Assurance.h \
    AssuranceAfficher.h \
    AssuranceAjout.h \
    AssuranceGestion.h \
    CLIENT.h \
    ClientAvis.h \
    Departement.h \
    DepartementAfficher.h \
    DepartementAjout.h \
    DepartementGestion.h \
    EventGestion.h \
    GUI_AssuranceSociete.h \
    GUI_ClientAvis.h \
    GUI_EventPromo.h \
    GUI_LocationPointsF.h \
    GUI_PersonnelDepart.h \
    GUI_VoitureParking.h \
    Location.h \
    LocationAjout.h \
    LocationGestion.h \
    Personnel.h \
    PersonnelAfficher.h \
    PersonnelAjout.h \
    PersonnelGestion.h \
    Point.h \
    PointAjout.h \
    PointsGestion.h \
    PromoGestion.h \
    Societe.h \
    SocieteAfficher.h \
    SocieteAjout.h \
    SocieteGestion.h \
    VoitureParking.h \
    acceuil.h \
    capture.h \
        mainwindow.h \
    connexion.h \
    parking.h \
    qcustomplot.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/qucustomplot.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    statistique.h \
    stmp.h \
    voiture.h


FORMS += \
    AssuranceAfficher.ui \
    AssuranceAjout.ui \
    AssuranceGestion.ui \
    ClientAvis.ui \
    DepartementAfficher.ui \
    DepartementAjout.ui \
    DepartementGestion.ui \
    EventGestion.ui \
    GUI_AssuranceSociete.ui \
    GUI_ClientAvis.ui \
    GUI_EventPromo.ui \
    GUI_LocationsPointsF.ui \
    GUI_PersonnelDepart.ui \
    GUI_VoitureParking.ui \
    LocationAjout.ui \
    LocationGestion.ui \
    PersonnelAfficher.ui \
    PersonnelAjout.ui \
    PersonnelGestion.ui \
    PointAjout.ui \
    PointsGestion.ui \
    PromoGestion.ui \
    SocieteAfficher.ui \
    SocieteAjout.ui \
    SocieteGestion.ui \
    VoitureParking.ui \
    acceuil.ui \
    capture.ui \
        mainwindow.ui \
    statistique.ui

RESOURCES += \
    images.qrc
