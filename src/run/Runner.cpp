#include "Runner.h"

void Runner::run() {
    Graph *grafo = new Graph();
    int opcao, peso, idAresta, verticeOrigem, verticeDestino, idVertice;

    do {
        this->showOptions();
        cout << "Digite o numero da opcao desejada: ";
        cin >> opcao;

        switch (opcao) {
            case Constants::Option::INSERT_VERTEX:
                //Inserir Vértice
                cout << "Digite o id do vertice: ";
                cin >> idVertice;

                if (grafo->existeVertice(idVertice)) {
                    cout << "Vertex já existente!";
                    this->breakLines();
                    system("pause");
                } else {
                    grafo->inserirVertice(idVertice, idVertice);
                }

                this->clearConsole();
                grafo->imprimirGrafo();
                break;

            case Constants::Option::REMOVE_VERTEX:
                //Remover Vértice
                cout << "Digite o id do vertice a ser removido: ";
                cin >> idVertice;

                if (grafo->existeVertice(idVertice)) {
                    grafo->removerVertice(idVertice);
                } else {
                    cout << "Vertex não existente!";
                    this->breakLines();
                    system("pause");
                }

                this->clearConsole();
                grafo->imprimirGrafo();
                break;

            case Constants::Option::INSERT_EDGE:
                //Inserir Edge
                cout << "Digite o id da aresta: ";
                cin >> idAresta;

                if (grafo->existeAresta(idAresta)) {
                    cout << "Edge existente!";
                    this->breakLines();
                    system("pause");
                } else {
                    cout << "Digite o id do vertice origem: ";
                    cin >> verticeOrigem;
                    cout << "Digite o id do vertice destino: ";
                    cin >> verticeDestino;
                    if (grafo->existeVertice(verticeOrigem) && grafo->existeVertice(verticeDestino)) {
                        cout << "Digite o peso da aresta: ";
                        cin >> peso;
                        grafo->inserirAresta(idAresta, verticeOrigem, verticeDestino, peso);
                    } else {
                        cout << "Vertices inválidos!";
                        this->breakLines();
                        system("pause");
                    }
                }

                this->clearConsole();
                grafo->imprimirGrafo();
                break;

            case Constants::Option::REMOVE_EDGE:
                //Remover Edge
                cout << "Digite o id da aresta: ";
                cin >> idAresta;

                if (grafo->existeAresta(idAresta)) {
                    grafo->removerAresta(idAresta);
                } else {
                    cout << "Edge não existente!";
                    this->breakLines();
                    system("pause");
                }

                this->clearConsole();
                grafo->imprimirGrafo();
                break;

            case Constants::Option::SHOW_STRUCTURE:
                this->clearConsole();
                grafo->imprimirGrafo();
                break;

            case Constants::Option::SHOW_TREE_WIDTH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca em Largura";
                this->breakLines();
                grafo->buscaEmLargura();
                break;

            case Constants::Option::SHOW_TREE_DEPTH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca em Profundidade";
                this->breakLines();
                grafo->buscaEmProfundidade();
                break;

            case Constants::Option::SHOW_SHORTEST_PATH:
                this->clearConsole();
                cout << "Graph - Algoritmo de Busca por Caminho Mínimo";
                this->breakLines();
                grafo->buscaEmCaminhoMinimo();
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
    cout << "  ------------------Menu-------------\n";
    cout << "  | " << Constants::Option::INSERT_VERTEX << " - Inserir Vértice             |\n";
    cout << "  | " << Constants::Option::REMOVE_VERTEX << " - Remover Vértice             |\n";
    cout << "  | " << Constants::Option::INSERT_EDGE << " - Inserir Aresta              |\n";
    cout << "  | " << Constants::Option::REMOVE_EDGE << " - Remover Aresta              |\n";
    cout << "  | " << Constants::Option::SHOW_STRUCTURE << " - Imprimir Estrutura          |\n";
    cout << "  | " << Constants::Option::SHOW_TREE_WIDTH << " - Imprimir por Largura        |\n";
    cout << "  | " << Constants::Option::SHOW_TREE_DEPTH << " - Imprimir por Profundidade   |\n";
    cout << "  | " << Constants::Option::SHOW_SHORTEST_PATH << " - Imprimir por Caminho Mínimo |\n";
    cout << "  | " << Constants::Option::EXIT << " - Sair                        |\n";
    cout << "  -----------------------------------\n";
    cout << endl;
}

void Runner::breakLines() {
    cout << endl << endl;
}