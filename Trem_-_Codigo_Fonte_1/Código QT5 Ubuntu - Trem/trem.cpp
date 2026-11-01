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
    bool lock_inicial = true;
    // Variável para impedir que T2 e T5 destranquem vias que não possuem na primeira descida
    bool primeira_volta = true;

    while (true) {
        // --- 0. SPAWN INICIAL (Limpo e Direto) ---
        if (lock_inicial) {
            // T3, T5 e T6 nascem nas esquinas esquerdas dos seus quadrados e descem
            if (ID == 3) { mutex3.lock(); }
            if (ID == 5) { mutex8.lock(); }
            if (ID == 6) { mutex9.lock(); }
            lock_inicial = false;
        }

        // --- 1. BLOCO DE PAUSA DO SLIDER ---
        mutex_pausa.lock();
        if (pausado) {
            condicao_pausa.wait(&mutex_pausa);
        }
        mutex_pausa.unlock();

        // --- 2. HIERARQUIA MATEMÁTICA (Regra: n antes de n+1) ---
        switch(ID) {
        case 1: // Trem A (Sequência: 1 -> 2)
            if (x == 140 && y == 140) { mutex1.lock(); }
            else if (x == 380 && y == 170) { mutex2.lock(); mutex1.unlock(); }
            else if (x == 680 && y == 140) { mutex2.unlock(); }
            break;

        case 2: // Trem B
            if (x == 140 && y == 260) { mutex4.lock(); }
            // HIERARQUIA ATIVADA: Pede M1, M3 e M5 simultaneamente e por ordem
            else if (x == 280 && y == 290) { mutex1.lock(); mutex3.lock(); mutex5.lock(); }
            else if (x == 340 && y == 290) { mutex4.unlock(); }
            else if (x == 410 && y == 260) { mutex5.unlock(); }
            else if (x == 380 && y == 170) { mutex3.unlock(); }
            else if (x == 140 && y == 200) {
                if (primeira_volta) { primeira_volta = false; }
                else { mutex1.unlock(); }
            }
            break;

        case 3: // Trem C (Sequência natural: 2 -> 3 -> 6 -> 7)
            if (x == 680 && y == 200) { mutex2.lock(); }
            else if (x == 440 && y == 170) { mutex3.lock(); mutex2.unlock(); }
            else if (x == 410 && y == 260) { mutex6.lock(); mutex3.unlock(); }
            else if (x == 550 && y == 290) { mutex7.lock(); mutex6.unlock(); }
            else if (x == 680 && y == 260) { mutex7.unlock(); }
            break;

        case 4: // Trem D (Hierarquia: 4 -> 8)
            if (x == 280 && y == 410) { mutex4.lock(); mutex8.lock(); }
            else if (x == 280 && y == 290) { mutex8.unlock(); }
            else if (x == 110 && y == 290) { mutex4.unlock(); }
            break;

        case 5: // Trem E
            // HIERARQUIA ATIVADA: Pede M5, M6 e M9 simultaneamente e por ordem
            if (x == 550 && y == 410) { mutex5.lock(); mutex6.lock(); mutex9.lock(); }
            else if (x == 550 && y == 290) { mutex9.unlock(); }
            else if (x == 380 && y == 290) { mutex6.unlock(); }
            else if (x == 340 && y == 290) { mutex8.lock(); } // M8 pode ser pedido solto pois 5 < 8
            else if (x == 310 && y == 320) {
                if (primeira_volta) { primeira_volta = false; }
                else { mutex5.unlock(); }
            }
            else if (x == 340 && y == 410) { mutex8.unlock(); }
            break;

        case 6: // Trem F (Sequência natural: 7 -> 9)
            if (x == 850 && y == 320) { mutex7.lock(); }
            else if (x == 610 && y == 290) { mutex9.lock(); mutex7.unlock(); }
            else if (x == 580 && y == 310) { mutex9.unlock(); }
            break;
        }

        // --- 3. LÓGICA DE MOVIMENTO (Sentido Anti-horário) ---
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
