#include "trem.h"
#include <QtCore>



QMutex mutex1; // Região entre A e B
QMutex mutex2; // Região entre A e C
QMutex mutex3; // Região entre B e C
QMutex mutex4; // Região entre B e D
QMutex mutex5; // Região entre B e E
QMutex mutex6; // Região entre C e E
QMutex mutex7; // Região entre C e F
QMutex mutex8; // Região entre D e E
QMutex mutex9; // Região entre E e F


//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::alterarVelocidade(int velocidadeM){
    velocidade = velocidadeM;

    mutex_pausa.lock();
    if (velocidadeM == 0) {
        pausado = true;
    } else if (pausado) {
        pausado = false;
        condicao_pausa.wakeAll();
    }
    mutex_pausa.unlock();
}

void Trem::run() {
    if (ID == 3) { mutex3.lock(); }
    if (ID == 5) { mutex8.lock(); }
    if (ID == 6) { mutex9.lock(); }

    while (true) {
        mutex_pausa.lock();
        if (pausado) {
            condicao_pausa.wait(&mutex_pausa);
        }
        mutex_pausa.unlock();

        switch(ID) {
        case 1: // Trem A (Regiões 1 e 2)
            if (x == 140 && y == 150) { mutex1.lock(); }
            else if (x == 380 && y == 170) { mutex2.lock(); mutex1.unlock(); }
            else if (x == 680 && y == 150) { mutex2.unlock(); }
            break;

        case 2: // Trem B (Regiões 1, 3, 4, 5)
            if (x == 140 && y == 280) { mutex4.lock(); }
            else if (x == 290 && y == 290) { mutex5.lock(); mutex4.unlock(); }
            else if (x == 390 && y == 290) { mutex1.lock(); mutex3.lock(); mutex5.unlock(); }
            else if (x == 390 && y == 170) { mutex3.unlock(); }
            else if (x == 140 && y == 180) { mutex1.unlock(); }
            break;

        case 3: // Trem C (Regiões 2, 3, 6, 7)
            if (x == 410 && y == 280) { mutex6.lock(); mutex3.unlock(); }
            else if (x == 560 && y == 290) { mutex7.lock(); mutex6.unlock(); }
            else if (x == 680 && y == 280) { mutex7.unlock(); }
            else if (x == 680 && y == 180) { mutex2.lock(); }
            else if (x == 430 && y == 170) { mutex3.lock(); }
            else if (x == 410 && y == 190) { mutex2.unlock(); }
            break;

        case 4: // Trem D (Regiões 4, 8)
            if (x == 300 && y == 410) { mutex8.lock(); }
            else if (x == 310 && y == 300) { mutex4.lock(); }
            else if (x == 300 && y == 290) { mutex8.unlock(); }
            else if (x == 130 && y == 290) { mutex4.unlock(); }
            break;

        case 5: // Trem E (Regiões 5, 6, 8, 9)
            if (x == 570 && y == 410) { mutex9.lock(); }
            else if (x == 580 && y == 300) { mutex5.lock(); mutex6.lock(); }
            else if (x == 570 && y == 290) { mutex9.unlock(); }
            else if (x == 420 && y == 290) { mutex8.lock(); mutex6.unlock(); }
            else if (x == 310 && y == 300) { mutex5.unlock(); }
            else if (x == 320 && y == 410) { mutex8.unlock(); }
            break;

        case 6: // Trem F (Regiões 7, 9)
            if (x == 690 && y == 290) { mutex7.lock(); }
            else if (x == 590 && y == 290) { mutex9.lock(); }
            else if (x == 580 && y == 300) { mutex7.unlock(); }
            else if (x == 590 && y == 410) { mutex9.unlock(); }
            break;
        }

        if (y == quadrado.esqSup.y && x > quadrado.esqSup.x) {
            x -= 10;
        }
        else if (x == quadrado.esqSup.x && y < quadrado.esqInf.y) {
            y += 10;
        }
        else if (y == quadrado.esqInf.y && x < quadrado.dirInf.x) {
            x += 10;
        }
        else {
            y -= 10;
        }

        emit updateGUI(ID, x, y);

        int tempo_dormir = 210 - velocidade;
        msleep(tempo_dormir);
    }
}
