#include "overviewtable.h"

#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QMouseEvent>

OverviewTable::OverviewTable(QWidget *parent) :
    QWidget(parent)
  , m_borderWidth(10)
  ,m_borderColor(QColor(209,209,209, 255))
  ,m_backColor(QColor(255,255,255,255))
  ,m_innerRadius(5)
  ,m_font(QFont("微软雅黑",20))
  ,m_fontColor(QColor("#545657"))
  ,m_underlineWidth(1)
  ,m_underlineColor(QColor(209,209,209, 255))
  ,m_markOffsetY(m_borderWidth)
  ,m_itemHeight(60)
  ,m_y_offset(0)
  ,pressed(false)
  ,m_total_height(0)
  ,m_checkedIndex(0)
  ,m_checkedColor(QColor(230,230,230, 110))
  ,m_margin(10)
  ,m_right_margin(80)
  ,m_fontScale(1.2)
{
}

void OverviewTable::paintEvent(QPaintEvent *event)
{
    y_offsetList.clear();
    heightList.clear();
    QPainter p(this);
    QPen pen;
    pen.setColor(m_borderColor);
    pen.setWidth(m_borderWidth);
    p.setPen(pen);

    int width = this->width();
    int height = this->height();
    int pen_offset = m_underlineWidth / 2;
    int pen_offset_right = 0;
    if (m_underlineWidth % 2 == 0)
    {
        pen_offset_right = m_underlineWidth / 2;
    }else{
        pen_offset_right = m_underlineWidth / 2 + 1;
    }



    if (m_borderWidth != 0)
    {
        p.fillRect(0,0, width, height, m_borderColor);
        //draw mark
        //        if (!m_mark.isNull())
        //        {
        //            p.drawPixmap(0,m_markOffsetY, m_mark);
        //        }
        pen.setColor(m_backColor);
        p.setPen(pen);
        QRect rect(m_borderWidth, m_borderWidth, width - 2 * m_borderWidth, height - 2 *m_borderWidth);
        QPainterPath path;
        path.addRoundedRect(rect, m_innerRadius, m_innerRadius);
        QPolygon polygon = path.toFillPolygon().toPolygon();
        QRegion region(polygon);
        p.setClipRegion(region);
        p.fillRect(0,0, width, height, m_backColor);


    }




    int size = m_itemList.size();
    if (size == 0){
        return;
    }
    int max_len_font = 0;
    QString max_len_title;
    for (int i = 0; i < size; ++i)
    {
        QString str = m_itemList[i].title;
        int len = str.size();
        if (max_len_font < len){
            max_len_font = len;
            max_len_title = str;
        }
    }

    p.setFont(m_font);
    p.setPen(pen);
    QFontMetrics fm = p.fontMetrics();
    int firstColumnWidth = fm.width(max_len_title) * m_fontScale;
    int height_fm = fm.height();
    int y_offset =  m_borderWidth;
    int font_y_offset = m_itemHeight / 2 + height_fm / 3;


    m_total_height  = 0;
    for (int i = 0; i < size; ++i)
    {
        QString &title = m_itemList[i].title;
        QImage &image = m_itemList[i].image;
        QString &content = m_itemList[i].content;
        int title_width = fm.width(title) + 20;
        //  int font_x_offset = (firstColumnWidth  - title_width)/ 2  + m_borderWidth ;
        int font_x_offset = firstColumnWidth - title_width + m_borderWidth;
        int last_offset = y_offset;
        pen.setColor(m_fontColor);
        p.setPen(pen);
        y_offsetList.append(y_offset + m_y_offset);
        if (image.isNull())
        {
            //qDebug()<<"drawText : " << font_x_offset << font_y_offset + y_offset << title;
            int itemHeight= m_itemHeight;
            int font_width = fm.width(content[0]) ;

            int secondColumnWidth = width - m_borderWidth * 2 - firstColumnWidth - m_underlineWidth - m_right_margin;
            int rowFontCount = secondColumnWidth / font_width;
            if (rowFontCount < content.size())
            {

                itemHeight = m_itemHeight * 2;
                int font_y_offset2 = itemHeight / 2 + height_fm / 3;
                QString first = content.mid(0, rowFontCount);

                QString second = content.mid(rowFontCount);

                p.drawText(30 + firstColumnWidth, y_offset + font_y_offset+ m_y_offset, first);
                  p.drawText(30 + firstColumnWidth, y_offset + font_y_offset2+ m_y_offset, second);
                  p.drawText(font_x_offset, y_offset + font_y_offset2 + m_y_offset, title);

            }else{
                  p.drawText(30 + firstColumnWidth, y_offset + font_y_offset+ m_y_offset, content);
          p.drawText(font_x_offset, y_offset + font_y_offset + m_y_offset, title);
            }


            if (m_checkedIndex == i){
                p.fillRect(0, y_offset + m_y_offset, width, itemHeight, m_checkedColor);
                p.drawPixmap(width-m_right_margin, y_offset + m_y_offset + ( itemHeight- m_editImage.size().height()) / 2, m_editImage);
                currentEditRect = QRect(width-m_right_margin, y_offset + m_y_offset + ( itemHeight- m_editImage.size().height()) / 2, m_editImage.width(), m_editImage.height());
            }
            y_offset += itemHeight;
            m_total_height += itemHeight + m_underlineWidth;
            heightList.append(itemHeight);

        }else{
            QSize size = image.size();
            int font_y_offset2 = size.height() / 2 + height_fm / 3 + m_margin ;
            p.drawText(font_x_offset, y_offset + font_y_offset2+ m_y_offset, title);
            int itemHeight =  size.height() +  m_margin * 2;
            if (m_checkedIndex == i){
                p.fillRect(0, y_offset + m_y_offset, width,itemHeight, m_checkedColor);
                p.drawPixmap(width-m_right_margin, y_offset + m_y_offset + (itemHeight - m_editImage.size().height()) / 2, m_editImage);
                currentEditRect = QRect(width-m_right_margin, y_offset + m_y_offset + ( itemHeight- m_editImage.size().height()) / 2, m_editImage.width(), m_editImage.height());

            }

            QRect rect(30 + firstColumnWidth,  y_offset + m_margin+ m_y_offset, size.width(), size.height());
            p.fillRect(rect, Qt::green);
            p.drawImage(30 + firstColumnWidth, y_offset + m_margin+ m_y_offset, image);
            y_offset += itemHeight ;
            // qDebug()<<"drawImage : " << size.height() << y_offset;
            m_total_height += itemHeight + m_underlineWidth;
            heightList.append(itemHeight);
        }
        pen.setColor(m_underlineColor);
        pen.setWidth(m_underlineWidth);
        p.setPen(pen);
        p.drawLine(m_borderWidth + pen_offset, y_offset + pen_offset+ m_y_offset, width - m_borderWidth - pen_offset_right, y_offset+ pen_offset+ m_y_offset);
        p.drawLine(firstColumnWidth + pen_offset , last_offset+ m_y_offset, firstColumnWidth + pen_offset, y_offset -pen_offset_right+ m_y_offset);
        y_offset +=  m_underlineWidth;


    }




    QRegion region(0,0, width, height);
    p.setClipRegion(region);
//    if ((m_markOffsetY) < m_borderWidth)
//    {
//        qDebug()<<" < 0 " << m_markOffsetY << m_y_offset;
//        for(int i =0; i < y_offsetList.size(); i++)
//        {
//            QImage &image = m_itemList[i].image;
//            int y_off = y_offsetList[i];
//            if (y_off > 0){
//                if (image.isNull()){
//                    m_markOffsetY = y_off;
//                }else{
//                    m_markOffsetY = y_off + m_margin + ( image.size().height() - m_itemHeight) / 2;
//                }
//                m_checkedIndex = i;
//                break;

//            }
//        }
//    }
//    else if (m_markOffsetY > (this->height() - m_borderWidth * 2))
//    {
//        for (int i = y_offsetList.size() - 1; i>=0; --i)
//        {
//            QImage &image = m_itemList[i].image;
//            int y_off = y_offsetList[i];

//        }
//    }
    if (!m_mark.isNull())
    {
        qDebug()<<"draw mark : " << m_markOffsetY;
        p.drawPixmap(0,m_markOffsetY, m_mark);
    }


}

