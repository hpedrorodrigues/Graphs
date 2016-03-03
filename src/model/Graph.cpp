#include "Graph.h"

void Graph::setPesoEntreVertices(int vOrigem, int vDestino, int peso) {
    this->pesoEntreArestas[vOrigem][vDestino] = peso;
}

int Graph::getPesoEntreVertices(int vOrigem, int vDestino) {
    return this->pesoEntreArestas[vOrigem][vDestino];
}

Vertex *Graph::extrairMinimo(Vertex *u, Vertex *s, list<int> Dlist) {
    // Iterator "lerVertD" criado para receber o elemento com menor dist�ncia da lista "D"
    list<int>::iterator lerVertDlist;
    // Retorna a menor dist�ncia da lista "Dlist"
    lerVertDlist = min_element(Dlist.begin(), Dlist.end());
    int menorDistancia = *lerVertDlist;
    if (menorDistancia != 0) {
        // Retorna o v�rtice com a menor dist�ncia do map "Dmap"
        lerVertDmap = Dmap.find(menorDistancia);
        u = lerVertDmap->second;
        Dmap.erase(lerVertDmap);
    } else {
        u = s;
    }
    return u;
}

bool Graph::existeVertice(int id) {
    bool existe = false;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber o v�rtice encontrado a partir do id
    lerVert = vertice.find(id);
    //Se o iterator for diferente de nulo ent�o o v�rtice existe
    //.end() � o elemento ap�s o �ltimo elemento do contido no map, ou seja, NULL
    if (lerVert != vertice.end()) {
        existe = true;
    }
    return existe;
}

bool Graph::existeAresta(int id) {
    bool existe = false;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber a aresta encontrada a partir do id
    lerAresta = aresta.find(id);
    //Se o iterator for diferente de nulo ent�o a aresta existe
    //.end() � o elemento ap�s o �ltimo elemento do contido no map, ou seja, NULL
    if (lerAresta != aresta.end()) {
        existe = true;
    }
    return existe;
}

void Graph::inserirAresta(int idAresta, int verticeOrigem, int verticeDestino, int peso) {
    Edge *a = new Edge(verticeOrigem, verticeDestino, peso);
    //Adiciona um v�rtice adjacente a partir do v�rtice origem
    adicionarVerticeAdjacente(verticeOrigem, verticeDestino);

    //Adiciona o peso na aresta entre o v�rtice origem e destino
    setPesoEntreVertices(a->verticeOrigem, a->verticeDestino, a->peso);

    //Armazena uam nova aresta com id �nico e v�rtices de origem e destino
    aresta[idAresta] = a;
}

void Graph::adicionarVerticeAdjacente(int idVertice, int idVerticeAdjacente) {
    /*.find() retorna um iterador que aponta para o local
         de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //Os iteratores devem receber os v�rtices encontrados a partir de seus id's
    lerVert = vertice.find(idVertice);
    lerVertAdjacente = vertice.find(idVerticeAdjacente);

    //"->second" acessa o valor de refer�ncia mapeada para o elemento
    //O objeto v recebe o valor do v�rtice origem
    Vertex *v = lerVert->second;

    //.push_back() Adiciona um novo elemento no final da lista, ap�s o atual �ltimo elemento.
    //O vertice adjacente � adicionado na lista junto � refer�ncia do v�rtice origem
    v->verticeAdjacente.push_back(lerVertAdjacente->second);
}

void Graph::removerAresta(int idAresta) {
    int idVertice1;
    int idVertice2;
    /*.find() retorna um iterador que aponta para o local
     de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //O iterator deve receber a aresta encontrada a partir do id
    lerAresta = aresta.find(idAresta);
    //"->second" acessa o valor de refer�ncia mapeada para o elemento
    //As variaveis idVertice1 e idVertice2 receberam os valores dos v�rtices
    idVertice1 = lerAresta->second->verticeOrigem;
    idVertice2 = lerAresta->second->verticeDestino;
    //Remove um v�rtice adjacente a partir do v�rtice origem
    removerVerticeAdjacente(idVertice1, idVertice2);
    //.erase() Remove um elemento que corresponde a uma chave especificada.
    //A aresta � removida a partir de um id �nico
    aresta.erase(idAresta);
}

void Graph::removerVerticeAdjacente(int idVertice, int idVerticeAdj) {
    /*.find() retorna um iterador que aponta para o local
         de um elemento em um mapa com uma chave igual a uma chave especificada*/
    //Os iteratores devem receber os v�rtices encontrados a partir de seus id's
    lerVert = vertice.find(idVertice);
    lerVertAdjacente = vertice.find(idVerticeAdj);

    //"->second" acessa o valor de refer�ncia mapeada para o elemento
    //O objeto v recebe o valor do v�rtice origem
    Vertex *v = lerVert->second;
    //.remove() Remove um elemento da lista a partir de um id espec�fico
    //O vertice adjacente � removido da lista junto � refer�ncia do v�rtice origem
    v->verticeAdjacente.remove(lerVertAdjacente->second);
}

