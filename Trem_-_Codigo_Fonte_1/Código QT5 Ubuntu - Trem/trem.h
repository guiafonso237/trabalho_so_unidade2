#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Ponto{
public:
    int x;
    int y;
};

class Quadrado{
public:
    Ponto esqSup, esqInf, dirSup, dirInf;
};

class Trem: public QThread{
 Q_OBJECT
public:
    Quadrado quadrado;
    Trem(int,int,int);  //construtor
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;
   QMutex mutex_pausa;
   QWaitCondition condicao_pausa;
   bool pausado = false;
protected:
    void run() override;
public:
    void alterarVelocidade(int velocidadeM);
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
};

#endif // TREM_H
