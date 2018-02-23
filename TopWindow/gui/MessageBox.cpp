#include "ui_MessageBox.h"
#include "MessageBox.h"
#include "TopWindow.h"

MessageBox::MessageBox(const QString &message, bool cancelButtonVisible, QWidget *parent)
    : QWidget(parent), ui(new Ui::MessageBox) {
    ui->setupUi(this);
    ui->messageLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->messageLabel->setText(message);
    ui->cancelButton->setVisible(cancelButtonVisible);

    setAttribute(Qt::WA_StyledBackground);
    setStyleSheet(".MessageBox { background: white; }");

    // 点击取消按钮关闭窗口
    connect(ui->cancelButton, &QPushButton::clicked, [this] {
        TopWindow::findWindow(this)->close();
    });
}

MessageBox::~MessageBox() {
    delete ui;
}

void MessageBox::message(const QString &msg, int width, int height,
                         const QMargins &windowPaddings, const QMargins &borderImageBorders,
                         const QString &borderImagePath,
                         bool borderImageHorizontalStretch, bool borderImageVerticalStretch) {
    // 使用自定义窗口
    MessageBox *box = new MessageBox(msg, false);
    TopWindow *window = new TopWindow(box, windowPaddings, borderImageBorders, borderImagePath,
                                      borderImageHorizontalStretch, borderImageVerticalStretch);
    MessageBox::setWindowForMessageBox(window, width, height);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();

    // 点击确定按钮关闭窗口
    connect(box->ui->okButton, &QPushButton::clicked, [=] {
        window->close();
        window->deleteLater();
    });
}

bool MessageBox::confirm(const QString &msg, int width, int height,
                         const QMargins &windowPaddings, const QMargins &borderImageBorders,
                         const QString &borderImagePath,
                         bool borderImageHorizontalStretch, bool borderImageVerticalStretch) {
    // 使用自定义窗口
    MessageBox *box = new MessageBox(msg, true);
    TopWindow window(box, windowPaddings, borderImageBorders, borderImagePath,
                     borderImageHorizontalStretch, borderImageVerticalStretch);
    MessageBox::setWindowForMessageBox(&window, width, height);

    // 确认结果
    bool result = false;

    // 点击确定按钮
    connect(box->ui->okButton, &QPushButton::clicked, [&] {
        result = true;
        window.close();
    });

    window.showModal();
    return result;
}

void MessageBox::setWindowForMessageBox(TopWindow *window, int width, int height) {
    window->setTitleBarVisible(false);
    window->setResizable(false);
    window->setWindowFlags(Qt::Dialog | Qt::Popup | Qt::FramelessWindowHint);
    window->setWindowModality(Qt::ApplicationModal);
    window->resize(width, height);
}


