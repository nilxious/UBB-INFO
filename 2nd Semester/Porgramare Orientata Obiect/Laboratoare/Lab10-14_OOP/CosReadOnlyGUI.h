#include "observer.h"
#include "CosCumparaturi.h"
#include <QWidget>
#include <QPainter>
#include <cstdlib>

class CosReadOnlyGUI : public QWidget, public Observer {
private:
    CosCumparaturi& cos;

public:
    explicit CosReadOnlyGUI(CosCumparaturi& cos) : cos{ cos } {
        cos.addObserver(this);
        setMinimumSize(400, 300);
    }

    ~CosReadOnlyGUI() override {
        cos.removeObserver(this);
    }

    void update() override {
        repaint(); // redesenează când se modifică coșul
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        int count = cos.getProduse().size();
        for (int i = 0; i < count; ++i) {
            int x = rand() % width();
            int y = rand() % height();
            int size = 20 + rand() % 30;
            painter.drawEllipse(x, y, size, size);
        }
    }
};
