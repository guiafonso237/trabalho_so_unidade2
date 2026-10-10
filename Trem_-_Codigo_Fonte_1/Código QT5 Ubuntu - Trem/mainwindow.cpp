#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,140, 50);
    trem2 = new Trem(2,140, 170);
    trem3 = new Trem(3, 410, 170);
    trem4 = new Trem(4, 40, 290);
    trem5 = new Trem(5, 310, 290);
    trem6 = new Trem(6, 580, 290);

    //Indica qual quadrante ele está
    trem1->quadrado.esqSup.x = 140;
    trem1->quadrado.esqSup.y = 50;

    trem1->quadrado.esqInf.x = 140;
    trem1->quadrado.esqInf.y = 170;

    trem1->quadrado.dirSup.x = 680;
    trem1->quadrado.dirSup.y = 50;

    trem1->quadrado.dirInf.x = 680;
    trem1->quadrado.dirInf.y = 170;

    // Trem B (assumindo a variável trem2)
    trem2->quadrado.esqSup.x = 140;
    trem2->quadrado.esqSup.y = 170;

    trem2->quadrado.esqInf.x = 140;
    trem2->quadrado.esqInf.y = 290;

    trem2->quadrado.dirSup.x = 410;
    trem2->quadrado.dirSup.y = 170;

    trem2->quadrado.dirInf.x = 410;
    trem2->quadrado.dirInf.y = 290;

    // Trem C (assumindo a variável trem3)
    trem3->quadrado.esqSup.x = 410;
    trem3->quadrado.esqSup.y = 170;

    trem3->quadrado.esqInf.x = 410;
    trem3->quadrado.esqInf.y = 290;

    trem3->quadrado.dirSup.x = 680;
    trem3->quadrado.dirSup.y = 170;

    trem3->quadrado.dirInf.x = 680;
    trem3->quadrado.dirInf.y = 290;

    // Trem D (assumindo a variável trem4)
    trem4->quadrado.esqSup.x = 40;
    trem4->quadrado.esqSup.y = 290;

    trem4->quadrado.esqInf.x = 40;
    trem4->quadrado.esqInf.y = 410;

    trem4->quadrado.dirSup.x = 310;
    trem4->quadrado.dirSup.y = 290;

    trem4->quadrado.dirInf.x = 310;
    trem4->quadrado.dirInf.y = 410;

    // Trem E (assumindo a variável trem5)
    trem5->quadrado.esqSup.x = 310;
    trem5->quadrado.esqSup.y = 290;

    trem5->quadrado.esqInf.x = 310;
    trem5->quadrado.esqInf.y = 410;

    trem5->quadrado.dirSup.x = 580;
    trem5->quadrado.dirSup.y = 290;

    trem5->quadrado.dirInf.x = 580;
    trem5->quadrado.dirInf.y = 410;

    // Trem F (assumindo a variável trem6)
    trem6->quadrado.esqSup.x = 580;
    trem6->quadrado.esqSup.y = 290;

    trem6->quadrado.esqInf.x = 580;
    trem6->quadrado.esqInf.y = 410;

    trem6->quadrado.dirSup.x = 850;
    trem6->quadrado.dirSup.y = 290;

    trem6->quadrado.dirInf.x = 850;
    trem6->quadrado.dirInf.y = 410;

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem6,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));


    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();


}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->tremA->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->tremB->setGeometry(x,y,21,17);
        break;
    case 3:
        ui->tremC->setGeometry(x, y, 21, 17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->tremD->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->tremE->setGeometry(x,y,21,17);
        break;
    case 6:
        ui->tremF->setGeometry(x, y, 21, 17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
    trem6->terminate();
}

void MainWindow::on_slider_velocidade_trem1_valueChanged(int value){
    trem1->velocidade = ui->slider_velocidade_trem1->sliderPosition();

}

