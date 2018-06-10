#include <QtWidgets/QApplication>
#include "include/RobotSpeech.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    RobotSpeech robotspeech;
    robotspeech.show();
    return app.exec();
}
