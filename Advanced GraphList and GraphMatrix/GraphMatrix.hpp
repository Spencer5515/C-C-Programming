#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include "Graph.hpp"
#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;

class GraphMatrix : public Graph {
    private:
        bool** adjMatrix;

    protected:
        // the depth-first search algorithm
        virtual void dfs(int) override;

        // the breadth-first search algorithm
        virtual void bfs(int) override;

        // the topological sort algorithm
        virtual void topoSort(int) override;

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

void GraphMatrix::dfs(int i) {
    // TODO
    marking[i] = 1; // sets first to true
  
    for (int j = 0; j < v; j++) { 
        if (adjMatrix[i][j] == 1 && (!marking[j])) { // if adjacent -> not visited
            dfs(j); 
        } // if
    } // for loop
}

void GraphMatrix::bfs(int s) {
    // TODO
	for (int i = 0; i < v; i++) {
		marking[i] = false;
	} // for loop
    
    ArrayQueue<int> q; // sets up queue for bfs
    q.enqueue(s);
    marking[s] = true;
    
    while (q.isEmpty() == false) {
        int vert = q.front();
        q.dequeue();
        
        for (int i = 0; i < v; i++) {
            int side = i;
            
            if(marking[side] == false) {
                q.enqueue(side);
                marking[side] = true;
            } // if
        } // for loop
    } // while
}

void GraphMatrix::topoSort(int i) {
    // TODO
	marking[i] = 1; // sets first to true
  
    for (int j = 0; j < v; j++) { 
        if (adjMatrix[i][j] == 1 && (!marking[j])) { // if adjacent -> not visited
            topoSort(j); 
        } // if
    } // for loop
	S->push(i);
}

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
    S = new ArrayStack<int>(v);
    marking = new bool[v];
}

GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < v; i++) {
        delete adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] marking;
    delete S;
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
