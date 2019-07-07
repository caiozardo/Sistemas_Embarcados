
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileInfo>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QMainWindow>
#include <QFileDialog>
#include <QTimer>
#include "../../qcustomplot.h" //
namespace Ui {
class MainWindow;
}

//config do serial
class QSerialPort;

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void setupDemo(int demoIndex);
  void setupRealtimeDataDemo(QCustomPlot *customPlot);
  void detect();

  
  
public slots:

private slots:
  void realtimeDataSlot(QString);
  void readSerial();
  void cont_picos(QString, QString);


  
private:


  Ui::MainWindow *ui;

   //config plot false
    QTimer arqTimer;
    QFile file;
    QString nomearquivo = "DADOS.txt";
    QString fakeBuffer;
    QList<QString> LineList;
    int ct = 0;
    QString TextReaded;
    float flutuante;
    float calc_bpm;
    char arq[775];

  //config do serial
  QSerialPort *arduino;
  QString arduino_port_name;
  bool arduino_is_available;
  static const quint16 arduino_nano_vendor_id = 6790;
  static const quint16 arduino_nano_product_id = 29987;
  static const quint16 arduino_uno_vendor_id = 9025;
  static const quint16 arduino_uno_product_id = 67;
  int contt = 0;
  bool VorF = false;
  QByteArray serialData;
  float calc;
  QString ritmo;
  QString serialBuffer;
  QString Buffer_pts_0;
  QString Buffer_pts_1;
  QString ECG_p1;
  QString ECG_p2;
  int picos=0;
  int picos_1=0;
  int picos_2;
  int picos_3;
  float var1;
   float var2;
  float BPM;
  float PMAX1;
  float PMAX2;
  int PTMAX=0;
  QString parsed_data;
  float ecg_value;
  int control = 0;
  float teste;
  double exerc_t = 0;

  //config plot
  QString demoName;
  QString plott;
  QTimer dataTimer;
  bool ok;
  QCPItemTracer *itemDemoPhaseTracer;
  int currentDemoIndex;
};

#endif // MAINWINDOW_H
