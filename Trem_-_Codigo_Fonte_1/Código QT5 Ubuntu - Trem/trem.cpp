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

    if (velocidadeM == 0) {
        pausado = true; // Sinaliza para o trem parar
    } else if (pausado) {
        pausado = false;
        condicao_pausa.wakeAll(); // Acorda a thread imediatamente
    }
}
//Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        if(ID == 1){
            if(Ponto(x, y) == pontosCriticos[0]){
                alterarVelocidade(0); //teste para o primeiro
            }
        }
        mutex_pausa.lock();
        if (pausado) {
            condicao_pausa.wait(&mutex_pausa);
        }
        mutex_pausa.unlock();

        // --- LÓGICA DE MOVIMENTO ---
        // Seus if/else de movimento (x e y) vêm aqui
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

        emit updateGUI(ID, x, y);

        int tempo_dormir = 210 - velocidade;
        msleep(tempo_dormir);
    }
}

