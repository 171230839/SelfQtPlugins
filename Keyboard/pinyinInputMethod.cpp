#include "pinyinInputMethod.h"
#include <QDateTime>
#include <QSettings>

#include <QDebug>
#include <QApplication>
#include "pinyin/pinyinime.h"
using namespace ime_pinyin;
#include <QFile>

/**
 * @brief CPinyinInputMethod::CPinyinInputMethod
 * 调用谷歌输入法。
 *  加载谷歌输入法所需资源，包含配置文件 pinyinEx.ini和字典 dat文件。
 * 字典.dat 文件根据路径需要复制粘贴到dll所在目录下。
 */
CPinyinInputMethod::CPinyinInputMethod()
{

    QString tt = QApplication::applicationDirPath()+"/dict/dict_pinyin.dat";
    QString t = QApplication::applicationDirPath()+ "/user.dat";
//    bool ret = im_open_decoder(tt.toLocal8Bit().data(),  t.toLocal8Bit().data());
 bool ret = im_open_decoder(QString(":/dict/dict_pinyin.dat"), t);
    if (!ret) {
        qDebug()<<"--------------im_open_decoder false ";
        return;
    }

//    QFile file(":/dict/dict_pinyin.dat");
//    QFile file(":/dict/test.txt");
//    qDebug() << " file open" << file.open(QIODevice::ReadWrite);
//    qDebug()<< " read " << QString::fromLocal8Bit(file.readAll());
//    qDebug()<<" file ---- " << file.exists() << file.handle();
    qDebug()<<"-im_open_decoder ";
}

/**
 * @brief CPinyinInputMethod::~CPinyinInputMethod
 *  清空状态， 调用输入法资源卸载接口。
 */
CPinyinInputMethod::~CPinyinInputMethod()
{
	lstEN.clear();
	HanziModel.clear();
    im_close_decoder();
}

/**
 * @brief CPinyinInputMethod::SearchCN
 * 根据字符串，获取中文匹配结果
 * @param gemfield
 */
QString CPinyinInputMethod::SearchCN(const QString &gemfield)
{

    if (gemfield == m_gemfield) {
        return "";
    }
     QString py = gemfield;
    if (gemfield.size() > m_gemfield.size())
    {

        QStringList newHanziList;
        im_reset_search();
        int num = im_search(gemfield.toLatin1().data(), gemfield.size());
        const uint16 *pos;
        int size = im_get_spl_start_pos(pos);

        for (int i = size - 1; i > 0; i--) {
            py.insert(pos[i], "'");
        }
        py.replace("''", "'");
//        if (num > 50) {
//            num = 50;
//        }

        char16 buf[20] = {0};
        for (int i = 0; i < num; i++) {
            im_get_candidate(i, buf, 20);
            newHanziList << QString::fromUtf16(buf);
        }

        HanziModel.append(newHanziList);

    }
    else if (gemfield.size() < m_gemfield.size())
    {
        HanziModel.resize(gemfield.size());
    }
    m_gemfield = gemfield;
    return py;

}

void CPinyinInputMethod::clear()
{
    m_gemfield = "";
    HanziModel.clear();
}
