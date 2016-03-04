#ifndef GRAPHS_GRAFO_H
#define GRAPHS_GRAFO_H

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
    map<int, Vertex *>::iterator lerVertDmap;

    /**
     * Mapa criado para armazenar vértices à partir de um id único.
     */
    map<int, Vertex *> vertex;

    /**
     * Iteradores "vertexToReadIterator" e "adjacentVertexToReadIterator" foram criados para ler ou modificar quaisquer
     * elementos em um mapa.
     */
    map<int, Vertex *>::iterator vertexToReadIterator;
    map<int, Vertex *>::iterator adjacentVertexToReadIterator;

    /**
     * Mapa criado para armazenar arestas à partir de um id único.
     *
     * Iterador "edgeToReadIterator" foi criado para ler ou modificar qualquer elemento em um mapa.
     */
    map<int, Edge *> edge;
    map<int, Edge *>::iterator edgeToReadIterator;

    int **weightBetweenEdges;

    void setWeightBetweenVertices(int originVertexId, int destinationVertexId, int weight);

    int getWeightBetweenVertices(int originVertexId, int destinationVertexId);

    Vertex *extractMinimum(Vertex *u, Vertex *s, list<int> Dlist);

    bool hasVertex(int vertexId);

    bool hasEdge(int edgeId);

    void insertEdge(int edgeId, int originVertexId, int destinationVertexId, int weight);

    /**
     * Insere um vértice adjacente a partir do vértice origem.
     */
    void insertAdjacentVertex(int vertexId, int adjacentVertexId);

    void removeEdge(int idAresta);

    /**
     * Remove um vértice adjacente a partir do vértice origem.
     */
    void removeAdjacentVertex(int vertexId, int adjacentVertexId);

    /**
     * Inserir um novo vértice no vetor, passando o id único e o valor do vértice.
     */
    void insertVertex(int vertexId, int data);

    //Remover vértice do grafo a partir do id
    void removeVertex(int vertexId);

    /**
     * Exibe a lista de adjacências.
     */
    void showStructure();

    void showTreeWidth();

    void showTreeDepth();

    void showTreeDepthVisit(Vertex *u, int time);

    void showShortestPath();
};


#endif