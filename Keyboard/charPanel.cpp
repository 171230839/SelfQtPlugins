#include "charPanel.h"
#include "keyboard.h"
#include <QPainter>
#include <QMouseEvent>
#include <QTextEdit>
#include <QDebug>
#include "pinyinInputMethod.h"

CharPanel::CharPanel(Keyboard *keyboard, QWidget *parent )
    :QWidget(parent)
    ,keyboard(keyboard)
    ,shiftPressed(true)
    ,pressed(false)
    ,m_font_y_offset(0)
    ,m_total_font_height(0)
    ,m_fontScale(1.5)
    ,oneWordModel(false)
    ,pressPoint(QPoint(0,0))
    ,leftBlockStr("Shift")
    ,rightBlockStr("确定")
    ,rightFirstControlStr("清空")
    ,rightSecondControlStr("退格")
    ,pressRectIndex(-1)
    ,m_ensureScale(0.3)
{
    m_numberList << "1"  << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "0";
    m_charList1 << "Q" << "W" << "E" <<"R" << "T" << "Y" << "U" <<"I" << "O" << "P";
    m_charList2 << "A" << "S" << "D" << "F" <<"G" <<"H" <<"J" << "K" <<"J" <<"，";
    m_charList3 << "Z" << "X" << "C" << "V" << "B" << "N" << "M" << "。";

    m_charList1_lower << "q" << "w" << "e" <<"r" << "t" <<  "y" << "u" << "i" << "o" <<"p";
    m_charList2_lower << "a" << "s" << "d" << "f" << "g"  << "h" << "j" << "k" << "j" << ",";
    m_charList3_lower << "z" << "x" << "c" << "v" << "b" << "n" << "m" << ".";
    m_buttonList << "返回" << "退格" << "清除" << "词/字" ;
}

