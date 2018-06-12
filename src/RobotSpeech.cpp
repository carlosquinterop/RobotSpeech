#include "include/RobotSpeech.h"

RobotSpeech::RobotSpeech()
{
    QDesktopWidget dw;
    int x_window=dw.width()*0.4;
    int y_window=dw.height()*0.6;  
  
    mainLayout = new QGridLayout();
    buttonsLayout = new QGridLayout();    
    
    signalMapper = new QSignalMapper();
        
    buttonTexts[0] = "Hola";
    buttonTexts[1] = "Adiós";
    buttonTexts[2] = "Sí";
    buttonTexts[3] = "No";
    buttonTexts[4] = "No sé";
    buttonTexts[5] = "Bienvenidos";
    buttonTexts[6] = "Un placer conocerlos";
    buttonTexts[7] = "No oigo";
    buttonTexts[8] = "¿Cómo están?";
    buttonTexts[9] = "Nos vemos en una \n próxima ocasión";
    buttonTexts[10] = "Soy un robot";
    buttonTexts[11] = "Hagamos silencio \n por favor";
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
    {
	shortcutButtons[i] = new QPushButton(buttonTexts[i]);
	signalMapper->setMapping(shortcutButtons[i], buttonTexts[i]);
    }
    playButton = new QPushButton("Reproducir");
    
    appName = new QLabel("Robot Speech");
    
    textEntry = new QPlainTextEdit();
    
    QWidget *window = new QWidget();
    
    speakProcess = new QProcess();
    
    mainLayout->addWidget(appName, 0, 0);
    mainLayout->addLayout(buttonsLayout, 1, 0);
    mainLayout->addWidget(textEntry, 2, 0);
    mainLayout->addWidget(playButton, 3, 0);
    
    int row = 0, col = 0;
    for (int i = 0;i <4;i++)
    {
	for (int j = 0;j < 3;j++)
	    buttonsLayout->addWidget(shortcutButtons[3*i +j], i, j);	    
    }
    
    playButton->setFixedSize(QSize(0.96*x_window, 0.1*y_window));
    
    appName->setAlignment(Qt::AlignCenter);
    QFont f("Arial",16);
    QFontMetrics fm(f);
    appName->setFont(f);
    
    window->setLayout(mainLayout);
    setCentralWidget(window);
    window->setFixedSize(x_window,y_window);
    setWindowTitle("Robot Speech");
    
    speechProcessName = "espeak";
    
    for (int i = 0;i < NUMBER_OF_BUTTONS;i++)
	connect(shortcutButtons[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(playStandardMessages(QString)));
    connect(speakProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processEnded(int, QProcess::ExitStatus)));
    connect(playButton, SIGNAL(clicked()), this, SLOT(playButtonSlot()));
}

RobotSpeech::~RobotSpeech()
{
  
}

void RobotSpeech::playStandardMessages(QString message)
{
    QStringList arguments;
    arguments << "-a" << "200" << "-s" << "190" << "-ves-la";
    arguments << message;
    speakProcess->start(speechProcessName, arguments);
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(false);
    
}

void RobotSpeech::processEnded(int exitCode, QProcess::ExitStatus existStatus)
{
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(true);
    textEntry->setPlainText("");
}

void RobotSpeech::playButtonSlot()
{
    QStringList arguments;
    arguments << "-a" << "200" << "-s" << "190" << "-ves-la";
    arguments << textEntry->toPlainText();
    speakProcess->start(speechProcessName, arguments);
    
    for(int i = 0;i < NUMBER_OF_BUTTONS;i++)
	shortcutButtons[i]->setEnabled(false);
}