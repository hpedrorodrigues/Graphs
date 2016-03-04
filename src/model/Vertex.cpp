#include "Vertex.h"

Vertex::Vertex(int data) {
    this->data = data;
};

Vertex::~Vertex() {
    this->data = 0;
    adjacentVertex.clear();
};