#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <vector>


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
    Ponto(){}
    Ponto(int x_, int y_){
        this->x = x_;
        this->y = y_;
    }
    bool operator==(const Ponto& outro) const{
        return ((outro.x == this->x) && (outro.y == this->y));
    }
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
    void static pararTrem(int id);
    void alterarVelocidade(int velocidadeM);
   int velocidade;
    std::vector<Ponto> pontosCriticos;
};

#endif // TREM_H
