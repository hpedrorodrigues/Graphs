#ifndef GRAPHS_VERTICE_H
#define GRAPHS_VERTICE_H

#include <list>

using namespace std;

class Vertex {

public:

    int data, color, chronometer;
    float vertexDistance;
    Vertex *father;
    list<Vertex *> adjacentVertex;
    list<Vertex *>::iterator vertexIterator;

    Vertex(int data);

    ~Vertex();
};

#endif