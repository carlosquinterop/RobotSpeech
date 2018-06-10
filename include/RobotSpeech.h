#ifndef RobotSpeech_H
#define RobotSpeech_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QString>
#include <QPushButton>
#include <QObject>
#include <QSignalMapper>
#include <QGridLayout>
#include <QProcess>
#include <QLabel>
#include <QPlainTextEdit>
#include <QDesktopWidget>
#include <iostream>
#include <QStringList>

#define NUMBER_OF_BUTTONS 12

using namespace std;

class RobotSpeech : public QMainWindow
{
    Q_OBJECT

public:
    RobotSpeech();
    virtual ~RobotSpeech();
private:
    QString buttonTexts[NUMBER_OF_BUTTONS], speechProcessName;
    QSignalMapper *signalMapper;
    QPushButton *shortcutButtons[NUMBER_OF_BUTTONS], *playButton;
    QGridLayout *mainLayout, *buttonsLayout, *textLayout;
    QProcess *speakProcess;
    QLabel *appName;
    QPlainTextEdit *textEntry;
    
private slots:
  void playStandardMessages(QString message);
  void processEnded(int exitCode, QProcess::ExitStatus existStatus);
  void playButtonSlot();
};

#endif // RobotSpeech_H
