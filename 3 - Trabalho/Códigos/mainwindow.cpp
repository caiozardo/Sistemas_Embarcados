
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QMessageBox>
#include <QMetaEnum>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QCoreApplication>
#include <QFileInfo>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QFileDialog>
#include<QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{

  ui->setupUi(this);

  //config da serial
  arduino_is_available = false;
  arduino_port_name ="";
  arduino = new QSerialPort;


  qDebug() << "Numero de portas diponiveis : " << QSerialPortInfo::availablePorts().length();
      foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
          qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
          if(serialPortInfo.hasVendorIdentifier()){
              qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
          }
          qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
          if(serialPortInfo.hasProductIdentifier()){
              qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
          }
      }


      foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
          if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
              if(serialPortInfo.vendorIdentifier() == arduino_nano_vendor_id || serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id ){
                  if(serialPortInfo.productIdentifier() == arduino_nano_product_id || serialPortInfo.productIdentifier() == arduino_uno_product_id){
                      arduino_port_name = serialPortInfo.portName();
                      arduino_is_available = true;
                  }
              }
          }
      }
  if(arduino_is_available){

      qDebug() <<"Dispositivo conectado";
      arduino->setPortName(arduino_port_name);
      arduino->open(QSerialPort::ReadOnly);
      arduino->setBaudRate(QSerialPort::Baud9600);
      arduino->setDataBits(QSerialPort::Data8);
      arduino->setParity(QSerialPort::NoParity);
      arduino->setStopBits(QSerialPort::OneStop);
      arduino->setFlowControl(QSerialPort::NoFlowControl);

      QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
  }else{

    QMessageBox::information(this, "Healty Heartbeats", "Modulo não conectado.");
    /*  QFile file(nomearquivo);

          if(!file.open(QFile::ReadOnly |
                        QFile::Text))
          {
              qDebug() << " erro ao abrir os arquivos";
              return;
          }
            QTextStream in(&file);
                while (!in.atEnd())
                {
                   fakeBuffer = in.readLine();
                    qDebug()<< fakeBuffer;
                    //arq[ct] = fakeBuffer;
                    ct++;
                    fakeBuffer.clear();
                }


                file.flush();
                file.close();


        */


  }


  setGeometry(400, 250, 542, 390);
  
  setupDemo(0);

  // 0: setupRealtimeDataDemo(ui->customPlot);
}

void MainWindow::setupDemo(int demoIndex)
{
  switch (demoIndex)
  {
    case 0: setupRealtimeDataDemo(ui->customPlot); break;

  }
  setWindowTitle("ECG GRÁFICO: "+ demoName);
  statusBar()->clearMessage();
  currentDemoIndex = demoIndex;
  ui->customPlot->replot();
}


void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
  demoName = "Healthy Heartbeats";
  

  //
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
  //
  customPlot->addGraph(); // blue line
  customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
  customPlot->addGraph(); // red line
  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->yAxis->setRange(-1.2, 1.2);
  

  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  

  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(detect()));
  dataTimer.start(0);
}

void MainWindow::readSerial()
{

    QStringList buffer_split = serialBuffer.split(","); // armazena os dados em um buffer encontrando as virgulas dos dados

    if(buffer_split.length() < 3){ // garante que tenha mais de 3 dados

        serialData = arduino->readAll();
        serialBuffer = serialBuffer + QString::fromStdString(serialData.toStdString());


    }else{
        serialBuffer = "";
         qDebug() << buffer_split << "\n";
         parsed_data = buffer_split[1];
         ECG_p1 = buffer_split[0];
         ECG_p2 = buffer_split[1];
         ecg_value= parsed_data.toFloat();
         parsed_data = QString::number(ecg_value, 'g', 4);
         MainWindow::realtimeDataSlot(parsed_data);
         MainWindow::cont_picos(ECG_p1,ECG_p2);
    }
}

void MainWindow::cont_picos(QString Buffer_pts_0, QString Buffer_pts_1){



    var1 = Buffer_pts_0.toFloat();
    var2 = Buffer_pts_1.toFloat();


    // tabulação de dados
    if(picos==0 && PTMAX == 0){
       if(var2>=var1){
        PMAX1 = var2;
    }else{
        PMAX1 =var1;
        picos=picos;}}
    // tabulação de dados 2

    if(picos ==1 && PTMAX == 0){
    if(PMAX1 > var2){
          picos = picos+1;
          PMAX1 = PMAX1;
    }
    if(PMAX1 == var2){
              picos = picos;
              PMAX1 =PMAX1;
        }
    if(PMAX1 < var2){
              picos = picos;
              PMAX1= var2;
        }
    // tabulação de dado 3

    }if(picos >=2 && PTMAX == 0){
        if (PMAX1> var2){
           picos = picos;
           PMAX1 = PMAX1;}
        if(PMAX1 == var2){
            picos = picos +1;
            PMAX1 =PMAX1;
        }
        else{
            PMAX2 = var2;
            PMAX1 = 0;
            picos = picos + 1;

        }} if(PMAX2>= var2 ){
             PMAX2 = PMAX2;
             picos = picos + 1;
             PTMAX = PTMAX + 1;
            }else{
              PMAX2 = var2;
              picos = picos;
              PTMAX = 1;
    }if(PTMAX<=1){

        if(PMAX2>var2){
            PMAX2 =PMAX2;
            picos =0;
            PTMAX = 1;

        }if (PMAX2 == var2){
            PMAX2 = 0;
            PMAX1 = var2;
            picos = picos + 1;
            PTMAX = PTMAX +1;

        }if(PMAX2 < var2){
            picos = picos +1;
            PMAX2 = var2;
            PTMAX = PTMAX +1;
        }
    }




}


void MainWindow::realtimeDataSlot(QString plott)
{

    qDebug() << "plott" << plott;
    float numero = plott.toFloat();

   /* plott.toFloat(&ok); // calculando a quantidade de dados plotados
    if(ok != 0){
        control= control +1;
    }*/


  static QTime time(QTime::currentTime());

  double key = time.elapsed()/1000.0;



  ui->customPlot->graph(1)->addData(key,numero);
  ui->customPlot->graph(1)->rescaleValueAxis();


  ui->customPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->customPlot->replot();


  calc_bpm = (PTMAX/key);

    if(calc_bpm > 101){

          ritmo = "FC TAQUICARDIA";
      }if(calc_bpm< 59){

          ritmo = "FC BRADICARDIA";}

      if(calc_bpm > 60 || calc_bpm <100){

          ritmo = "FC NORMAL";
      }


    ui->statusBar->showMessage(
          QString("%1 Qtd de Batimentos || Tempo de exe : %2  ||\n RITMO :%3 || BPM/m: %4" )
          .arg(PTMAX)
           .arg((key))
                .arg((ritmo))
            .arg((calc_bpm)) );





 /* calc_bpm =(PTMAX/key);
  ui->statusBar->showMessage(
              QString("%8   BPM/m    ")
              .arg((calc_bpm)));*/

}
/*void MainWindow::detect(float calc, bool VorF){


    qDebug() << "BPM "<< calc;


    if(calc > 101){

        ritmo = "FC TAQUICARDIA";
    }if(calc < 59){

        ritmo = "FC BRADICARDIA";}

    if(calc > 60 || calc_bpm <100){

        ritmo = "FC NORMAL";
    }

    if(VorF){

       QMessageBox::information(this, "Healty Heartbeats", ritmo);
    }else{

        //
    }
}*/

MainWindow::~MainWindow()
{

  delete ui;

}
