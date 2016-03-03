#ifndef GRAPHS_GRAFO_H
#define GRAPHS_GRAFO_H

#include <iostream>
#include <list>
#include <map>

#include "Vertex.h"
#include "Edge.h"

using namespace std;

class Graph {

public:
    /*Os mapas  armazenam elementos associativos formados por uma combinação
      de um valor de chave e um valor mapeado, seguindo uma ordem específica.*/
    /*Em um mapa, os valores chave são geralmente utilizados para classificar
     e identificar exclusivamente os elementos, enquanto que os valores
     mapeados armazenar o conteúdo associado a esta chave.*/

    map<int, Vertex *> Dmap;
    map<int, Vertex *>::iterator lerVertDmap;

    //Map criado para armazenar vertices a partir de um id único
    map<int, Vertex *> vertex;

    //Iteratores "lerVert" e "lerVertAdjacente" criados para ler ou modificar quaisquer elementos em um map
    map<int, Vertex *>::iterator vertexToReadIterator;
    map<int, Vertex *>::iterator adjacentVertexToReadIterator;

    //Map criado para armazenar arestas a partir de um id único
    //Iterator "lerAresta" criado para ler ou modificar qualquer elemento em um map
    map<int, Edge *> edge;
    map<int, Edge *>::iterator edgeToReadIterator;

    int **weightBetweenEdges;

    void setPesoEntreVertices(int originVertexId, int destinationVertexId, int weight);

    int getPesoEntreVertices(int originVertexId, int destinationVertexId);

    Vertex *extrairMinimo(Vertex *u, Vertex *s, list<int> Dlist);

    //Verifica, a partir do id, se o vértice existe
    bool existeVertice(int vertexId);

    //Verifica, a partir do id, se a aresta existe
    bool existeAresta(int edgeId);

    //Insere aresta a partir de um id único vértice origem e destino passados
    void inserirAresta(int edgeId, int originVertexId, int destinationVertexId, int weight);

    //Adiciona um vértice adjacente a partir do vértice origem
    void adicionarVerticeAdjacente(int idVertice, int idVerticeAdjacente);

    //Remove aresta a partir de um id único
    void removerAresta(int idAresta);

    //Remove um vértice adjacente a partir do vértice origem
    void removerVerticeAdjacente(int idVertice, int idVerticeAdj);

    //Inserir novo vértice no vetor passando id único e valor do vértice
    void inserirVertice(int idVertice, int dado);

    //Remover vértice do grafo a partir do id
    void removerVertice(int idVertice);

    void removerVerticeDoGrafoPorId(int idVertice);

    //Exibe a lista de adjacência
    void imprimirGrafo();

    void buscaEmLargura();

    void buscaEmProfundidade();

    void buscaEmProfundidadeVisita(Vertex *u, int tempo);

    void buscaEmCaminhoMinimo();
};


#endif