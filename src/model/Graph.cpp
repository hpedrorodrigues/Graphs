#include "Graph.h"

Graph::Graph() {
}

Graph::~Graph() {
}

void Graph::setWeightBetweenVertices(int originVertexId, int destinationVertexId, int weight) {
    this->weightBetweenEdges[originVertexId][destinationVertexId] = weight;
}

int Graph::getWeightBetweenVertices(int originVertexId, int destinationVertexId) {
    return this->weightBetweenEdges[originVertexId][destinationVertexId];
}

Vertex *Graph::extractMinimum(Vertex *u, Vertex *s, list<int> Dlist) {
    // Iterator "lerVertD" criado para receber o elemento com menor distância da lista "D"
    list<int>::iterator lerVertDlist;
    // Retorna a menor distância da lista "Dlist"
    lerVertDlist = min_element(Dlist.begin(), Dlist.end());
    int menorDistancia = *lerVertDlist;
    if (menorDistancia != 0) {
        // Retorna o vértice com a menor distância do map "Dmap"
        lerVertDmap = Dmap.find(menorDistancia);
        u = lerVertDmap->second;
        Dmap.erase(lerVertDmap);
    } else {
        u = s;
    }
    return u;
}

bool Graph::hasVertex(int vertexId) {
    bool existe = false;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber o vértice encontrado a partir do id
    vertexToReadIterator = vertex.find(vertexId);
    //Se o iterator for diferente de nulo então o vértice existe
    //.end() é o elemento após o último elemento do contido no map, ou seja, NULL
    if (vertexToReadIterator != vertex.end()) {
        existe = true;
    }
    return existe;
}

bool Graph::hasEdge(int edgeId) {
    bool existe = false;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber a aresta encontrada a partir do id
    edgeToReadIterator = edge.find(edgeId);
    //Se o iterator for diferente de nulo então a aresta existe
    //.end() é o elemento após o último elemento do contido no map, ou seja, NULL
    if (edgeToReadIterator != edge.end()) {
        existe = true;
    }
    return existe;
}

void Graph::insertEdge(int edgeId, int originVertexId, int destinationVertexId, int weight) {
    Edge *a = new Edge(originVertexId, destinationVertexId, weight);
    //Adiciona um vértice adjacente a partir do vértice origem
    insertAdjacentVertex(originVertexId, destinationVertexId);

    //Adiciona o peso na aresta entre o vértice origem e destino
    setWeightBetweenVertices(a->originVertexId, a->destinationVertexId, a->weight);

    //Armazena uma nova aresta com id único e vértices de origem e destino
    edge[edgeId] = a;
}

