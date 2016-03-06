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
    list<int>::iterator readValueDListIterator = min_element(Dlist.begin(), Dlist.end());
    int minDistance = *readValueDListIterator;

    if (minDistance != 0) {
        readValueDMapIterator = Dmap.find(minDistance);

        u = readValueDMapIterator->second;

        Dmap.erase(readValueDMapIterator);

    } else {

        u = s;
    }

    return u;
}

bool Graph::hasVertex(int vertexId) {
    bool hasVertex = false;

    /**
     * .find() retorna um iterador que aponta para o local de um elemento em um mapa com uma chave
     * igual a uma chave especificada.
     *
     * O iterator deve receber o vértice encontrado a partir do id
     */
    vertexToReadIterator = vertex.find(vertexId);

    /**
     * Se o iterator for diferente de nulo então o vértice existe.
     * .end() é o elemento após o último elemento do contido no map, ou seja, NULL.
     */
    if (vertexToReadIterator != vertex.end()) {
        hasVertex = true;
    }

    return hasVertex;
}

bool Graph::hasEdge(int edgeId) {
    bool hasEdge = false;

    /**
     * .find() retorna um iterador que aponta para o local de um elemento em um mapa com uma chave
     * igual a uma chave especificada.
     *
     * O iterator deve receber o vértice encontrado a partir do id
     */
    edgeToReadIterator = edge.find(edgeId);

    /**
     * Se o iterator for diferente de nulo então o vértice existe.
     * .end() é o elemento após o último elemento do contido no map, ou seja, NULL.
     */
    if (edgeToReadIterator != edge.end()) {
        hasEdge = true;
    }

    return hasEdge;
}

void Graph::insertEdge(int edgeId, int originVertexId, int destinationVertexId, int weight) {

    Edge *edgeToInsert = new Edge(originVertexId, destinationVertexId, weight);

    /**
     * Adiciona um vértice adjacente a partir do vértice de origem
     */
    insertAdjacentVertex(originVertexId, destinationVertexId);

    /**
     * Adiciona o peso na aresta entre o vértice origem e destino
     */
    setWeightBetweenVertices(edgeToInsert->originVertexId, edgeToInsert->destinationVertexId, edgeToInsert->weight);

    /**
     * Armazena uma nova aresta com id único e vértices de origem e destino
     */
    edge[edgeId] = edgeToInsert;
}

void Graph::insertAdjacentVertex(int vertexId, int adjacentVertexId) {
    /**
     * .find() retorna um iterador que aponta para o local
     * de um elemento em um mapa com uma chave igual a uma chave especificada
     *
     * Os iteratores devem receber os vértices encontrados a partir de seus id's
     */
    vertexToReadIterator = vertex.find(vertexId);
    adjacentVertexToReadIterator = vertex.find(adjacentVertexId);

    /**
     * "->second" acessa o valor de referência mapeada para o elemento
     */
    Vertex *originVertex = vertexToReadIterator->second;

    /**
     * .push_back() Adiciona um novo elemento no final da lista, após o atual último elemento.
     *
     * O vertice adjacente é adicionado na lista junto é referência do vértice origem
     */
    originVertex->adjacentVertex.push_back(adjacentVertexToReadIterator->second);
}

void Graph::removeEdge(int edgeId) {
    int vertexId1, vertexId2;

    /**
     * .find() retorna um iterador que aponta para o local
     * de um elemento em um mapa com uma chave igual a uma chave especificada
     *
     * O iterator deve receber a aresta encontrada a partir do id
     */
    edgeToReadIterator = edge.find(edgeId);

    /**
     * "->second" acessa o valor de referência mapeada para o elemento
     *
     * As variaveis vertexId1 e vertexId2 receberam os valores dos vértices
     */
    vertexId1 = edgeToReadIterator->second->originVertexId;
    vertexId2 = edgeToReadIterator->second->destinationVertexId;

    /**
     * Remove um vértice adjacente a partir do vértice origem
     */
    removeAdjacentVertex(vertexId1, vertexId2);

    /**
     * .erase() Remove um elemento que corresponde a uma chave especificada.
     * A aresta é removida a partir de um id único
     */
    edge.erase(edgeId);
}

