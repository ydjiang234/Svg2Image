#ifndef SVG2IMAGE_H
#define SVG2IMAGE_H

#include <iostream>
#include <QImage>
#include <QByteArray>


class Svg2Image
{
public:
    Svg2Image();
    ~Svg2Image();
    bool save(QByteArray array, QString path, QSize size, const char* format="jpg", int dpi=300, Qt::GlobalColor color=Qt::GlobalColor::white);
    //size here is in mm
private:
    QImage* Bytes2Image(QByteArray array, QSize size, int dpi=300, Qt::GlobalColor color=Qt::GlobalColor::white);
};

#endif // SVG2IMAGE_H
