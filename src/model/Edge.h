#ifndef GRAPHS_EDGE_H
#define GRAPHS_EDGE_H


class Edge {

public:

    int originVertexId, destinationVertexId, weight;

    Edge(int originVertexId, int destinationVertexId, int weight);

    ~Edge();
};

#endif