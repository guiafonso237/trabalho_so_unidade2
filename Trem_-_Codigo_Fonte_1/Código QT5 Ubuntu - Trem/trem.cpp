#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        // Linha superior: move para a esquerda
        if (y == quadrado.esqSup.y && x > quadrado.esqSup.x) {
            x -= 10;
        }
        // Linha esquerda: move para baixo
        else if (x == quadrado.esqSup.x && y < quadrado.esqInf.y) {
            y += 10;
        }
        // Linha inferior: move para a direita
        else if (y == quadrado.esqInf.y && x < quadrado.dirInf.x) {
            x += 10;
        }
        // Linha direita: move para cima
        else {
            y -= 10;
        }

        // Emite o sinal com o ID próprio deste trem para atualizar a interface gráfica
        emit updateGUI(ID, x, y);
        if(velocidade == 200){
            msleep(100000);
        }else{
            msleep(velocidade);
        }

    }
}




