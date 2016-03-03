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
    /*Os mapas  armazenam elementos associativos formados por uma combina��o
      de um valor de chave e um valor mapeado, seguindo uma ordem espec�fica.*/
    /*Em um mapa, os valores chave s�o geralmente utilizados para classificar
     e identificar exclusivamente os elementos, enquanto que os valores
     mapeados armazenar o conte�do associado a esta chave.*/

    map<int, Vertex *> Dmap;
    map<int, Vertex *>::iterator lerVertDmap;

    //Map criado para armazenar vertices a partir de um id �nico
    map<int, Vertex *> vertice;

    //Iteratores "lerVert" e "lerVertAdjacente" criados para ler ou modificar quaisquer elementos em um map
    map<int, Vertex *>::iterator lerVert;
    map<int, Vertex *>::iterator lerVertAdjacente;

    //Map criado para armazenar arestas a partir de um id �nico
    //Iterator "lerAresta" criado para ler ou modificar qualquer elemento em um map
    map<int, Edge *> aresta;
    map<int, Edge *>::iterator lerAresta;

    int **pesoEntreArestas;

    void setPesoEntreVertices(int vOrigem, int vDestino, int peso);

    int getPesoEntreVertices(int vOrigem, int vDestino);

    Vertex *extrairMinimo(Vertex *u, Vertex *s, list<int> Dlist);

    //Verifica, a partir do id, se o v�rtice existe
    bool existeVertice(int id);

    //Verifica, a partir do id, se a aresta existe
    bool existeAresta(int id);

    //Insere aresta a partir de um id �nico v�rtice origem e destino passados
    void inserirAresta(int idAresta, int verticeOrigem, int verticeDestino, int peso);

    //Adiciona um v�rtice adjacente a partir do v�rtice origem
    void adicionarVerticeAdjacente(int idVertice, int idVerticeAdjacente);

    //Remove aresta a partir de um id �nico
    void removerAresta(int idAresta);

    //Remove um v�rtice adjacente a partir do v�rtice origem
    void removerVerticeAdjacente(int idVertice, int idVerticeAdj);

    //Inserir novo v�rtice no vetor passando id �nico e valor do v�rtice
    void inserirVertice(int idVertice, int dado);

    //Remover v�rtice do grafo a partir do id
    void removerVertice(int idVertice);

    void removerVerticeDoGrafoPorId(int idVertice);

    //Exibe a lista de adjac�ncia
    void imprimirGrafo();

    void buscaEmLargura();

    void buscaEmProfundidade();

    void buscaEmProfundidadeVisita(Vertex *u, int tempo);

    void buscaEmCaminhoMinimo();
};


#endif