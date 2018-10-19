#ifndef OVERVIEWTABLE_H
#define OVERVIEWTABLE_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>



class  QDESIGNER_WIDGET_EXPORT  OverviewTable : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor backColor READ backColor WRITE setBackColor )
    Q_PROPERTY(QColor fontColor READ fontColor WRITE setFontColor )
    Q_PROPERTY(QFont font READ font WRITE setFont )
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor)
    Q_PROPERTY(QColor underlineColor READ underlineColor WRITE setUnderlineColor)
    Q_PROPERTY(int underlineWidth READ underlineWidth WRITE setUnderlineWidth)
    Q_PROPERTY(QPixmap mark READ mark WRITE setMark)
    Q_PROPERTY(int innerRadius READ innerRadius WRITE setInnerRadius)
    Q_PROPERTY(int itemHeight READ itemHeight WRITE setItemHeight )
    Q_PROPERTY(QColor checkedColor READ checkedColor WRITE setCheckedColor)
    Q_PROPERTY(QPixmap editImage READ editImage WRITE setEditImage )
public:
    OverviewTable(QWidget *parent = 0);
    void paintEvent(QPaintEvent * event);


    QColor backColor(){
        return m_backColor;
    }
    void setBackColor(QColor &color){
        m_backColor = color;
    }

    QColor fontColor(){
        return m_fontColor;
    }
    void setFontColor(QColor &color){
        m_fontColor = color;
    }

    QFont font(){
        return m_font;
    }
    void setFont(QFont &font){
        m_font = font;
    }

    int borderWidth(){
        return m_borderWidth;
    }

    void setBorderWidth(int width){
        m_borderWidth = width;
    }

    QColor borderColor(){
        return m_borderColor;
    }

    void setBorderColor(QColor &color){
        m_borderColor = color;
    }


    QColor underlineColor(){
        return m_underlineColor;
    }

    void setUnderlineColor(QColor &color){
        m_underlineColor = color;
    }

    int underlineWidth(){
        return m_underlineWidth;
    }
    void setUnderlineWidth(int width){
        m_underlineWidth  = width;
    }



    void addItemStr(QString &, QString &str);
    void addItemImage( QString &,QImage &img);

    int innerRadius(){
        return m_innerRadius;
    }
    void setInnerRadius(int radius){
        m_innerRadius = radius;
    }
    QPixmap mark(){
        return m_mark;
    }
    void setMark(QPixmap &map){
        m_mark = map;
        m_itemHeight = map.size().height();
    }
    int itemHeight(){
        return m_itemHeight;
    }

    void setItemHeight(int h){
        m_itemHeight = h;
    }
    QColor checkedColor(){
        return m_checkedColor;
    }
    void setCheckedColor(QColor &color){
        m_checkedColor = color;
    }

    QPixmap editImage(){
        return m_editImage;
    }
    void setEditImage(QPixmap &map){
        m_editImage = map;
    }

        void clear();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
signals:
    void editClick(int index);

private:
    QColor m_backColor;
    QColor m_fontColor;
    QFont m_font;
    int m_borderWidth;
    QColor m_borderColor;
    QColor m_underlineColor;
    int m_underlineWidth;
    QColor m_markColor;
    int m_innerRadius;
    QPixmap m_editImage;
    struct Item{
        QString title;
        QString content;
        QImage image;
    };
    QList<Item> m_itemList;
    QPixmap m_mark;

    int m_markOffsetY;
    int m_itemHeight;

    int m_y_offset;
    int m_total_height;

    bool pressed;
    int pressY;
    int moveY;

    int m_margin;
    int m_right_margin;

    QList<int> y_offsetList;
    QList<int> heightList;
    int m_checkedIndex;

    QColor m_checkedColor;

   double m_fontScale;

   QRect currentEditRect;
};

#endif
