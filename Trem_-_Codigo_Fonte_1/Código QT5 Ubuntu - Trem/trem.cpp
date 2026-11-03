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

    while (true) {
        // --- 0. SPAWN INICIAL: mutexes dos cantos onde o trem nasce (ordem crescente) ---
        if (lock_inicial) {
            switch (ID) {
            case 2: mutex1.lock(); break;                    // B nasce em (140,170): canto da região 1
            case 3: mutex2.lock(); mutex3.lock(); break;     // C nasce em (410,170): cruzamento das regiões 2 e 3
            case 5: mutex5.lock(); mutex8.lock(); break;     // E nasce em (310,290): cantos das regiões 5 e 8
            case 6: mutex7.lock(); mutex9.lock(); break;     // F nasce em (580,290): cantos das regiões 7 e 9
            }
            lock_inicial = false;
        }

        // --- 1. BLOCO DE PAUSA DO SLIDER ---
        mutex_pausa.lock();
        while (pausado) {
            condicao_pausa.wait(&mutex_pausa);
        }
        mutex_pausa.unlock();

        // --- 2. CONTROLE DAS REGIÕES CRÍTICAS ---
        // lock: 30px antes de entrar | unlock: 30px depois de sair
        switch(ID) {
        case 1: // Trem A (1 -> 2)
            if      (x == 140 && y == 140) { mutex1.lock(); }
            else if (x == 380 && y == 170) { mutex2.lock(); }    // pega M2 ainda segurando M1
            else if (x == 440 && y == 170) { mutex1.unlock(); }  // saiu da região 1 (vai até x=410)
            else if (x == 680 && y == 140) { mutex2.unlock(); }
            break;

        case 2: // Trem B (nasce com M1)
            if      (x == 140 && y == 200) { mutex1.unlock(); }  // saiu do canto (140,170)
            else if (x == 140 && y == 260) { mutex4.lock(); }
            // Hierarquia: pede M1, M3 e M5 juntos e em ordem crescente
            else if (x == 280 && y == 290) { mutex1.lock(); mutex3.lock(); mutex5.lock(); }
            else if (x == 340 && y == 290) { mutex4.unlock(); }
            else if (x == 410 && y == 260) { mutex5.unlock(); }
            else if (x == 380 && y == 170) { mutex3.unlock(); }
            break;

        case 3: // Trem C (nasce com M2 e M3) (2 -> 3 -> 6 -> 7)
            if      (x == 410 && y == 200) { mutex2.unlock(); }  // saiu do canto (410,170)
            else if (x == 410 && y == 260) { mutex6.lock(); }    // pega M6 ainda segurando M3
            else if (x == 440 && y == 290) { mutex3.unlock(); }  // saiu do canto (410,290)
            else if (x == 550 && y == 290) { mutex7.lock(); }    // pega M7 ainda segurando M6
            else if (x == 610 && y == 290) { mutex6.unlock(); }  // saiu da região 6 (vai até x=580)
            else if (x == 680 && y == 260) { mutex7.unlock(); }
            else if (x == 680 && y == 200) { mutex2.lock(); }
            else if (x == 440 && y == 170) { mutex3.lock(); }    // pega M3 ainda segurando M2
            break;

        case 4: // Trem D (4 -> 8)
            if      (x == 280 && y == 410) { mutex4.lock(); mutex8.lock(); }
            else if (x == 280 && y == 290) { mutex8.unlock(); }
            else if (x == 110 && y == 290) { mutex4.unlock(); }
            break;

        case 5: // Trem E (nasce com M5 e M8)
            if      (x == 310 && y == 320) { mutex5.unlock(); }
            else if (x == 340 && y == 410) { mutex8.unlock(); }
            // Hierarquia: pede M5, M6 e M9 juntos e em ordem crescente
            else if (x == 550 && y == 410) { mutex5.lock(); mutex6.lock(); mutex9.lock(); }
            else if (x == 550 && y == 290) { mutex9.unlock(); }
            else if (x == 380 && y == 290) { mutex6.unlock(); }
            else if (x == 340 && y == 290) { mutex8.lock(); }    // segura M5, então 5 < 8
            break;

        case 6: // Trem F (nasce com M7 e M9) (7 -> 9)
            if      (x == 580 && y == 320) { mutex7.unlock(); }  // saiu do canto (580,290)
            else if (x == 610 && y == 410) { mutex9.unlock(); }  // saiu do canto (580,410)
            else if (x == 850 && y == 320) { mutex7.lock(); }
            else if (x == 610 && y == 290) { mutex9.lock(); }    // pega M9 ainda segurando M7
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