void Graph::removeAdjacentVertex(int vertexId, int adjacentVertexId) {
    /**
     * .find() retorna um iterador que aponta para o local
     * de um elemento em um mapa com uma chave igual a uma chave especificada
     *
     * Os iteratores devem receber os vértices encontrados a partir de seus id's
     */
    vertexToReadIterator = vertex.find(vertexId);
    adjacentVertexToReadIterator = vertex.find(adjacentVertexId);

    /**
     * "->second" acessa o valor de referência mapeada para o elemento
     */
    Vertex *originVertex = vertexToReadIterator->second;

    /**
     * .remove() Remove um elemento da lista a partir de um id específico
     *
     * O vertice adjacente é removido da lista junto é referência do vértice origem
     */
    originVertex->adjacentVertex.remove(adjacentVertexToReadIterator->second);
}

void Graph::insertVertex(int vertexId, int data) {
    Vertex *vertexToInsert = new Vertex(data);
    vertex[vertexId] = vertexToInsert;

    /**
     * Inicializa as arestas com peso igual a 0
     */
    weightBetweenEdges = new int *[vertex.size()];
    for (int i = 0; i < vertex.size(); i++) {
        weightBetweenEdges[i] = new int[vertex.size()];
    }

    Vertex *i, *j;

    for (map<int, Vertex *>::iterator i_ = vertex.begin();
         vertexToReadIterator != vertex.end(); vertexToReadIterator++) {

        for (map<int, Vertex *>::iterator j_ = vertex.begin();
             vertexToReadIterator != vertex.end(); vertexToReadIterator++) {

            i = i_->second;
            j = j_->second;

            setWeightBetweenVertices(i->data, j->data, 0);
        }
    }
}

void Graph::removeVertex(int vertexId) {
    Edge *edgeToRemove;

    for (edgeToReadIterator = edge.begin(); edgeToReadIterator != edge.end(); edgeToReadIterator++) {

        edgeToRemove = edgeToReadIterator->second;

        if (edgeToRemove->destinationVertexId == vertexId) {

            removeAdjacentVertex(edgeToRemove->originVertexId, edgeToRemove->destinationVertexId);
            removeEdge(edgeToReadIterator->first);
        }

        if (edgeToRemove->originVertexId == vertexId) {

            removeEdge(edgeToReadIterator->first);
        }
    }

    removeVertexById(vertexId);
}

void Graph::removeVertexById(int vertexId) {
    Vertex *vertexToRemove;

    vertexToReadIterator = vertex.find(vertexId);

    vertexToRemove = vertexToReadIterator->second;

    vertexToRemove->~Vertex();

    vertex.erase(vertexId);
}

void Graph::showStructure() {
    Vertex *vertexToShow, *vertexToShow2;

    cout << "Graph: \n\n";

    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {

        vertexToShow = vertexToReadIterator->second;

        cout << " ";
        cout << "[";
        cout << vertexToShow->data;
        cout << "]";

        for (vertexToShow->vertexIterator = vertexToShow->adjacentVertex.begin();
             vertexToShow->vertexIterator != vertexToShow->adjacentVertex.end(); vertexToShow->vertexIterator++) {

            vertexToShow2 = *(vertexToShow->vertexIterator);
            cout << " -> " << vertexToShow2->data;
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

    /**
     * Pega o primeiro elemento da lista
     */
    s = vertex.begin()->second;


    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;

        /**
         * cor = 0 (Branco) = Vértice não visitado
         */
        u->color = 0;

        /**
         * Distância do vértice até a raiz(distância como infinito)
         */
        u->vertexDistance = numeric_limits<int>::infinity();

        /**
         * Pai
         */
        u->father = NULL;
    }

    /**
     * cor = 1 (Cinza) = Vértice sendo visitado
     */
    s->color = 1;
    s->vertexDistance = 0;
    s->father = NULL;

    /**
     * Q é uma fila
     */
    Q.push_back(s);

    /**
     * Exibir raiz
     */
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

                /**
                 * Exibir vértices adjacentes
                 */
                cout << "  " << v->data << " - ";
            }
        }

        cout << endl;

        /**
         * Remove o primeiro elemento da lista atual
         */
        Q.pop_front();

        /**
         * cor = 2 (Preto) = Vértice visitado
         */
        u->color = 2;
    };
}

