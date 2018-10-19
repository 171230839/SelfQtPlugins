#include "hanziPanel.h"
#include <QPainter>
#include "keyboard.h"
#include "pinyinInputMethod.h"
#include <QDebug>
#include <QMouseEvent>
#include <QTextEdit>

HanziPanel::HanziPanel(Keyboard *keyboard, QWidget* parent)
    :QWidget(parent)
    ,keyboard(keyboard)
    ,m_font_init_offset(10)
    ,m_font_x_offset(0)
    ,m_total_x_offset(0)
    ,m_total_font_width(0)
    ,m_right_margin(60)
{

}

void HanziPanel::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
p.setRenderHint(QPainter::Antialiasing, true);
    int width = keyboard->getWidth();
    //m_right_margin = this->width() - width;
    int height = this->height();
    p.fillRect(0,0, width, height, keyboard->hanziBackColor());
    //   QPixmap map("E:/Qt/client/BPA3/TestKeyboard/rc/apple.png");
    //p.drawPixmap(width - m_right_margin, 0 , m_right_margin, height,map);
    QVector<QStringList> &hanziModel = g_CPinyinInputMethod::getInstance()->HanziModel;
    int size = hanziModel.size();
    if (size == 0)
    {
        return;
    }

    p.setFont(keyboard->hanziFont());

    QPen pen;
    pen.setColor(keyboard->hanziFontColor());
    p.setPen(pen);
    QFontMetrics fm = p.fontMetrics();

    int height_fm = fm.height();

    int font_y_offset = this->height() /2 + height_fm / 3;

    if (keyboard->getKeyboardState() == KEYBOARD_STATE::DEFAULT){
        QSize size = keyboard->omitIconSize();
        QPixmap map = keyboard->omitIcon().pixmap(size);
        int top_margin = (this->height() - size.height()) / 2;
        m_right_margin = size.width() + 10;
        p.drawPixmap(width - m_right_margin+ 5, top_margin, size.width(), size.height(), map);
        p.setClipRect(0,0, width - m_right_margin , height);
    }else{
        QString text = keyboard->getLabel()->text();
        if (text.size() > 1){
            p.drawText(m_font_init_offset, font_y_offset, text.mid(0,1));
        }
        return;
    }

    m_total_x_offset = 0;
    m_total_font_width = 0;
    m_font_widthV.clear();
    m_font_width_totalV.clear();
    for (int i = size - 1; i >= 0; --i)
    {
        QStringList &hanziList = hanziModel[i];

        if (hanziList.size() != 0)
        {
            int font_width = fm.width(hanziList[0]);

            if (i == size - 1){
                for(int j = 0; j < hanziList.size(); ++j)
                {
                    p.drawText(m_font_init_offset + m_font_x_offset + font_width * j * 1.2  , font_y_offset, hanziList[j]);
                }
                int total = m_font_init_offset + m_font_x_offset+ font_width * hanziList.size() * 1.2;
                m_total_x_offset += total;
                m_font_width_totalV.append(m_total_x_offset);
            }else{
                for(int j = 0; j < hanziList.size(); ++j)
                {
                    p.drawText(m_total_x_offset + font_width * j * 1.2, font_y_offset, hanziList[j]);
                }
                int total = font_width * hanziList.size() * 1.2;
                m_total_x_offset += total;
                m_font_width_totalV.append(m_total_x_offset);
            }
            m_total_font_width += font_width *hanziList.size() * 1.2;
            m_font_widthV.append(font_width * 1.2);

        }

    }

}

void HanziPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed  = true;
        pressX = event->pos().x();
        moveX = pressX;
    }
}

void HanziPanel::mouseMoveEvent(QMouseEvent *event)
{

    if (pressed){

        int x = event->pos().x();



        if ((m_total_font_width + m_font_init_offset) < (this->width() - m_right_margin))
        {
            return;
        }
        if ((m_font_x_offset <=0) && (m_font_x_offset >= ((this->width() - m_right_margin) - (m_total_font_width + m_font_init_offset))))
        {
            m_font_x_offset += x - moveX;
            moveX = x;

            if (m_font_x_offset > 0){
                m_font_x_offset = 0;
            }
            else if (m_font_x_offset < ((this->width() - m_right_margin) - (m_total_font_width + m_font_init_offset)))
            {
                m_font_x_offset = (this->width() - m_right_margin) - (m_total_font_width + m_font_init_offset);
            }

            this->repaint();
        }

    }

}

void HanziPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pressed){
            pressed = false;

            int x = event->pos().x();
             if (abs(x - pressX) > 5){
                return;
            }
            //  x = x - m_font_x_offset;
            int size = m_font_width_totalV.size();
            QVector<QStringList> &hanziModel = g_CPinyinInputMethod::getInstance()->HanziModel;
            if (hanziModel.size() == 0){
                return;
            }
           if ((keyboard->getWidth() - x) < m_right_margin){
                this->repaint();
                keyboard->changeToState(KEYBOARD_STATE::SHOWHANZI);
                return;
            }

            for (int i = 0; i < size; ++i)
            {
                 if (x < m_font_width_totalV[i])
                {
                    int item_width = m_font_widthV[i];
                    //  int index = x / item_width;
                    int index = 0;
                    if (i == 0){
                        index = (x - m_font_x_offset - m_font_init_offset) / item_width;
                    }else{
                        index = (x - m_font_width_totalV[i - 1]) / item_width;
                    }
                    if (index >= hanziModel[size -i -1].size()){
                        return;
                    }
                    QString text = hanziModel[size - i - 1].at(index);
                    keyboard->addText(text);
                    keyboard->clear();
                    this->repaint();
                    break;
                }
            }
        }
    }
}

void HanziPanel::clear()
{
    m_font_x_offset = 0;
}