void Graph::inserirVertice(int idVertice, int dado) {
    Vertex *v = new Vertex(dado);
    vertice[idVertice] = v;

    //Inicializa as arestas com peso igual a 0
    pesoEntreArestas = (int **) malloc(vertice.size() * sizeof(int *));
    for (int i = 0; i < vertice.size(); i++)
        pesoEntreArestas[i] = (int *) malloc(vertice.size() * sizeof(int));

    Vertex *i, *j;
    map<int, Vertex *>::iterator i_;
    map<int, Vertex *>::iterator j_;
    for (i_ = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        for (j_ = vertice.begin(); lerVert != vertice.end(); lerVert++) {
            i = i_->second;
            j = j_->second;
            setPesoEntreVertices(i->dado, j->dado, 0);
        }
    }
}

void Graph::removerVertice(int idVertice) {
    Edge *arst;
    for (lerAresta = aresta.begin(); lerAresta != aresta.end(); lerAresta++) {
        arst = lerAresta->second;
        if (arst->verticeDestino == idVertice) {
            removerVerticeAdjacente(arst->verticeOrigem, arst->verticeDestino);
            removerAresta(lerAresta->first);
        }
        if (arst->verticeOrigem == idVertice) {
            removerAresta(lerAresta->first);
        }
    }
    removerVerticeDoGrafoPorId(idVertice);
}

void Graph::removerVerticeDoGrafoPorId(int idVertice) {
    Vertex *remove;
    lerVert = vertice.find(idVertice);
    remove = lerVert->second;
    remove->~Vertex();
    vertice.erase(idVertice);
}

