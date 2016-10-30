#ifndef QGV
#define QGV
#include <QGraphicsView>

class QGV : public QGraphicsView
{
protected:

    inline void setCursorArrow()
    {
        viewport()->setCursor(Qt::CrossCursor);
    }

    void enterEvent(QEvent *event)
    {
        QGraphicsView::enterEvent(event);
        setCursorArrow();
    }

    void mousePressEvent(QMouseEvent *event)
    {
        QGraphicsView::mousePressEvent(event);
        setCursorArrow();
    }

    void mouseReleaseEvent(QMouseEvent *event)
    {
        QGraphicsView::mouseReleaseEvent(event);
        setCursorArrow();
    }
};

#endif // QGV

