#include "digitPanel.h"
#include <QPainter>
#include <QPen>
#include <QFontMetrics>
#include <QDebug>
#include <QLineEdit>

DigitPanel::DigitPanel(QWidget *parent) :
    QWidget(parent)
  ,m_borderColor(QColor(255,255,255,255))
  ,m_backColor(QColor("#666666"))
  ,m_fontColor(Qt::white)
  ,m_inputLineEdit(nullptr)
  ,m_borderWidth(1)
  ,pressed(false)
  ,pressRectIndex(-1)
{
    //    this->resize(m_itemWidth * 3, m_itemHeight * 4);
    digitList << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "清空"  << "0" << "退格";

}

void DigitPanel::paintEvent(QPaintEvent *event)
{
    buttonRectList.clear();

    QPainter p(this);
    QPen pen;
    pen.setColor(this->m_borderColor);
    pen.setWidth(m_borderWidth);
    p.setPen(pen);
    int width = this->width();
    int height = this->height();
    int   pen_offset = m_borderWidth / 2;
    int  pen_offset_right = 0;
    if (m_borderWidth % 2 == 0)
    {
        pen_offset_right = m_borderWidth / 2;
    }else{
        pen_offset_right = m_borderWidth / 2 + 1;
    }

    m_itemWidth = (width - m_borderWidth * 4) / 3;
    m_itemHeight = (height - m_borderWidth * 5 ) / 4;
    width = (m_itemWidth + m_borderWidth) * 3 ;
    height = (m_itemHeight + m_borderWidth) * 4 + m_borderWidth - pen_offset_right;


    p.drawLine(pen_offset,0, pen_offset, height);
    p.drawLine(m_itemWidth + m_borderWidth + pen_offset, 0, m_itemWidth + m_borderWidth + pen_offset, height);
    p.drawLine(m_itemWidth * 2 + m_borderWidth * 2 + pen_offset, 0, m_itemWidth * 2 + m_borderWidth * 2 + pen_offset, height);
    p.drawLine(m_itemWidth * 3 + m_borderWidth * 3 + pen_offset, 0, m_itemWidth * 3 + m_borderWidth * 3 + pen_offset, height);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            p.drawLine((m_borderWidth + m_itemWidth) * j + m_borderWidth + pen_offset, (m_borderWidth + m_itemHeight) * i + pen_offset, \
                       (m_borderWidth + m_itemWidth) * (j+1) - pen_offset_right, (m_borderWidth + m_itemHeight) * i  + pen_offset);
            if (i != 4){

                QRect rect((m_borderWidth + m_itemWidth) * j + m_borderWidth, (m_borderWidth + m_itemHeight) * i + m_borderWidth, m_itemWidth, m_itemHeight);
                p.fillRect(rect, backColor());
                ButtonRectStr button;
                button.rect = rect;
                button.str = digitList.at(i* 3 + j);
                buttonRectList.append(button);

            }
        }
    }


    if (pressed)
    {
        if(pressRectIndex != -1){
            ButtonRectStr &button = buttonRectList[pressRectIndex];
            p.fillRect(button.rect, m_clickBackColor);
            p.drawPixmap(button.rect, m_clickImage);
        }

    }






    QFont font;
    int fontSize = m_itemWidth * 0.2;
    font.setPointSize(fontSize);
    font.setFamily("微软雅黑");
    pen.setColor(m_fontColor);
    p.setFont(font);
    p.setPen(pen);

    QFontMetrics fm = p.fontMetrics();
    int width_1 = fm.width("1");

    int width_back = fm.width("退格");

    int height_fm = fm.height();

    int font_x_offset = (m_itemWidth - width_1)/ 2  + m_borderWidth ;
    int font_y_offset = m_itemHeight / 2 + height_fm / 3    + m_borderWidth;
    p.drawText(font_x_offset , font_y_offset , QString("1"));
    p.drawText(m_itemWidth + m_borderWidth + font_x_offset, font_y_offset , QString("2"));
    p.drawText((m_itemWidth + m_borderWidth) * 2 + font_x_offset, font_y_offset,QString("3"));
    p.drawText(font_x_offset, m_itemHeight + m_borderWidth + font_y_offset, QString("4"));
    p.drawText(m_itemWidth + m_borderWidth + font_x_offset, m_itemHeight + m_borderWidth + font_y_offset, QString("5"));
    p.drawText((m_itemWidth + m_borderWidth) * 2 + font_x_offset, m_itemHeight + m_borderWidth + font_y_offset, QString("6"));
    p.drawText(font_x_offset, (m_itemHeight + m_borderWidth) * 2 + font_y_offset, QString("7"));
    p.drawText(m_itemWidth + m_borderWidth + font_x_offset, (m_itemHeight + m_borderWidth) * 2 + font_y_offset, QString("8"));
    p.drawText((m_itemWidth + m_borderWidth) * 2 + font_x_offset, (m_itemHeight + m_borderWidth) * 2 + font_y_offset, QString("9"));
    p.drawText(m_itemWidth + m_borderWidth + font_x_offset, (m_itemHeight + m_borderWidth) * 3 + font_y_offset, QString("0"));

    font_x_offset = (m_itemWidth - width_back) / 2 + m_borderWidth;
    font_y_offset = m_itemHeight / 2 + height_fm / 3  + m_borderWidth;
    p.drawText(font_x_offset, (m_itemHeight + m_borderWidth) * 3 + font_y_offset, QString("清空"));
    p.drawText((m_itemWidth + m_borderWidth) * 2 + font_x_offset, (m_itemHeight + m_borderWidth) * 3 + font_y_offset, QString("退格"));

}

void DigitPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed  = true;
        pressPoint = event->pos();
        pressRectIndex = -1;
        for(int i = 0; i < buttonRectList.size(); i++)
        {
            ButtonRectStr &button = buttonRectList[i];
            if (button.rect.contains(pressPoint))
            {
                pressRectIndex = i ;
              //  qDebug()<<" press : " << pressRectIndex;
                this->repaint();
                break;
            }
        }
    }
}

void DigitPanel::mouseMoveEvent(QMouseEvent *event)
{

    if (pressed)
    {
        int currentIndex = -1;
         pressPoint = event->pos();
        for(int i = 0; i < buttonRectList.size(); i++)
        {
            ButtonRectStr &button = buttonRectList[i];
            if (button.rect.contains(pressPoint))
            {
                currentIndex = i ;
            }
        }
        if ((pressRectIndex != -1) && (pressRectIndex != currentIndex))
        {
            pressed = false;
            this->repaint();
        }
    }


}


void DigitPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pressed)
        {
            if (pressRectIndex != -1){
                if (m_inputLineEdit == NULL){
                    return;
                }
                ButtonRectStr &button = buttonRectList[pressRectIndex];
                QString str = button.str;
                int index  = digitList.indexOf(str);
               // qDebug()<<"release  " << str  << "  index : " << index;
                if ((index > -1) && (index < 9) || (index == 10)){

                        QString text = m_inputLineEdit->text();
                        m_inputLineEdit->setText(text+str);

                }else if (index == 9)
                {
                    m_inputLineEdit->clear();
                }
                else if (index == 11)
                {
                    QString text = m_inputLineEdit->text();
                    if (text.size() > 0){
                        text = text.mid(0, text.size() - 1);
                        m_inputLineEdit->setText(text);
                    }
                }
                pressed = false;
                this->repaint();
            }
        }
    }
}
