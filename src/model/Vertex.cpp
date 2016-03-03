#include "Vertex.h"

Vertex::Vertex(int dado) {
    this->dado = dado;
    this->cor = cor;
    this->distancia = distancia;
    this->pai = pai;
    this->cronometro = cronometro;
};

Vertex::~Vertex() {
    this->dado = 0;
    verticeAdjacente.clear();
};