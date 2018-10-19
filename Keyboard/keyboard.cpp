#include "keyboard.h"

#include <QPainter>
#include <QPen>
#include <QFontMetrics>
#include <QDebug>
#include <QMouseEvent>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "pinyinInputMethod.h"
#include "hanziPanel.h"
#include "charPanel.h"

Keyboard::Keyboard(QWidget *parent) :
    QStackedWidget(parent)
  ,m_borderColor(QColor(255,255,255,255))
  ,m_backColor(QColor("#666666"))
  ,m_fontColor(Qt::white)
  ,m_inputTextEdit(nullptr)
  ,m_borderWidth(1)
  ,m_hanziFont(QFont("微软雅黑",20))
  ,m_showLabelHeight(35)
  ,m_hanziPanelHeight(50)
  ,m_hanziBackColor(QColor(255,255,255, 110))
  ,m_hanziFontColor(Qt::black)
  ,m_showHanziBackColor(QColor(165,165,165, 110))
  ,m_showHanziWordColor(QColor(211,211,211, 255))
  ,m_showHanziFontColor(Qt::black)
  ,m_state(KEYBOARD_STATE::DEFAULT)
{

    QWidget *widget = new QWidget();
    QVBoxLayout *mvl = new QVBoxLayout;
    m_labPyText = new QLabel(this);
    m_labPyText->setObjectName("keyboard_label");
    m_labPyText->setFixedHeight(m_showLabelHeight);
    mvl->addWidget(m_labPyText);
    hanziPanel = new HanziPanel(this);
    hanziPanel->setFixedHeight(m_hanziPanelHeight);
    mvl->addWidget(hanziPanel);

    charPanel = new CharPanel(this);

    mvl->addWidget(charPanel);
    mvl->setSpacing(0);
    mvl->setMargin(0);
    widget->setLayout(mvl);
    this->addWidget(widget);




    //   pinyinInput = g_CPinyinInputMethod::getInstance();
}

Keyboard::~Keyboard()
{
    //if (pinyinInput != NULL){
    //      delete pinyinInput;
    //}

}




QWidget *Keyboard::getHanziPanel()
{
    return qobject_cast<QWidget*>(this->hanziPanel);
}

void Keyboard::changeToState(KEYBOARD_STATE state)
{
     this->setKeyboardState(state);
    charPanel->repaint();
    hanziPanel->repaint();
}


int Keyboard::getWidth()
{
    return charPanel->getWidth();
}

void Keyboard::clear()
{
    g_CPinyinInputMethod::getInstance()->clear();
    charPanel->clear();
    m_labPyText->clear();
    hanziPanel->clear();
    m_searchStr.clear();
    charPanel->repaint();
    hanziPanel->repaint();
}

void Keyboard::addText(QString text)
{
    if (m_inputTextEdit == NULL){
        return;
    }
    QString inputText = m_inputTextEdit->toPlainText();
    inputText += text;
    m_inputTextEdit->setPlainText(inputText);
    m_inputTextEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
}

void Keyboard::backspace()
{
    if ( m_searchStr.size() > 0){
         m_searchStr =  m_searchStr.mid(0,  m_searchStr.size()-1);
        m_labPyText->setText(g_CPinyinInputMethod::getInstance()->SearchCN( m_searchStr));
        hanziPanel->repaint();
    }
    else{
        if (m_inputTextEdit == NULL){
            return;
        }
        QString inputText = m_inputTextEdit->toPlainText();
        if (inputText.size() > 0)
        {
            inputText = inputText.mid(0, inputText.size() - 1);
            m_inputTextEdit->setPlainText(inputText);
           m_inputTextEdit->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);

        }
    }
}

void Keyboard::addSearchChar(QString ch)
{
    m_searchStr += ch;
    m_labPyText->setText(g_CPinyinInputMethod::getInstance()->SearchCN(m_searchStr));
    hanziPanel->repaint();
}

void Keyboard::pressEnter()
{
    this->addText(m_searchStr);
    this->clear();
}

void Keyboard::clearAllText()
{
    if (m_inputTextEdit == NULL){
        return;
    }
    m_inputTextEdit->clear();
}

void Keyboard::setHanziPanelHeight(int h)
{
    m_hanziPanelHeight = h;
    hanziPanel->setFixedHeight(m_hanziPanelHeight);
}


