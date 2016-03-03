#include "Vertex.h"

Vertex::Vertex(int data) {
    this->data = data;
    this->color = color;
    this->vertexDistance = vertexDistance;
    this->father = father;
    this->chronometer = chronometer;
};

Vertex::~Vertex() {
    this->data = 0;
    adjacentVertex.clear();
};