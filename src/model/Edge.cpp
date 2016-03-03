#include "Edge.h"

Edge::Edge(int idVertice1, int idVertice2, int p) {
    this->verticeOrigem = idVertice1;
    this->verticeDestino = idVertice2;
    this->peso = p;
};

Edge::~Edge() {

}