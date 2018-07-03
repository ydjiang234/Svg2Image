#include "Svg2Image.h"
#include <QSvgRenderer>
#include <QPainter>

Svg2Image::Svg2Image() {}
Svg2Image::~Svg2Image() {}

bool Svg2Image::save(QByteArray array, QString path, QSize size, const char* format, int dpi, int Quality, Qt::GlobalColor color)
{
    QImage *im = this->Bytes2Image(array, size, dpi, Quality, color);
    im->save(path, format);
    return true;
}

QImage* Svg2Image::Bytes2Image(QByteArray array, QSize size, int dpi, int Quality, Qt::GlobalColor color)
{
    QSvgRenderer *svg = new QSvgRenderer(array);
    QImage *im = new QImage(size.width()*Quality, size.height()*Quality, QImage::Format_ARGB32);
    int dpm = (int)dpi * 25.4 / 10E3;
    im->setDotsPerMeterX(dpm);
    im->setDotsPerMeterY(dpm);
    im->fill(color);
    QPainter *painter = new QPainter(im);
    svg->render(painter);
    painter->end();
    im->scaled(size);
    return im;
}
