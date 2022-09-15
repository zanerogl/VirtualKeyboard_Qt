#ifndef KEYBOARD
#define KEYBOARD

#include <QWidget>
#include <QPainter>
#include "keys.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

    /**
     * @brief init  初始化
     */
    void init();

    /**
     * @brief popUp popIn   弹出/探入
     * @param x             x方向移动距离
     * @param y             y方向移动距离
     * @param msecs         动画间隔
     */
    void popUp(int x = 0, int y = 100, int msecs = 200);
    void popIn(int x = 0, int y = 100, int msecs = 200);

protected:
    void paintEvent(QPaintEvent *event) override;


private:
    Ui::Widget *ui;
};
#endif // KEYBOARD
