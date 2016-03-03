#include "Edge.h"

Edge::Edge(int originVertexId, int destinationVertexId, int weight) {
    this->originVertexId = originVertexId;
    this->destinationVertexId = destinationVertexId;
    this->weight = weight;
};

Edge::~Edge() {
}