void OverviewTable::addItemStr( QString &title, QString &str)
{
    Item item  = {title, str};

    m_itemList.append(item);
}

void OverviewTable::addItemImage(QString &title, QImage &img)
{
    Item item = {title, "", img};
    m_itemList.append(item);
}

void OverviewTable::clear()
{
    m_itemList.clear();
}

void OverviewTable::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed  = true;
        pressY = event->pos().y();
        // pressX = event->pos().x();
        moveY = pressY;
        //   this->repaint();
    }
}

void OverviewTable::mouseMoveEvent(QMouseEvent *event)
{
    if (pressed)
    {
        qDebug()<<"1" << m_y_offset ;
        if (m_total_height < this->height()){
            return;
        }

        if ((m_y_offset <=0) && (m_y_offset >= (this->height() - m_borderWidth * 2 - m_total_height)))
        {
            int y = event->pos().y();
            qDebug()<<" y: " << y << " moveY : " << moveY;
            m_y_offset += y - moveY;
            bool changed = true;

            if (m_y_offset > 0){
                m_y_offset = 0;
                changed = false;
            }
            else if (m_y_offset < (this->height() - m_total_height - m_borderWidth * 2)){
                m_y_offset = this->height() - m_total_height - m_borderWidth * 2;
                changed = false;
            }
            if (changed){
                m_markOffsetY += y - moveY;
                qDebug()<<"changed : " << m_markOffsetY;
            }
            moveY = y;
            this->repaint();

        }
    }

}

void OverviewTable::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pressed)
        {
            int y = event->pos().y();
            if (abs(y - pressY) > 5){
                return;
            }

            QPoint point = event->pos();
            if (currentEditRect.contains(point))
            {
                qDebug() << "emit editClick " << m_checkedIndex;
                emit editClick(m_checkedIndex);
                return;
            }

            for (int i = 0; i< y_offsetList.size(); ++i)
            {
                int y_offset = y_offsetList[i];
                if ((y > y_offset) && (y < (y_offset + heightList[i]))){

                    QImage &image = m_itemList[i].image;
                    if (image.isNull()){
                        m_markOffsetY = y_offset;
                    }else{
                        m_markOffsetY = y_offset + m_margin + ( image.size().height() - m_itemHeight) / 2;
                    }
                    m_checkedIndex = i;
                    break;
                }

            }
            this->repaint();


        }
    }

}
