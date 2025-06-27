#include <QApplication>
#include "Gui.h"
#include "teste.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    ruleaza_teste();

    Repository repo("fisier.txt");
    Service srv(repo);
    Gui gui(srv);
    gui.show();
    return a.exec();
}

