#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "Graph.hpp"
#include <iostream>
using namespace std;

class GraphMatrix : public Graph {
    private:
        bool** adjMatrix;

    public:
        // constructor
        GraphMatrix(int, bool);

        // destructor
        virtual ~GraphMatrix();

        // determine if an edge exists
        virtual bool isEdge(int, int) const override;

        // print a representation of the graph
        virtual void print() const override;

        // toggle the existence of an edge
        virtual void toggleEdge(int, int) override;
};

GraphMatrix::GraphMatrix(int numV, bool dirFlag) {
    v = numV;
    directed = dirFlag;
    adjMatrix = new bool*[v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];

        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < v; i++) {
        delete adjMatrix[i];
    }
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const {
    return i >= 0 && i < v && j >= 0 && j < v && adjMatrix[i][j];
}

void GraphMatrix::print() const {
    cout << "    ";
    for (int i = 0; i < v; i++) {
        cout << i << ' ';
    }
    cout << endl;

    cout << "---";
    for (int i = 0; i < v; i++) {
        cout << "--";
    }
    cout << endl;

    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        for (int j = 0; j < v; j++) {
            cout << adjMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void GraphMatrix::toggleEdge(int i, int j) {
    if (i >= 0 && i < v && j >= 0 && j < v) {
        adjMatrix[i][j] = !adjMatrix[i][j];
        adjMatrix[i][j] ? e++ : e--;

        if (!directed) {
            adjMatrix[j][i] = !adjMatrix[j][i];

            // include if keeping track of how many directed edges
            // adjMatrix[j][i] ? e++ : e--;
        }
    }
}

#endif