void CharPanel::paintEvent(QPaintEvent *event)
{

    buttonRectList.clear();
    leftBlockIndexList.clear();
    rightBlockIndexList.clear();
    m_borderWidth = keyboard->borderWidth();
    QColor borderColor = keyboard->borderColor();
    QColor fontColor = keyboard->fontColor();
    QColor backColor = keyboard->backColor();
    QPainter p(this);
    QPen pen;
    pen.setColor(borderColor);
    pen.setWidth(m_borderWidth);
    p.setPen(pen);
    int width = this->width();
    int height = this->height();
    int pen_offset = m_borderWidth / 2;
    int pen_offset_right = 0;
    if (m_borderWidth % 2 == 0)
    {
        pen_offset_right = m_borderWidth / 2;
    }else{
        pen_offset_right = m_borderWidth / 2 + 1;
    }
    m_itemWidth = (width - m_borderWidth * 12) / (11 + m_ensureScale);
    m_itemHeight = (height - m_borderWidth * 5 ) / 4;
    width = (m_itemWidth + m_borderWidth) * 11 + m_itemWidth * m_ensureScale + m_borderWidth ;
    //height = (m_itemHeight + m_borderWidth) * 4 - pen_offset_right;
    m_width = width;

    if (keyboard->getKeyboardState() == KEYBOARD_STATE::DEFAULT)
    {
        // 先画横线
        p.drawLine(pen_offset, pen_offset, width - pen_offset_right, pen_offset);
        p.drawLine(pen_offset, (m_itemHeight + m_borderWidth) + pen_offset, width-pen_offset_right, (m_itemHeight + m_borderWidth) + pen_offset);
        p.drawLine(pen_offset, (m_itemHeight + m_borderWidth) * 2 + pen_offset, width-pen_offset_right,  (m_itemHeight + m_borderWidth) * 2 + pen_offset);
        p.drawLine(m_itemWidth / 2 + m_borderWidth + pen_offset, (m_itemHeight + m_borderWidth) * 3 + pen_offset,
                   m_itemWidth / 2 + m_borderWidth * 2 + (m_itemWidth + m_borderWidth) * 10 - pen_offset_right, (m_itemHeight + m_borderWidth) * 3 + pen_offset);
        p.drawLine(pen_offset, (m_itemHeight + m_borderWidth) * 4 + pen_offset, width - pen_offset_right, (m_itemHeight + m_borderWidth) * 4 + pen_offset);

        //前两排
        for (int i = 0; i< 11; ++i)
        {
            p.drawLine((m_itemWidth + m_borderWidth) * i + pen_offset, m_borderWidth + pen_offset, (m_itemWidth + m_borderWidth) * i + pen_offset,
                       m_itemHeight + m_borderWidth - pen_offset_right);
            p.drawLine((m_itemWidth + m_borderWidth) * i + pen_offset, m_borderWidth * 2 + m_itemHeight + pen_offset, (m_itemWidth + m_borderWidth) * i + pen_offset,
                       (m_itemHeight + m_borderWidth) * 2 - pen_offset_right);

            if (i != 10){
                QRect rect1((m_borderWidth + m_itemWidth) * i + m_borderWidth, m_borderWidth, m_itemWidth, m_itemHeight);
                p.fillRect(rect1, backColor);
                ButtonRectStr button1;
                button1.rect = rect1;
                button1.str = m_numberList[i];

                buttonRectList.append(button1);

                QRect rect2((m_borderWidth + m_itemWidth) * i + m_borderWidth, m_borderWidth * 2 + m_itemHeight, m_itemWidth, m_itemHeight);
                p.fillRect(rect2, backColor);
                ButtonRectStr button2;
                button2.rect = rect2;
                button2.str = shiftPressed?m_charList1[i]:m_charList1_lower[i];
                buttonRectList.append(button2);

            }else{
                QRect rect1((m_borderWidth + m_itemWidth) * i + m_borderWidth, m_borderWidth, m_itemWidth + m_itemWidth * m_ensureScale, m_itemHeight);
                p.fillRect(rect1, backColor);
                ButtonRectStr button1;
                button1.rect = rect1;
                button1.str = rightFirstControlStr;
                buttonRectList.append(button1);

                QRect rect2((m_borderWidth + m_itemWidth) * i + m_borderWidth, m_borderWidth * 2 + m_itemHeight, m_itemWidth + m_itemWidth * m_ensureScale, m_itemHeight);
                p.fillRect(rect2, backColor);
                ButtonRectStr button2;
                button2.rect = rect2;

                button2.str = rightSecondControlStr;
                buttonRectList.append(button2);

            }
        }

        int left_A = m_itemWidth / 2 + m_borderWidth + pen_offset;
        int start_A_y = m_itemHeight * 2 + m_borderWidth * 3 + pen_offset;
        int end_A_y = m_itemHeight * 3 + m_borderWidth * 3 - pen_offset_right;
        for (int i = 0; i < 11; ++i)
        {
            int x = (m_itemWidth + m_borderWidth) * i + left_A;
            p.drawLine(x, start_A_y, x, end_A_y);
            if (i != 10){
                QRect rect1(m_itemWidth / 2 + m_borderWidth *2 + (m_itemWidth + m_borderWidth) * i,m_itemHeight * 2 + m_borderWidth * 3, m_itemWidth, m_itemHeight);
                p.fillRect(rect1, backColor );
                ButtonRectStr button1;
                button1.rect = rect1;
                button1.str = shiftPressed?m_charList2[i]:m_charList2_lower[i];
                buttonRectList.append(button1);
            }else{
                int x = m_itemWidth / 2 + m_borderWidth *2 + (m_itemWidth + m_borderWidth) * i;
                QRect rect1(x,m_itemHeight * 2 + m_borderWidth * 3, width - x - m_borderWidth, m_itemHeight * 2 + m_borderWidth);
                p.fillRect(rect1, backColor );
                ButtonRectStr button1;
                button1.rect = rect1;
                button1.str = rightBlockStr;
                rightBlockIndexList.append(buttonRectList.size());
                buttonRectList.append(button1);
            }
        }

        int left_Z = m_itemWidth / 2 + m_borderWidth + m_borderWidth  + m_itemWidth + pen_offset;
        int start_Z_y = m_itemHeight * 3 + m_borderWidth * 4 + pen_offset;
        int end_Z_y = m_itemHeight * 4 + m_borderWidth * 4 - pen_offset_right;
        for (int i = 0; i < 9; ++i)
        {
            int x = (m_itemWidth + m_borderWidth) * i + left_Z;
            p.drawLine(x, start_Z_y, x, end_Z_y);
            if (i != 8){
                QRect rect(m_itemWidth / 2 + m_itemWidth + m_borderWidth *3 +  (m_itemWidth + m_borderWidth) * i , m_itemHeight*3 + m_borderWidth * 4, m_itemWidth, m_itemHeight);
                p.fillRect(rect, backColor);
                ButtonRectStr button;
                button.rect = rect;
                button.str = shiftPressed?m_charList3[i]:m_charList3_lower[i];
                buttonRectList.append(button);

            }else{
                QRect rect(m_itemWidth / 2 + m_itemWidth + m_borderWidth *3 +  (m_itemWidth + m_borderWidth) * i , m_itemHeight*3 + m_borderWidth * 4, m_itemWidth + m_borderWidth, m_itemHeight);
                p.fillRect(rect, backColor);
                ButtonRectStr button;
                button.rect = rect;
                button.str = rightBlockStr;
                rightBlockIndexList.append(buttonRectList.size());
                buttonRectList.append(button);
            }
        }

        p.drawLine(pen_offset + width - m_borderWidth, m_borderWidth + pen_offset, pen_offset + width - m_borderWidth, m_itemHeight + m_borderWidth - pen_offset_right);
        p.drawLine(pen_offset + width - m_borderWidth, m_itemHeight + m_borderWidth * 2 + pen_offset, pen_offset + width - m_borderWidth,
                   (m_itemHeight + m_borderWidth) * 2 - pen_offset_right);
        p.drawLine(pen_offset, (m_itemHeight + m_borderWidth) * 2 + m_borderWidth + pen_offset, pen_offset, (m_itemHeight + m_borderWidth) * 4 - pen_offset_right);
        p.drawLine(pen_offset + width - m_borderWidth, (m_itemHeight + m_borderWidth) * 2 + m_borderWidth + pen_offset, pen_offset + width - m_borderWidth,
                   (m_itemHeight + m_borderWidth) * 4 - pen_offset_right);

        QRect rect1(m_borderWidth, m_itemHeight *2 + m_borderWidth * 3, m_itemWidth/2, m_itemHeight * 2 + m_borderWidth);
        p.fillRect(rect1, backColor);
        ButtonRectStr button1;
        button1.rect = rect1;
        button1.str = leftBlockStr;
        leftBlockIndexList.append(buttonRectList.size());
        buttonRectList.append(button1);

        QRect rect2(m_borderWidth + m_itemWidth / 2, m_itemHeight * 3+ m_borderWidth * 4,  m_borderWidth + m_itemWidth, m_itemHeight);
        p.fillRect(rect2, backColor);
        ButtonRectStr button2;
        button2.rect = rect2;
        button2.str = leftBlockStr;
        leftBlockIndexList.append(buttonRectList.size());
        buttonRectList.append(button2);

        //绘制点击效果
        if (pressed)
        {


            if (pressRectIndex != -1)
            {
                ButtonRectStr &button = buttonRectList[pressRectIndex];

                if ((button.str != rightBlockStr) && (button.str != leftBlockStr))
                {
                    p.fillRect(button.rect, keyboard->clickBackColor());
                    p.drawPixmap(button.rect, keyboard->clickImage());
                }else
                {
                    if (button.str == rightBlockStr){

                        ButtonRectStr button1 = buttonRectList[rightBlockIndexList[0]];

                        ButtonRectStr button2 = buttonRectList[rightBlockIndexList[1]];

                        p.fillRect(button1.rect, keyboard->clickBackColor());
                        p.fillRect(button2.rect, keyboard->clickBackColor());
                        p.drawPixmap(button1.rect.united(button2.rect), keyboard->ensureClickImage());

                    }else if (button.str == leftBlockStr){

                        ButtonRectStr button1 = buttonRectList[leftBlockIndexList[0]];

                        ButtonRectStr button2 = buttonRectList[leftBlockIndexList[1]];

                        p.fillRect(button1.rect, keyboard->clickBackColor());
                        p.fillRect(button2.rect, keyboard->clickBackColor());
                        p.drawPixmap(button1.rect.united(button2.rect), keyboard->shiftClickImage());


                    }
                }

            }
        }

        //------------开始写字符
        QFont font;
        int fontSize = m_itemWidth * 0.3;
        font.setPointSize(fontSize);
        font.setFamily("微软雅黑");
        pen.setColor(fontColor);
        p.setFont(font);
        p.setPen(pen);

        QFontMetrics fm = p.fontMetrics();
        int width_1 = fm.width("1");

        int width_back = fm.width("退格");

        int height_fm = fm.height();

        int font_x_offset = (m_itemWidth - width_1)/ 2  + m_borderWidth ;
        int font_y_offset = m_itemHeight / 2 + height_fm / 3    + m_borderWidth;

        for (int i = 0; i < 10; ++i){
            p.drawText(font_x_offset + (m_itemWidth + m_borderWidth) * i, font_y_offset, m_numberList.at(i));
            p.drawText(font_x_offset + (m_itemWidth + m_borderWidth) * i, font_y_offset + (m_itemHeight + m_borderWidth) * 1, shiftPressed?m_charList1[i]:m_charList1_lower[i]);
            p.drawText(m_itemWidth /2 + m_borderWidth + font_x_offset + (m_itemWidth + m_borderWidth) * i,
                       font_y_offset + (m_itemHeight + m_borderWidth) * 2, shiftPressed?m_charList2[i]:m_charList2_lower[i]);
            if (i < 8){
                p.drawText(m_itemWidth/2 +m_itemWidth + m_borderWidth * 2 + font_x_offset + (m_itemWidth + m_borderWidth) * i,
                           font_y_offset + (m_itemHeight + m_borderWidth) * 3, shiftPressed?m_charList3[i]:m_charList3_lower[i]);
            }
        }
        font_x_offset = (m_itemWidth + m_itemWidth * m_ensureScale - width_back) / 2 + m_borderWidth;
        font_y_offset = m_itemHeight / 2 + height_fm / 3  + m_borderWidth;
        p.drawText(font_x_offset + (m_itemWidth + m_borderWidth) * 10, font_y_offset, QString("清空"));
        p.drawText(font_x_offset + (m_itemWidth + m_borderWidth) * 10, font_y_offset + m_itemHeight + m_borderWidth, QString("退格"));
        p.drawText(font_x_offset, font_y_offset + (m_itemHeight + m_borderWidth) *3, QString("Shift"));
        font_x_offset = (m_itemWidth * 2 - width_back) / 2 + m_borderWidth;
        p.drawText((m_itemWidth + m_borderWidth) * 9 + m_borderWidth+ m_itemWidth /2 + font_x_offset,font_y_offset + (m_itemHeight + m_borderWidth) *3,
                   QString("确定"));

    }
    else if (keyboard->getKeyboardState() == KEYBOARD_STATE::SHOWHANZI)
    {
        m_x_offset = width - m_itemWidth - m_itemWidth / 2 - m_borderWidth * 2;
        p.fillRect(0,0, m_x_offset, m_borderWidth * 5 + m_itemHeight * 4, keyboard->showHanziBackColor());
        for (int i = 0; i < 5; ++i){
            int temp = i * (m_borderWidth + m_itemHeight) + pen_offset;
            p.drawLine(m_x_offset + pen_offset, temp, width - pen_offset_right, temp);
            if (i != 4){
                temp = i * (m_borderWidth + m_itemHeight) + m_borderWidth;
                QRect rect(m_x_offset + m_borderWidth, temp, m_itemWidth + m_itemWidth / 2, m_itemHeight);
                p.fillRect(rect, backColor);
                ButtonRectStr button;
                button.rect = rect;
                button.str = m_buttonList[i];
                buttonRectList.append(button);
            }
        }

        int end_Z_y = m_itemHeight * 4 + m_borderWidth * 5 - pen_offset_right;
        p.drawLine(m_x_offset + pen_offset,  pen_offset, m_x_offset + pen_offset, end_Z_y);
        p.drawLine(width - m_borderWidth + pen_offset, pen_offset, width - m_borderWidth + pen_offset,end_Z_y);


        pen.setColor(keyboard->showHanziFontColor());
        p.setFont(keyboard->hanziFont());
        p.setPen(pen);


        QFontMetrics fm = p.fontMetrics();
        int height_fm = fm.height();
        int font_y_offset = m_itemHeight / 2 + height_fm / 3    + m_borderWidth;
        int width_1 = fm.width("1");
        int width_back = fm.width("退格");

        int font_x_offset = 10;

        QVector<QStringList> &hanziModel = g_CPinyinInputMethod::getInstance()->HanziModel;
        int size = hanziModel.size();
        if (size == 0)
        {
            return;
        }
        vHanziStr.clear();
        vHanziStr.append(QStringList());
        vHanziWidth.clear();
        vHanziWidth.append(QVector<int>());
        int currentPosX = font_x_offset;
        int vIndex = 0;
        if (oneWordModel){
            size = 1;
        }
        for (int i = size - 1; i >= 0; --i)
        {
            QStringList &hanziList = hanziModel[i];
            if (hanziList.size() != 0)
            {
                int font_width = fm.width(hanziList[0]) * m_fontScale;

                int firstFontCount = (m_x_offset - currentPosX) / font_width;
                int rowFontCount = m_x_offset / font_width;

                if (hanziList.size() <= rowFontCount)
                {
                    vHanziStr[vIndex].append(hanziList);
                    for (int j = 0; j < hanziList.size(); j++){
                        vHanziWidth[vIndex].append(font_width);
                        currentPosX += font_width;
                    }
                }else
                {
                    for (int j = 0; j < firstFontCount; j++ )
                    {
                        vHanziStr[vIndex].append(hanziList[j]);
                        vHanziWidth[vIndex].append(font_width);
                    }
                    vHanziStr.append(QStringList());
                    vHanziWidth.append(QVector<int>());
                    vIndex++;

                    int rowCount = (hanziList.size() - firstFontCount) / rowFontCount;
                    for (int m = 0; m < rowCount; m++)
                    {
                        for (int j = 0; j < rowFontCount; j++ )
                        {
                            vHanziStr[vIndex].append(hanziList[j + m * rowFontCount + firstFontCount]);
                            vHanziWidth[vIndex].append(font_width);
                        }
                        vHanziStr.append(QStringList());
                        vHanziWidth.append(QVector<int>());
                        vIndex++;
                    }

                    currentPosX = font_x_offset;
                    int remaindCount = hanziList.size() - rowFontCount * rowCount - firstFontCount;
                    for (int j = 0; j < remaindCount; j++ )
                    {
                        vHanziStr[vIndex].append(hanziList[j+ rowFontCount * rowCount + firstFontCount]);
                        vHanziWidth[vIndex].append(font_width);
                        currentPosX += font_width;
                    }
                }

            }
        }

        for (int i = 0; i < vIndex + 1; ++i)
        {
            QStringList &hanziStrList = vHanziStr[i];
            QVector<int> &hanziWidthV = vHanziWidth[i];
            int x_offset = 0;
            int size = hanziStrList.size();

            for (int j = 0; j < size; ++j)
            {

                p.drawText(x_offset + font_x_offset, font_y_offset + i * (m_itemHeight + m_borderWidth) + m_font_y_offset , hanziStrList[j]);


                x_offset += hanziWidthV[j];


            }
        }

        if (pressed)
        {

            if (pressX > m_x_offset)
            {
                int row = pressY / m_itemHeight;

                int temp = row * (m_borderWidth + m_itemHeight) + m_borderWidth;
                QRect rect(m_x_offset + m_borderWidth, temp, m_itemWidth + m_itemWidth / 2, m_itemHeight);
                p.fillRect(rect, keyboard->clickBackColor());
                p.drawPixmap(rect, keyboard->clickImage());
            }

        }


        pen.setColor(fontColor);
        p.setPen(pen);
        m_total_font_height = (vIndex + 1) * m_itemHeight;

        font_x_offset = (m_itemWidth + m_itemWidth /  2 - width_back) / 2 + m_borderWidth;
        p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 0 + pen_offset + font_y_offset, "返回" );
        p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 1 + pen_offset + font_y_offset, "退格" );
        p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 2 + pen_offset + font_y_offset, "清除" );
        //  p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 3 + pen_offset + font_y_offset, "词/字" );
        if (oneWordModel){
            pen.setColor(keyboard->showHanziWordColor());
            p.setPen(pen);
            p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 3 + pen_offset + font_y_offset, "词" );
            pen.setColor(fontColor);
            p.setPen(pen);
            p.drawText(m_x_offset + pen_offset + (m_itemWidth + m_itemWidth /  2) / 2 , (m_borderWidth + m_itemHeight) * 3 + pen_offset + font_y_offset, "/字" );

        }else{
            p.drawText(m_x_offset + pen_offset + font_x_offset, (m_borderWidth + m_itemHeight) * 3 + pen_offset + font_y_offset, "词" );
            pen.setColor(keyboard->showHanziWordColor());
            p.setPen(pen);
            p.drawText(m_x_offset + pen_offset + (m_itemWidth + m_itemWidth /  2) / 2, (m_borderWidth + m_itemHeight) * 3 + pen_offset + font_y_offset, "/字" );
        }




    }

}


void CharPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        pressed  = true;

        if (keyboard->getKeyboardState() == KEYBOARD_STATE::DEFAULT)
        {
            pressPoint = event->pos();
            pressRectIndex = -1;
            for (int i=0; i < buttonRectList.size(); ++i){
                ButtonRectStr &button = buttonRectList[i];
                if (button.rect.contains(pressPoint))
                {
                    pressRectIndex = i;
                }
            }

            this->repaint();
        }
        else if (keyboard->getKeyboardState() == KEYBOARD_STATE::SHOWHANZI)
        {
            pressY = event->pos().y();
            pressX = event->pos().x();
            moveY = pressY;
            this->repaint();
        }
    }
}

void CharPanel::mouseMoveEvent(QMouseEvent *event)
{

    if (pressed)
    {
        if (keyboard->getKeyboardState() == KEYBOARD_STATE::DEFAULT)
        {
            int currentIndex = -1;
            pressPoint = event->pos();
            for (int i=0; i < buttonRectList.size(); ++i){
                ButtonRectStr &button = buttonRectList[i];
                if (button.rect.contains(pressPoint))
                {
                    currentIndex = i;
                }
            }
            if ((pressRectIndex != -1) && (currentIndex != pressRectIndex))
            {
                pressed = false;
                this->repaint();
            }



        }
        else if (keyboard->getKeyboardState() == KEYBOARD_STATE::SHOWHANZI)
        {


            if (m_total_font_height < this->height()){

                return;
            }
            if ((m_font_y_offset <= 0) && (m_font_y_offset >= (this->height() - m_total_font_height)))
            {
                int y = event->pos().y();
                m_font_y_offset += y - moveY;
                moveY = y;
                if (m_font_y_offset > 0){
                    m_font_y_offset = 0;
                }
                else if (m_font_y_offset < (this->height() - m_total_font_height)){
                    m_font_y_offset = this->height() - m_total_font_height;
                }
                this->repaint();
            }
        }

    }
}

void CharPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (pressed)
        {
            if (keyboard->getKeyboardState() == KEYBOARD_STATE::DEFAULT)
            {
                if (pressRectIndex != -1)
                {
                    ButtonRectStr &button = buttonRectList[pressRectIndex];

                    if (m_numberList.contains(button.str))
                    {
                        keyboard->addText(button.str);
                    }
                    else if ((m_charList1.contains(button.str)) || (m_charList1_lower.contains(button.str)) ||
                             (m_charList2.contains(button.str)) || (m_charList2_lower.contains(button.str)) ||
                             (m_charList3.contains(button.str)) || (m_charList3_lower.contains(button.str)))
                    {
                        keyboard->addSearchChar(button.str);
                    }
                    else if (button.str == rightFirstControlStr)
                    {
                        keyboard->clearAllText();
                        keyboard->clear();

                    }
                    else if (button.str == rightSecondControlStr)
                    {
                        keyboard->backspace();
                    }
                    else if (button.str == leftBlockStr)
                    {
                        shiftPressed = !shiftPressed;
                    }
                    else if (button.str == rightBlockStr)
                    {
                        keyboard->pressEnter();
                    }

                }


                pressed = false;
                this->repaint();
            }
            else if (keyboard->getKeyboardState() == KEYBOARD_STATE::SHOWHANZI)
            {
                int y = event->pos().y();
                if (abs(y - pressY) > 5){
                    return;
                }
                int x = event->pos().x();
                if (x > m_x_offset)
                {
                    int row = y / m_itemHeight;
                    if (row == 0){

                        keyboard->changeToState(KEYBOARD_STATE::DEFAULT);
                    }else if (row == 1){

                        keyboard->backspace();
                    }else if (row == 2){

                        keyboard->changeToState(KEYBOARD_STATE::DEFAULT);
                        keyboard->clear();
                    }else if (row == 3){

                        this->clear();
                        oneWordModel = !oneWordModel;

                    }
                }else{
                    int row = (y - m_font_y_offset) / m_itemHeight;

                    int total_x = 0;
                    if (vHanziWidth.size() < row + 1){
                        return;
                    }
                    for (int i = 0; i <vHanziWidth[row].size(); ++i)
                    {
                        total_x += vHanziWidth[row].at(i);
                        if (x < total_x){
                            QString str = vHanziStr[row].at(i);

                            keyboard->addText(str);
                            keyboard->changeToState(KEYBOARD_STATE::DEFAULT);
                            keyboard->clear();
                            break;
                        }
                    }
                }
                pressed = false;
                this->repaint();


            }

        }
    }
}

