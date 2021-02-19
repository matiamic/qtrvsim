#ifndef LCDDISPLAYVIEW_H
#define LCDDISPLAYVIEW_H

#include "qtmips_machine/memory/backend/lcddisplay.h"

#include <QImage>
#include <QWidget>

class LcdDisplayView : public QWidget {
    Q_OBJECT

    using Super = QWidget;

public:
    explicit LcdDisplayView(QWidget *parent = nullptr);
    ~LcdDisplayView() override;

    void setup(machine::LcdDisplay *lcd_display);
    uint fb_width();
    uint fb_height();

public slots:
    void pixel_update(uint x, uint y, uint r, uint g, uint b);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void update_scale();
    float scale_x;
    float scale_y;
    QImage *fb_pixels;
};

#endif // LCDDISPLAYVIEW_H
