#ifndef DIGITPANEL_H
#define DIGITPANEL_H

#include <QtUiPlugin/QDesignerExportWidget>
#include <QWidget>
#include <QMouseEvent>
class QLineEdit;
class  QDESIGNER_WIDGET_EXPORT  DigitPanel : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor )
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor fontColor READ fontColor WRITE setFontColor )
    Q_PROPERTY(QColor backColor READ backColor WRITE setBackColor)
    Q_PROPERTY(QColor clickBackColor READ clickBackColor WRITE setClickBackColor)
    Q_PROPERTY(QPixmap clickImage READ clickImage WRITE setClickImage)
public:
    DigitPanel(QWidget *parent = 0);

    void paintEvent(QPaintEvent *event);
    inline QColor borderColor(){
        return this->m_borderColor;
    }
    inline void setBorderColor(QColor &color){
        this->m_borderColor = color;
    }

    inline QColor fontColor(){
        return this->m_fontColor;
    }
    inline void setFontColor(QColor &color){
        this->m_fontColor = color;
    }

    inline QColor backColor(){
        return this->m_backColor;
    }
    inline void setBackColor(QColor &color){
        this->m_backColor = color;
    }

    inline void setInputLineEdit(QLineEdit * widget){
        this->m_inputLineEdit = widget;
    }
    inline int borderWidth(){
        return this->m_borderWidth;
    }
    inline void setBorderWidth(int width){
        m_borderWidth = width;
    }

    inline QColor clickBackColor(){
        return m_clickBackColor;
    }
    inline void setClickBackColor(QColor &color){
        m_clickBackColor = color;
    }
    inline QPixmap clickImage(){
        return m_clickImage;
    }

    inline void setClickImage(QPixmap &pixmap){
        m_clickImage = pixmap;
    }

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QColor m_borderColor;
    QColor m_fontColor;
    QColor m_backColor;
    QLineEdit * m_inputLineEdit;
    int m_itemWidth;
    int m_itemHeight;
    int m_borderWidth;
    bool pressed;
    QPixmap m_clickImage;

    QStringList digitList;
    QPoint pressPoint;
    QColor m_clickBackColor;

    struct ButtonRectStr{
        QRect rect;
        QString str;
    };

    QList<ButtonRectStr> buttonRectList;

    int pressRectIndex;

};

#endif
