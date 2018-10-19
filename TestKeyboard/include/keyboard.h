#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QStackedWidget>
#include <QtUiPlugin/QDesignerExportWidget>
class CPinyinInputMethod ;
#include <QLabel>
#include <QIcon>
#include <QSize>
class QTextEdit;
class CharPanel;
class HanziPanel;


enum class KEYBOARD_STATE: unsigned int{
    DEFAULT,
    SHOWHANZI
};



class QDESIGNER_WIDGET_EXPORT Keyboard : public QStackedWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor )
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth)
    Q_PROPERTY(QColor fontColor READ fontColor WRITE setFontColor )
    Q_PROPERTY(QColor backColor READ backColor WRITE setBackColor)
    Q_PROPERTY(QFont hanziFont READ hanziFont WRITE setHanziFont)
    Q_PROPERTY(QColor hanziFontColor READ hanziFontColor WRITE setHanziFontColor)
    Q_PROPERTY(QColor hanziBackColor READ hanziBackColor WRITE setHanziBackColor)
    Q_PROPERTY(int showLabelHeight READ showLabelHeight WRITE setShowLabelHeight)
    Q_PROPERTY(int hanziPanelHeight READ hanziPanelHeight WRITE setHanziPanelHeight )
    //Q_PROPERTY(QPixmap omitImage READ omitImage WRITE setOmitImage)
    Q_PROPERTY(QIcon omitIcon READ omitIcon WRITE setOmitIcon)
    Q_PROPERTY(QSize omitIconSize READ omitIconSize WRITE setOmitIconSize)
    Q_PROPERTY(QPixmap clickImage READ clickImage WRITE setClickImage)
    Q_PROPERTY(QPixmap shiftClickImage READ shiftClickImage WRITE setShiftClickImage)
    Q_PROPERTY(QPixmap ensureClickImage READ ensureClickImage WRITE setEnsureClickImage)
    Q_PROPERTY(QColor clickBackColor  READ clickBackColor WRITE setClickBackColor)
    Q_PROPERTY(QColor showHanziBackColor READ showHanziBackColor WRITE setShowHanziBackColor)
    Q_PROPERTY(QColor showHanziWordColor READ showHanziWordColor WRITE setShowHanziWordColor)
    Q_PROPERTY(QColor showHanziFontColor READ showHanziFontColor WRITE setShowHanziFontColor)
public:
    Keyboard(QWidget *parent = 0);
    ~Keyboard();

    QColor borderColor(){
        return this->m_borderColor;
    }
    void setBorderColor(QColor &color){
        this->m_borderColor = color;
    }

    QColor fontColor(){
        return this->m_fontColor;
    }
    void setFontColor(QColor &color){
        this->m_fontColor = color;
    }

    QColor backColor(){
        return this->m_backColor;
    }
    void setBackColor(QColor &color){
        this->m_backColor = color;
    }
    QTextEdit * getInputTextEdit(){
        return m_inputTextEdit;
    }

    void setInputTextEdit(QTextEdit * widget){
        this->m_inputTextEdit = widget;
    }
    int borderWidth(){
        return this->m_borderWidth;
    }
    void setBorderWidth(int width){
        m_borderWidth = width;
    }
    QLabel * getLabel(){
        return this->m_labPyText;
    }

    QFont hanziFont(){
        return this->m_hanziFont;
    }
    void setHanziFont(QFont &font){
        m_hanziFont = font;
    }

    int showLabelHeight(){
        return this->m_showLabelHeight;
    }
    void setShowLabelHeight(int h){
        m_showLabelHeight = h;
        m_labPyText->setFixedHeight( m_showLabelHeight);
    }
    QWidget *getHanziPanel();
    QColor hanziBackColor(){
        return m_hanziBackColor;
    }
    void setHanziBackColor(QColor &color){
        m_hanziBackColor = color;
    }
    //    QPixmap omitImage(){
    //        return this->m_omitImage;
    //    }
    //    void setOmitImage(QPixmap &img){
    //        m_omitImage = img;
    //    }

    QIcon omitIcon(){
        return m_omitIcon;
    }
    void setOmitIcon(QIcon &icon){
        m_omitIcon = icon;
    }

    QSize omitIconSize(){
        return m_omitIconSize;
    }

    void setOmitIconSize(QSize &size){
        m_omitIconSize = size;
    }

    QPixmap clickImage(){
        return m_clickImage;
    }
    void setClickImage(QPixmap &img){
        m_clickImage  = img;
    }
    QPixmap shiftClickImage(){
        return m_shiftClickImage;
    }
    void setShiftClickImage(QPixmap &img){
        m_shiftClickImage = img;
    }

    QPixmap ensureClickImage(){
        return m_ensureClickImage;
    }
    void setEnsureClickImage(QPixmap &img){
        m_ensureClickImage = img;
    }

    QColor clickBackColor(){
        return m_clickBackColor;
    }

    void setClickBackColor(QColor &color){
        m_clickBackColor = color;
    }

    QColor showHanziBackColor(){
        return m_showHanziBackColor;
    }
    void setShowHanziBackColor(QColor &color){
        m_showHanziBackColor = color;
    }

    QColor showHanziWordColor(){
        return m_showHanziWordColor;
    }

    void setShowHanziWordColor(QColor &color){
        m_showHanziWordColor = color;
    }

    void changeToState(KEYBOARD_STATE state);

    int getWidth();
    void clear();
    void addText(QString str);
    void backspace();
    void addSearchChar(QString ch);
    void pressEnter();
    void clearAllText();

    KEYBOARD_STATE getKeyboardState(){
        return m_state;
    }

    void setKeyboardState(KEYBOARD_STATE st){
        m_state = st;
    }

    QColor hanziFontColor(){
        return m_hanziFontColor;
    }

    void setHanziFontColor(QColor& color){
        m_hanziFontColor = color;
    }

    QColor showHanziFontColor(){
        return m_showHanziFontColor;
    }

    void setShowHanziFontColor(QColor &color){
        m_showHanziFontColor = color;
    }

    int hanziPanelHeight(){
        return m_hanziPanelHeight;
    }

    void setHanziPanelHeight(int h);
private:
    QColor m_borderColor;
    QColor m_fontColor;
    QColor m_backColor;
    QTextEdit * m_inputTextEdit;

    int m_borderWidth;
    QLabel * m_labPyText;
    CharPanel * charPanel;
    QFont m_hanziFont;
    int m_showLabelHeight;
    int m_hanziPanelHeight;
    HanziPanel * hanziPanel;
    QColor m_hanziBackColor;
    //  QPixmap m_omitImage;
    QIcon m_omitIcon;
    QSize m_omitIconSize;
    QPixmap m_clickImage;
    QPixmap m_shiftClickImage;
    QPixmap m_ensureClickImage;
    QColor m_clickBackColor;
    QColor m_hanziFontColor;
    QColor m_showHanziBackColor;
    QColor m_showHanziWordColor;
    QColor m_showHanziFontColor;
    KEYBOARD_STATE m_state;
    QString m_searchStr;
};

#endif
