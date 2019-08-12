#include "CalloutChartWidget.h"
#include "Widget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QWidget *w = new Widget(nullptr);
    w->show();

    return a.exec();
}
