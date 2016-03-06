#include "Runner.h"

void Runner::run() {
    Graph *graph = new Graph();
    int option, weight, edgeId, originVertexId, destinationVertexId, vertexId;

    do {
        this->showOptions();
        cout << endl << "Choose a option: ";
        this->breakLines();
        cin >> option;

        switch (option) {

            case Constants::Option::INSERT_VERTEX:
                cout << "Type vertex id to insert :)";
                this->breakLines();
                cin >> vertexId;

                if (graph->hasVertex(vertexId)) {

                    cout << "Existent vertex :(";
                    this->breakLines();
                    this->pause();
                } else {

                    graph->insertVertex(vertexId, vertexId);
                }

                this->clearConsole();
                graph->showStructure();

                break;

            case Constants::Option::REMOVE_VERTEX:
                cout << "Type vertex id to remove :)" << endl;
                this->breakLines();
                cin >> vertexId;

                if (graph->hasVertex(vertexId)) {

                    graph->removeVertex(vertexId);
                } else {

                    cout << "Nonexistent vertex :(";
                    this->breakLines();
                    this->pause();
                }

                this->clearConsole();
                graph->showStructure();

                break;

            case Constants::Option::INSERT_EDGE:
                cout << "Type edge id to insert :)";
                this->breakLines();
                cin >> edgeId;

                if (graph->hasEdge(edgeId)) {

                    cout << "Existent edge :(";

                    this->breakLines();
                    this->pause();
                } else {

                    cout << "Type origin vertex id :)";
                    this->breakLines();
                    cin >> originVertexId;

                    cout << "Type destination vertex id :)";
                    this->breakLines();
                    cin >> destinationVertexId;

                    if (graph->hasVertex(originVertexId) && graph->hasVertex(destinationVertexId)) {

                        cout << "Type weight of edge :)";
                        this->breakLines();
                        cin >> weight;
                        graph->insertEdge(edgeId, originVertexId, destinationVertexId, weight);
                    } else {

                        cout << "Invalid vertices :(";

                        this->breakLines();
                        this->pause();
                    }
                }

                this->clearConsole();

                graph->showStructure();

                break;

            case Constants::Option::REMOVE_EDGE:
                cout << "Type edge id to remove :)";
                this->breakLines();
                cin >> edgeId;

                if (graph->hasEdge(edgeId)) {

                    graph->removeEdge(edgeId);
                } else {

                    cout << "Nonexistent edge :(";

                    this->breakLines();
                    this->pause();
                }

                this->clearConsole();
                graph->showStructure();

                break;

            case Constants::Option::SHOW_ADJACENCY_LIST:

                this->clearConsole();

                cout << "Adjacency list";

                this->breakLines();

                graph->showStructure();

                break;

            case Constants::Option::SHOW_BREADTH_FIRST_SEARCH:

                this->clearConsole();

                cout << "Breadth-first search (BFS)";

                this->breakLines();

                graph->showTreeWidth();

                break;

            case Constants::Option::SHOW_DEPTH_FIRST_SEARCH:

                this->clearConsole();

                cout << "Depth-first search (DFS)";

                this->breakLines();

                graph->showTreeDepth();

                break;

            case Constants::Option::SHOW_SHORTEST_PATH:

                this->clearConsole();

                cout << "Dijkstra's algorithm (shortest path)";

                this->breakLines();

                graph->showShortestPath();

                break;

            case Constants::Option::EXIT:

                cout << "Thx ... :)";

                this->breakLines();

                break;

            default:

                this->clearConsole();

                cout << "Invalid option, please, try again.";

                this->breakLines();
        }

    } while (option != Constants::Option::EXIT);
}

void Runner::clearConsole() {
    system("clear");
}

void Runner::showOptions() {
    cout << "  ---------------------------------------------\n";
    cout << "  |                  Graphs                   |\n";
    cout << "  |-------------------------------------------|\n";
    cout << "  |                                           |\n";
    cout << "  | " << Constants::Option::INSERT_VERTEX << " - Insert Vertex                         |\n";
    cout << "  | " << Constants::Option::REMOVE_VERTEX << " - Remove Vertex                         |\n";
    cout << "  | " << Constants::Option::INSERT_EDGE << " - Insert Edge                           |\n";
    cout << "  | " << Constants::Option::REMOVE_EDGE << " - Remove Edge                           |\n";
    cout << "  | " << Constants::Option::SHOW_ADJACENCY_LIST << " - Adjacency list                        |\n";
    cout << "  | " << Constants::Option::SHOW_BREADTH_FIRST_SEARCH << " - Breadth-first search (BFS)            |\n";
    cout << "  | " << Constants::Option::SHOW_DEPTH_FIRST_SEARCH << " - Depth-first search (DFS)              |\n";
    cout << "  | " << Constants::Option::SHOW_SHORTEST_PATH << " - Dijkstra's algorithm (shortest path)  |\n";
    cout << "  | " << Constants::Option::EXIT << " - Exit                                  |\n";
    cout << "  |                                           |\n";
    cout << "  ---------------------------------------------\n";
    cout << endl;
}

void Runner::breakLines() {
    cout << endl << endl;
}

void Runner::pause() {
    system("pause");
}