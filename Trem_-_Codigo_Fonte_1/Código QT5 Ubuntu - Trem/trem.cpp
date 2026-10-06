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
        switch(ID){
        case 1:     //Trem 1 caso esteja na direita superior
            if (y == 170 && x > 140)
                x-=10;
            else if (x == 140 && y < 290)
                y+=10;
            else if (x < 410 && y == 290)
                x+=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2:     //Trem 2 caso esteja na direita superior
            if (y == 170 && x > 410)
                x-=10;
            else if (x == 410 && y < 290) //esqSup
                y+=10;
            else if (x < 680 && y == 290)
                x+=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 50 && x > 140)
                x-=10;
            else if (x == 140 && y < 170) //esqSup
                y+=10;
            else if (x < 680 && y == 170)
                x+=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