void Graph::imprimirGrafo() {
    Vertex *v;
    cout << "Graph: \n\n";
    for (lerVert = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        v = lerVert->second;
        cout << " ";
        cout << "[";
        cout << v->dado;
        cout << "]";
        Vertex *imprimirVertice;
        for (v->lerVertice = v->verticeAdjacente.begin();
             v->lerVertice != v->verticeAdjacente.end(); v->lerVertice++) {
            imprimirVertice = *(v->lerVertice);
            cout << " -> " << imprimirVertice->dado;
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void Graph::buscaEmLargura() {
    Vertex *u, *s, *v;
    list<Vertex *> Q;
    list<Vertex *>::iterator lerVertQ;
    // Pega o primeiro elemento da lista
    s = vertice.begin()->second;
    for (lerVert = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        u = lerVert->second;
        // cor = 0 (Branco) = V�rtice n�o visitado
        u->cor = 0;
        // Dist�ncia do v�rtice at� a raiz(dist�ncia como infinito)
        u->distancia = numeric_limits<float>::infinity();;
        // Pai
        u->pai = NULL;
    }
    // cor = 1 (Cinza) = V�rtice sendo visitado
    s->cor = 1;
    s->distancia = 0;
    s->pai = NULL;
    // Q � uma fila
    Q.push_back(s);
    // Exibir raiz
    cout << "  " << s->dado;
    cout << endl;
    while (Q.size() != 0) {
        lerVertQ = Q.begin();
        u = *lerVertQ;
        for (u->lerVertice = u->verticeAdjacente.begin();
             u->lerVertice != u->verticeAdjacente.end(); u->lerVertice++) {
            v = *(u->lerVertice);
            if (v->cor == 0) {
                v->cor = 1;
                v->distancia = u->distancia + 1;
                v->pai = u;
                Q.push_back(v);
                //Exibir v�rtices adjacentes
                cout << "  " << v->dado << " - ";
            }
        }
        cout << endl;
        // Remove o primeiro elemento da lista atual
        Q.pop_front();
        // cor = 2 (Preto) = V�rtice visitado
        u->cor = 2;
    };
}

void Graph::buscaEmProfundidade() {
    Vertex *u, *s;
    // Pega o primeiro elemento da lista
    s = vertice.begin()->second;
    for (lerVert = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        u = lerVert->second;
        // cor = 0 (Branco) = V�rtice n�o visitado
        u->cor = 0;
        // Pai
        u->pai = NULL;
    }
    int tempo = 0;
    // Exibir raiz
    cout << "  " << s->dado << " -> ";
    for (lerVert = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        u = lerVert->second;
        // cor = 0 (Branco) = V�rtice n�o visitado
        if (u->cor == 0)
            buscaEmProfundidadeVisita(u, tempo);
    }
}

void Graph::buscaEmProfundidadeVisita(Vertex *u, int tempo) {
    Vertex *v;
    // cor = 1 (Cinza) = V�rtice sendo visitado
    u->cor = 1;
    tempo++;
    // Dist�ncia do v�rtice at� a raiz
    u->distancia = tempo;
    for (u->lerVertice = u->verticeAdjacente.begin(); u->lerVertice != u->verticeAdjacente.end(); u->lerVertice++) {
        v = *(u->lerVertice);
        if (v->cor == 0) {
            v->pai = u;
            //Exibir v�rtices adjacentes
            cout << "  " << v->dado << " -> ";
            buscaEmProfundidadeVisita(v, tempo);
        }
    }
    cout << endl;
    // cor = 2 (Preto) = V�rtice visitado
    u->cor = 2;
    tempo++;
    // cronometro guarda todos os intervalos de tempo
    u->cronometro = tempo;
}

void Graph::buscaEmCaminhoMinimo() {
    Vertex *v, *s, *u;
    // Lista "S" criada para guardar v�rtices visitados
    // Lista "Q" criada para guardar v�rtices n�o visitados
    // Lista "Dlist" criada para guardar a dist�ncia dos v�rtices
    list<Vertex *> S, Q;
    list<int> Dlist;

    // Iterator "lerVertS" criado para exibir os valores dos v�rtices visitados
    list<Vertex *>::iterator lerVertS, lerVertQ;
    bool execUnicaVez = true;
    // Pega o primeiro elemento da lista(raiz)
    s = vertice.begin()->second;
    for (lerVert = vertice.begin(); lerVert != vertice.end(); lerVert++) {
        v = lerVert->second;
        // Defini a dist�ncia de todos os v�rtices como infinito
        v->distancia = numeric_limits<float>::infinity();
        // Defini a pai de todos os v�rtices como nulo
        v->pai = NULL;
        Q.push_back(v);
    }
    s->distancia = 0;
    Dlist.push_back(s->distancia);
    while (Q.size() != 0) {
        //Extrai o elemento com menor dist�ncia
        u = extrairMinimo(u, s, Dlist);

        S.push_back(u);
        for (u->lerVertice = u->verticeAdjacente.begin();
             u->lerVertice != u->verticeAdjacente.end(); u->lerVertice++) {
            v = *(u->lerVertice);
            if (v->distancia > (u->distancia + getPesoEntreVertices(u->dado, v->dado))) {
                v->distancia = (u->distancia + getPesoEntreVertices(u->dado, v->dado));
                v->pai = u;
            }
            Dlist.push_back(v->distancia);
            Dmap[v->distancia] = v;
        }

        // Montando tabela com dist�ncia(d), pai(P) de cada v�rtice e ordem de visita(S)
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
            if (visitado->pai != NULL) {
                cout << "  " << visitado->dado << "  " << visitado->distancia << "  " << visitado->pai->dado <<
                "  " << visitado->dado;
            } else {
                cout << "  " << visitado->dado << "  " << visitado->distancia << "  " << "N" << "  " <<
                visitado->dado;
            }
        }
        cout << "\n\n";

        // Remove da lista a dist�ncia do atual v�rtice visitado
        Dlist.remove(u->distancia);
        // Remove o primeiro elemento das listas "S" e "Q"
        S.pop_front();
        Q.pop_front();
    };
}