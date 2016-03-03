#ifndef GRAPHS_ARESTA_H
#define GRAPHS_ARESTA_H


class Edge {

public:

    int verticeOrigem, verticeDestino, peso;

    Edge(int idVertice1, int idVertice2, int p);

    ~Edge();
};

#endif