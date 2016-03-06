#ifndef GRAPHS_VERTEX_H
#define GRAPHS_VERTEX_H

#include <list>

using namespace std;

class Vertex {

public:

    int data, color, chronometer;
    int vertexDistance;
    Vertex *father;
    list<Vertex *> adjacentVertex;
    list<Vertex *>::iterator vertexIterator;

    Vertex(int data);

    ~Vertex();
};

#endif