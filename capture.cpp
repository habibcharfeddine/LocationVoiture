#include "capture.h"
#include "ui_capture.h"
#include<QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include<QMenu>
#include <QAction>
#include<QFileDialog>

capture::capture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capture)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
           mCameraViewfinder =new QCameraViewfinder(this);
           mCameraImageCapture = new QCameraImageCapture(mCamera, this);
           mLayout = new QVBoxLayout;
           mOptionMenu = new QMenu("Options", this );
                  mEncenderAction =new QAction ("Encender",this);
                  mApagarAction = new QAction ("Apagar",this);
                  mCapturarAction =new QAction ("Captura",this);
                  mOptionMenu->addActions({mEncenderAction,mApagarAction,mCapturarAction});
                  ui->option_pushButton->setMenu(mOptionMenu);
                         mCamera->setViewfinder(mCameraViewfinder);
                         mLayout->addWidget(mCameraViewfinder);
                         mLayout->setMargin(0);
                         ui->scrollArea->setLayout(mLayout);
                         connect(mEncenderAction,&QAction::triggered,[&] (){
                                     mCamera->start();


                                 });

                                 connect(mApagarAction,&QAction::triggered, [&](){
                                     mCamera->stop();
                                     mCamera->destroyed(this);

                                 });
                                 connect(mCapturarAction,&QAction::triggered,[&](){
                                              mCamera->start();
                                            auto filename=  QFileDialog::getSaveFileName(this,"Capturar","/", "Imagen (*.jpg;*.jpeg)");
                                         if(filename.isEmpty())
                                         {return ;}
                                         mCameraImageCapture->setCaptureDestination(
                                                             QCameraImageCapture::CaptureToFile);
                                                 QImageEncoderSettings imageEncoderSettings ;
                                                 imageEncoderSettings.setCodec("image/jpeg");
                                                 imageEncoderSettings.setResolution(1600,1200);
                                                 mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
                                                         mCamera->setCaptureMode(QCamera::CaptureStillImage);
                                                         mCamera->start();
                                                         mCamera->searchAndLock();
                                                         mCameraImageCapture->capture(filename);
                                                         mCamera->unlock();
                                                         });
}

capture::~capture()
{
    delete ui;
}