void Graph::showTreeDepth() {
    Vertex *u, *s;

    /**
     * Pega o primeiro elemento da lista
     */
    s = vertex.begin()->second;

    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;

        /**
         * cor = 0 (Branco) = Vértice não visitado
         */
        u->color = 0;

        /**
         * Pai
         */
        u->father = NULL;
    }

    int time = 0;

    /**
     * Exibir raiz
     */
    cout << "  " << s->data << " -> ";

    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        u = vertexToReadIterator->second;

        /**
         * cor = 0 (Branco) = Vértice não visitado
         */
        if (u->color == 0) {
            showTreeDepthVisit(u, time);
        }
    }
}

void Graph::showTreeDepthVisit(Vertex *u, int time) {
    Vertex *v;

    /**
     * cor = 1 (Cinza) = Vértice sendo visitado
     */
    u->color = 1;
    time++;

    /**
     * Distância do vértice até a raiz
     */
    u->vertexDistance = time;

    for (u->vertexIterator = u->adjacentVertex.begin();
         u->vertexIterator != u->adjacentVertex.end(); u->vertexIterator++) {

        v = *(u->vertexIterator);

        if (v->color == 0) {
            v->father = u;

            /**
             * Exibir vértices adjacentes
             */
            cout << "  " << v->data << " -> ";
            showTreeDepthVisit(v, time);
        }
    }

    cout << endl;

    /**
     * cor = 2 (Preto) = Vértice visitado
     */
    u->color = 2;
    time++;

    /**
     * cronometro guarda todos os intervalos de tempo
     */
    u->chronometer = time;
}

void Graph::showShortestPath() {
    Vertex *v, *s, *u;

    /**
     * Lista "S" criada para guardar vértices visitados
     * Lista "Q" criada para guardar vértices não visitados
     * Lista "Dlist" criada para guardar a distância dos vértices
     */
    list<Vertex *> S, Q;
    list<int> Dlist;

    /**
     * Iterator "lerVertS" criado para exibir os valores dos vértices visitados
     */
    list<Vertex *>::iterator lerVertS;

    bool wasExecuted = true;

    /**
     * Pega o primeiro elemento da lista(raiz)
     */
    s = vertex.begin()->second;

    for (vertexToReadIterator = vertex.begin(); vertexToReadIterator != vertex.end(); vertexToReadIterator++) {
        v = vertexToReadIterator->second;

        /**
         * Define a distância de todos os vértices como infinito
         */
        v->vertexDistance = numeric_limits<int>::infinity();

        /**
         * Define o pai de todos os vértices como nulo
         */
        v->father = NULL;

        Q.push_back(v);
    }

    s->vertexDistance = 0;

    Dlist.push_back(s->vertexDistance);

    while (Q.size() != 0) {
        /**
         * Extrai o elemento com menor distância
         */
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

        /**
         * Montando tabela com distância(d), pai(P) de cada vértice e ordem de visita(S)
         */
        if (wasExecuted) {

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

            wasExecuted = false;
        }

        for (lerVertS = S.begin(); lerVertS != S.end(); lerVertS++) {
            Vertex *visited = *lerVertS;

            if (visited->father != NULL) {

                cout << "  " << visited->data <<
                "  " << visited->vertexDistance <<
                "  " << visited->father->data <<
                "  " << visited->data;
            } else {

                cout << "  " << visited->data <<
                "  " << visited->vertexDistance <<
                "  " << "N" <<
                "  " << visited->data;
            }
        }
        cout << "\n\n";

        /**
         * Remove da lista a distância do atual vértice visitado
         */
        Dlist.remove(u->vertexDistance);

        /**
         * Remove o primeiro elemento das listas "S" e "Q"
         */
        S.pop_front();
        Q.pop_front();
    };
}