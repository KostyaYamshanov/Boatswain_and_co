#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale( LC_ALL,"Russian" );
    QApplication App(argc, argv);
    QTranslator Translator;
    QLabel Label("Ты джавист?");
    QPushButton *PButtonYes = new QPushButton ("Нет!");
    QPushButton *PButtonOfc = new QPushButton ("Конечно нет!");
    QPushButton *PButtonPnh = new QPushButton ("Да (Пойти нахуй)");
    QWidget *Widget = new QWidget();
    QVBoxLayout *VLay = new QVBoxLayout(Widget);
    QMainWindow Window;

    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "LabBPM_" + QLocale(locale).name();
        if (Translator.load(":/i18n/" + baseName)) {
            App.installTranslator(&Translator);
            break;
        }
    }

    QObject :: connect (PButtonYes, SIGNAL(clicked()), &Label, SLOT(mysettext("Фу")));
    QObject :: connect (PButtonOfc, SIGNAL(clicked()), &Label, SLOT(mysettext("Мерзость")));
    QObject :: connect (PButtonPnh, SIGNAL(clicked()), &App, SLOT(quit()));

    VLay->addWidget(&Label);
    VLay->addWidget(PButtonYes);
    VLay->addWidget(PButtonOfc);
    VLay->addWidget(PButtonPnh);

    Widget->setLayout(VLay);
    Window.setCentralWidget(Widget);
    Window.show();
    return App.exec ();
}
