#ifndef GRAPHS_VERTICE_H
#define GRAPHS_VERTICE_H

#include <list>

using namespace std;

class Vertex {

public:

    int dado, cor, cronometro;
    float distancia;
    Vertex *pai;

    //Lista criada permitindo inserir ou remover vértices
    list<Vertex *> verticeAdjacente;
    //Iterator "lerVertice" criado para ler ou modificar qualquer elemento da lista
    list<Vertex *>::iterator lerVertice;

    Vertex(int dado);

    ~Vertex();
};

#endif