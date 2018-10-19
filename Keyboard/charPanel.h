#ifndef CHARPANEL_H
#define CHARPANEL_H

#include <QWidget>
class Keyboard;




class CharPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CharPanel(Keyboard *keyboar, QWidget * parent = nullptr);
    void paintEvent(QPaintEvent *event);

    int getWidth(){
        return m_width;
    }
    void clear(){
       m_font_y_offset = 0;
    }

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent *event);


signals:

public slots:

private:
    Keyboard * keyboard;
    QStringList m_numberList;
    QStringList m_charList1;
    QStringList m_charList2;
    QStringList m_charList3;

    QStringList m_charList1_lower;
    QStringList m_charList2_lower;
    QStringList m_charList3_lower;

    QStringList m_buttonList;

    int m_itemWidth;
    int m_itemHeight;


    bool pressed;
    int pressBoxIndex;
    int m_borderWidth;
    int m_width;

    bool shiftPressed;

    int m_font_y_offset;
    int pressY;
    int pressX;
    QPoint pressPoint;
    int moveY;
    int m_total_font_height;

    double m_fontScale;

     QVector<QStringList> vHanziStr;
  QVector<QVector<int>> vHanziWidth;

    bool oneWordModel;  // true 字模式 ， false 词模式

    int  m_x_offset;

    struct ButtonRectStr{
        QRect rect;
        QString str;
    };

    QList<ButtonRectStr> buttonRectList;
    int pressRectIndex;

    QList<int> leftBlockIndexList;
    QList<int> rightBlockIndexList;

    QString leftBlockStr;
    QString rightBlockStr;
    QString rightFirstControlStr;
    QString rightSecondControlStr;

    double m_ensureScale;

};

#endif // CHARPANEL_H
