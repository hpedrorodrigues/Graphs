#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <iostream>
#include <list>
#include <map>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph {

private:

    void removeVertexById(int vertexId);

public:

    Graph();

    ~Graph();

    map<int, Vertex *> Dmap;
    map<int, Vertex *>::iterator readValueDMapIterator;

    map<int, Vertex *> vertex;

    map<int, Vertex *>::iterator vertexToReadIterator;
    map<int, Vertex *>::iterator adjacentVertexToReadIterator;

    map<int, Edge *> edge;
    map<int, Edge *>::iterator edgeToReadIterator;

    int **weightBetweenEdges;

    void setWeightBetweenVertices(int originVertexId, int destinationVertexId, int weight);

    int getWeightBetweenVertices(int originVertexId, int destinationVertexId);

    Vertex *extractMinimum(Vertex *u, Vertex *s, list<int> Dlist);

    bool hasVertex(int vertexId);

    bool hasEdge(int edgeId);

    void insertEdge(int edgeId, int originVertexId, int destinationVertexId, int weight);

    void insertAdjacentVertex(int vertexId, int adjacentVertexId);

    void removeEdge(int edgeId);

    void removeAdjacentVertex(int vertexId, int adjacentVertexId);

    void insertVertex(int vertexId, int data);

    void removeVertex(int vertexId);

    void showStructure();

    void showTreeWidth();

    void showTreeDepth();

    void showTreeDepthVisit(Vertex *u, int time);

    void showShortestPath();
};


#endif