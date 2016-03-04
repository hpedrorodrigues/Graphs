#include "Runner.h"

void Runner::run() {
    Graph *grafo = new Graph();
    int opcao, peso, idAresta, verticeOrigem, verticeDestino, idVertice;

    do {
        this->showOptions();
        cout << "Digite o numero da opcao desejada: ";
        this->breakLines();
        cin >> opcao;

        switch (opcao) {
            case Constants::Option::INSERT_VERTEX:
                //Inserir Vértice
                cout << "Digite o id do vertice: ";
                cin >> idVertice;

                if (grafo->hasVertex(idVertice)) {
                    cout << "Vertex já existente!";
                    this->breakLines();
                    system("pause");
                } else {
                    grafo->insertVertex(idVertice, idVertice);
                }

                this->clearConsole();
                grafo->showStructure();
                break;

            case Constants::Option::REMOVE_VERTEX:
                //Remover Vértice
                cout << "Digite o id do vertice a ser removido: ";
                cin >> idVertice;

                if (grafo->hasVertex(idVertice)) {
                    grafo->removeVertex(idVertice);
                } else {
                    cout << "Vertex não existente!";
                    this->breakLines();
                    system("pause");
                }

                this->clearConsole();
                grafo->showStructure();
                break;

            case Constants::Option::INSERT_EDGE:
                //Inserir Edge
                cout << "Digite o id da aresta: ";
                cin >> idAresta;

                if (grafo->hasEdge(idAresta)) {
                    cout << "Edge existente!";
                    this->breakLines();
                    system("pause");
                } else {
                    cout << "Digite o id do vertice origem: ";
                    cin >> verticeOrigem;
                    cout << "Digite o id do vertice destino: ";
                    cin >> verticeDestino;
                    if (grafo->hasVertex(verticeOrigem) && grafo->hasVertex(verticeDestino)) {
                        cout << "Digite o peso da aresta: ";
                        cin >> peso;
                        grafo->insertEdge(idAresta, verticeOrigem, verticeDestino, peso);
                    } else {
                        cout << "Vertices inválidos!";
                        this->breakLines();
                        system("pause");
                    }
                }

                this->clearConsole();
                grafo->showStructure();
                break;

            case Constants::Option::REMOVE_EDGE:
                //Remover Edge
                cout << "Digite o id da aresta: ";
                cin >> idAresta;

                if (grafo->hasEdge(idAresta)) {
                    grafo->removeEdge(idAresta);
                } else {
                    cout << "Edge não existente!";
                    this->breakLines();
                    system("pause");
                }

                this->clearConsole();
                grafo->showStructure();
                break;

            case Constants::Option::SHOW_STRUCTURE:
                this->clearConsole();
                grafo->showStructure();
                break;

            case Constants::Option::SHOW_TREE_WIDTH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca em Largura";
                this->breakLines();
                grafo->showTreeWidth();
                break;

            case Constants::Option::SHOW_TREE_DEPTH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca em Profundidade";
                this->breakLines();
                grafo->showTreeDepth();
                break;

            case Constants::Option::SHOW_SHORTEST_PATH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca por Caminho Mínimo";
                this->breakLines();
                grafo->showShortestPath();
                break;

            case Constants::Option::EXIT:
                cout << "Saindo...";
                this->breakLines();
                break;

            default:
                this->clearConsole();
                cout << "Opção inválida, tente novamente.";
                this->breakLines();
        }
    } while (opcao != Constants::Option::EXIT);
}

void Runner::clearConsole() {
    system("clear");
}

void Runner::showOptions() {
    cout << "  ---------------Graphs--------------\n";
    cout << "  |                                 |\n";
    cout << "  | " << Constants::Option::INSERT_VERTEX << " - Insert Vertex               |\n";
    cout << "  | " << Constants::Option::REMOVE_VERTEX << " - Remove Vertex               |\n";
    cout << "  | " << Constants::Option::INSERT_EDGE << " - Insert Edge                 |\n";
    cout << "  | " << Constants::Option::REMOVE_EDGE << " - Remove Edge                 |\n";
    cout << "  | " << Constants::Option::SHOW_STRUCTURE << " - Show Structure              |\n";
    cout << "  | " << Constants::Option::SHOW_TREE_WIDTH << " - Show Tree Width             |\n";
    cout << "  | " << Constants::Option::SHOW_TREE_DEPTH << " - Show Tree Depth             |\n";
    cout << "  | " << Constants::Option::SHOW_SHORTEST_PATH << " - Show shortest path          |\n";
    cout << "  | " << Constants::Option::EXIT << " - Exit                        |\n";
    cout << "  |                                 |\n";
    cout << "  -----------------------------------\n";
    cout << endl;
}

void Runner::breakLines() {
    cout << endl << endl;
}