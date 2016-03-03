#ifndef GRAPHS_ARESTA_H
#define GRAPHS_ARESTA_H


class Edge {

public:

    int originVertexId, destinationVertexId, weight;

    Edge(int originVertexId, int destinationVertexId, int weight);

    ~Edge();
};

#endif