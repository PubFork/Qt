#include <Lib-1/Config.h>
#include <Lib-2/Form.h>

#include <QDebug>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton *button = new QPushButton("Access Global Variable");
    button->show();

    QObject::connect(button, &QPushButton::clicked, [] {
        qDebug() << &Config::instance();
        qDebug() << ++Config::count;
        qDebug() << ++g;
    });

    Form form;
    form.show();

    return app.exec();
}
