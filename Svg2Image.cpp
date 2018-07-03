#include "Svg2Image.h"
#include <QSvgRenderer>
#include <QPainter>

Svg2Image::Svg2Image() {}
Svg2Image::~Svg2Image() {}

bool Svg2Image::save(QByteArray array, QString path, QSize size, const char* format, int dpi, Qt::GlobalColor color)
{
    QImage *im = this->Bytes2Image(array, size, dpi, color);
    im->save(path, format);
    return true;
}

QImage* Svg2Image::Bytes2Image(QByteArray array, QSize size, int dpi, Qt::GlobalColor color)
{
    QSvgRenderer *svg = new QSvgRenderer(array);
    //Covert size in mm to pixel with given dpi
    size.rwidth() *= dpi;
    size.rwidth() /=25.4;
    size.rheight() *= dpi;
    size.rheight() /=25.4;
    QImage *im = new QImage(size, QImage::Format_ARGB32);
    double dpm = (double)dpi * 1E3 / 25.4;
    im->setDotsPerMeterX(dpm);
    im->setDotsPerMeterY(dpm);
    im->fill(color);
    QPainter *painter = new QPainter(im);
    svg->render(painter);
    painter->end();
    return im;
}