void Graph::insertAdjacentVertex(int vertexId, int adjacentVertexId) {
    /*.find() retorna um iterador que aponta para o local
         de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //Os iteratores devem receber os vértices encontrados a partir de seus id's
    vertexToReadIterator = vertex.find(vertexId);
    adjacentVertexToReadIterator = vertex.find(adjacentVertexId);

    //"->second" acessa o valor de referência mapeada para o elemento
    //O objeto v recebe o valor do vértice origem
    Vertex *v = vertexToReadIterator->second;

    //.push_back() Adiciona um novo elemento no final da lista, após o atual último elemento.
    //O vertice adjacente é adicionado na lista junto é referência do vértice origem
    v->adjacentVertex.push_back(adjacentVertexToReadIterator->second);
}

void Graph::removeEdge(int idAresta) {
    int idVertice1;
    int idVertice2;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber a aresta encontrada a partir do id
    edgeToReadIterator = edge.find(idAresta);
    //"->second" acessa o valor de referência mapeada para o elemento
    //As variaveis idVertice1 e idVertice2 receberam os valores dos vértices
    idVertice1 = edgeToReadIterator->second->originVertexId;
    idVertice2 = edgeToReadIterator->second->destinationVertexId;
    //Remove um vértice adjacente a partir do vértice origem
    removeAdjacentVertex(idVertice1, idVertice2);
    //.erase() Remove um elemento que corresponde a uma chave especificada.
    //A aresta é removida a partir de um id único
    edge.erase(idAresta);
}

void Graph::removeAdjacentVertex(int vertexId, int adjacentVertexId) {
    /*.find() retorna um iterador que aponta para o local
         de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //Os iteratores devem receber os vértices encontrados a partir de seus id's
    vertexToReadIterator = vertex.find(vertexId);
    adjacentVertexToReadIterator = vertex.find(adjacentVertexId);

    //"->second" acessa o valor de referência mapeada para o elemento
    //O objeto v recebe o valor do vértice origem
    Vertex *v = vertexToReadIterator->second;
    //.remove() Remove um elemento da lista a partir de um id específico
    //O vertice adjacente é removido da lista junto é referência do vértice origem
    v->adjacentVertex.remove(adjacentVertexToReadIterator->second);
}

void Graph::insertVertex(int vertexId, int data) {
    Vertex *v = new Vertex(data);
    vertex[vertexId] = v;

    //Inicializa as arestas com peso igual a 0
    weightBetweenEdges = (int **) malloc(vertex.size() * sizeof(int *));
    for (int i = 0; i < vertex.size(); i++)
        weightBetweenEdges[i] = (int *) malloc(vertex.size() * sizeof(int));

    Vertex *i, *j;
    map<int, Vertex *>::iterator i_;
    map<int, Vertex *>::iterator j_;
    for (i_ = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        for (j_ = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
            i = i_->second;
            j = j_->second;
            setWeightBetweenVertices(i->data, j->data, 0);
        }
    }
}

void Graph::removeVertex(int vertexId) {
    Edge *arst;
    for (edgeToReadIterator = edge.begin(); edgeToReadIterator != edge.end(); edgeToReadIterator++) {
        arst = edgeToReadIterator->second;
        if (arst->destinationVertexId == vertexId) {
            removeAdjacentVertex(arst->originVertexId, arst->destinationVertexId);
            removeEdge(edgeToReadIterator->first);
        }
        if (arst->originVertexId == vertexId) {
            removeEdge(edgeToReadIterator->first);
        }
    }
    removeVertexById(vertexId);
}

void Graph::removeVertexById(int vertexId) {
    Vertex *remove;
    vertexToReadIterator = vertex.find(vertexId);
    remove = vertexToReadIterator->second;
    remove->~Vertex();
    vertex.erase(vertexId);
}

void Graph::showStructure() {
    Vertex *v;
    cout << "Graph: \n\n";
    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        v = vertexToReadIterator->second;
        cout << " ";
        cout << "[";
        cout << v->data;
        cout << "]";
        Vertex *imprimirVertice;
        for (v->vertexIterator = v->adjacentVertex.begin();
             v->vertexIterator != v->adjacentVertex.end(); v->vertexIterator++) {
            imprimirVertice = *(v->vertexIterator);
            cout << " -> " << imprimirVertice->data;
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void Graph::showTreeWidth() {
    Vertex *u, *s, *v;
    list<Vertex *> Q;
    list<Vertex *>::iterator lerVertQ;
    // Pega o primeiro elemento da lista
    s = vertex.begin()->second;
    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;
        // cor = 0 (Branco) = Vértice não visitado
        u->color = 0;
        // Distância do vértice até a raiz(distância como infinito)
        u->vertexDistance = numeric_limits<float>::infinity();;
        // Pai
        u->father = NULL;
    }
    // cor = 1 (Cinza) = Vértice sendo visitado
    s->color = 1;
    s->vertexDistance = 0;
    s->father = NULL;
    // Q é uma fila
    Q.push_back(s);
    // Exibir raiz
    cout << "  " << s->data;
    cout << endl;
    while (Q.size() != 0) {
        lerVertQ = Q.begin();
        u = *lerVertQ;
        for (u->vertexIterator = u->adjacentVertex.begin();
             u->vertexIterator != u->adjacentVertex.end(); u->vertexIterator++) {
            v = *(u->vertexIterator);
            if (v->color == 0) {
                v->color = 1;
                v->vertexDistance = u->vertexDistance + 1;
                v->father = u;
                Q.push_back(v);
                //Exibir vértices adjacentes
                cout << "  " << v->data << " - ";
            }
        }
        cout << endl;
        // Remove o primeiro elemento da lista atual
        Q.pop_front();
        // cor = 2 (Preto) = Vértice visitado
        u->color = 2;
    };
}

void Graph::showTreeDepth() {
    Vertex *u, *s;
    // Pega o primeiro elemento da lista
    s = vertex.begin()->second;
    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;
        // cor = 0 (Branco) = Vértice não visitado
        u->color = 0;
        // Pai
        u->father = NULL;
    }
    int tempo = 0;
    // Exibir raiz
    cout << "  " << s->data << " -> ";
    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;
        // cor = 0 (Branco) = Vértice não visitado
        if (u->color == 0)
            showTreeDepthVisit(u, tempo);
    }
}

void Graph::showTreeDepthVisit(Vertex *u, int time) {
    Vertex *v;
    // cor = 1 (Cinza) = Vértice sendo visitado
    u->color = 1;
    time++;
    // Distância do vértice até a raiz
    u->vertexDistance = time;
    for (u->vertexIterator = u->adjacentVertex.begin();
         u->vertexIterator != u->adjacentVertex.end(); u->vertexIterator++) {
        v = *(u->vertexIterator);
        if (v->color == 0) {
            v->father = u;
            //Exibir vértices adjacentes
            cout << "  " << v->data << " -> ";
            showTreeDepthVisit(v, time);
        }
    }
    cout << endl;
    // cor = 2 (Preto) = Vértice visitado
    u->color = 2;
    time++;
    // cronometro guarda todos os intervalos de tempo
    u->chronometer = time;
}

void Graph::showShortestPath() {
    Vertex *v, *s, *u;
    // Lista "S" criada para guardar vértices visitados
    // Lista "Q" criada para guardar vértices não visitados
    // Lista "Dlist" criada para guardar a distância dos vértices
    list<Vertex *> S, Q;
    list<int> Dlist;

    // Iterator "lerVertS" criado para exibir os valores dos vértices visitados
    list<Vertex *>::iterator lerVertS, lerVertQ;
    bool execUnicaVez = true;
    // Pega o primeiro elemento da lista(raiz)
    s = vertex.begin()->second;
    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        v = vertexToReadIterator->second;
        // Defini a distância de todos os vértices como infinito
        v->vertexDistance = numeric_limits<float>::infinity();
        // Defini a pai de todos os vértices como nulo
        v->father = NULL;
        Q.push_back(v);
    }
    s->vertexDistance = 0;
    Dlist.push_back(s->vertexDistance);
    while (Q.size() != 0) {
        //Extrai o elemento com menor distância
        u = extractMinimum(u, s, Dlist);

        S.push_back(u);
        for (u->vertexIterator = u->adjacentVertex.begin();
             u->vertexIterator != u->adjacentVertex.end(); u->vertexIterator++) {
            v = *(u->vertexIterator);
            if (v->vertexDistance > (u->vertexDistance + getWeightBetweenVertices(u->data, v->data))) {
                v->vertexDistance = (u->vertexDistance + getWeightBetweenVertices(u->data, v->data));
                v->father = u;
            }
            Dlist.push_back(v->vertexDistance);
            Dmap[v->vertexDistance] = v;
        }

        // Montando tabela com distância(d), pai(P) de cada vértice e ordem de visita(S)
        if (execUnicaVez) {
            cout << "     ";
            list<string> a;
            a.push_back("d");
            a.push_back("P");
            a.push_back("S");
            list<string>::iterator a_;
            for (a_ = a.begin(); a_ != a.end(); a_++) {
                string b = *a_;
                cout << b << "  ";
            }
            cout << endl;
            execUnicaVez = false;
        }
        for (lerVertS = S.begin(); lerVertS != S.end(); lerVertS++) {
            Vertex *visitado = *lerVertS;
            if (visitado->father != NULL) {
                cout << "  " << visitado->data << "  " << visitado->vertexDistance << "  " << visitado->father->data <<
                "  " << visitado->data;
            } else {
                cout << "  " << visitado->data << "  " << visitado->vertexDistance << "  " << "N" << "  " <<
                visitado->data;
            }
        }
        cout << "\n\n";

        // Remove da lista a distância do atual vértice visitado
        Dlist.remove(u->vertexDistance);
        // Remove o primeiro elemento das listas "S" e "Q"
        S.pop_front();
        Q.pop_front();
    };
}