#ifndef HANZIPANEL_H
#define HANZIPANEL_H

#include <QWidget>
class Keyboard;
class HanziPanel : public QWidget
{
    Q_OBJECT
public:
    explicit HanziPanel(Keyboard *keyboard, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent * event);
        virtual void mousePressEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent * event);
        virtual void mouseReleaseEvent(QMouseEvent *event);

    void clear();
signals:

public slots:

private:


     Keyboard * keyboard;
    int m_right_margin;
    int m_font_x_offset;
    int m_total_x_offset;
    int m_font_init_offset;
    int m_total_font_width;
    bool pressed;
    int pressBoxIndex;
   int pressX;
   int moveX;
   QVector<int> m_font_widthV;
   QVector<int> m_font_width_totalV;

};

#endif // HANZIPANEL_H
