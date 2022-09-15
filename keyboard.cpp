#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
    setWindowFlags(Qt::FramelessWindowHint);

}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::init()
{
    setMinimumSize(QSize(600,300));

    QWidget *parentW = parentWidget();
    if(parentW)
    {
        int parentWidth = parentW->width();
        int parentHeight = parentW->height();
//        int height = this->height();

        int positionX = 0;
        int positionY = parentHeight;

        setGeometry(positionX, positionY, parentWidth, parentHeight/3);
    }
}

void Keyboard::popUp(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x()+x, this->y()+y, this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void Keyboard::popIn(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x()+x, this->y()+y, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void Keyboard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  //抗锯齿
    painter.setBrush(Qt::black);                   //设置画刷

    /*绘制背景*/
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()) , 5, 5);
    painter.drawPath(path.simplified());
}

