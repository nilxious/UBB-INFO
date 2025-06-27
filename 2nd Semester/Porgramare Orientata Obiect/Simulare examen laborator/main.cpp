#include <QApplication>
#include <QPushButton>

#include "Gui.h"
#include "Teste.h"
#include "Service.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    ruleazaTestele();

    Repository repository("fisier_imbracaminte.txt");

    Service service(repository);

    Gui gui(service);

    gui.show();
    return QApplication::exec();
}
