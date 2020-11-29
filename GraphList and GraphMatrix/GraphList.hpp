#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include "Graph.hpp"
#include "LinkedList.hpp"
#include <iostream>
using namespace std;

class GraphList : public Graph {
    private:
        LinkedList<int>** adjList;

    public:
        // constructor
        GraphList(int, bool);

        // destructor
        virtual ~GraphList();

        // determine if an edge exists
        virtual bool isEdge(int, int) const override;

        // print a representation of the graph
        virtual void print() const override;

        // toggle the existence of an edge
        virtual void toggleEdge(int, int) override;
};

GraphList::GraphList(int numV, bool dirFlag) {
    v = numV;
    directed = dirFlag;
    adjList = new LinkedList<int>*[numV];
    for (int i = 0; i < v; i++) {
        adjList[i] = new LinkedList<int>();
    }
}

GraphList::~GraphList() {
    for (int i = 0; i < v; i++) {
        delete adjList[i];
    }
    delete[] adjList;
}

bool GraphList::isEdge(int i, int j) const {
    if (i >= 0 && i < v && j >= 0 && j < v) {
        for (int k = 0; k < adjList[i]->getLength(); k++) {
            if (adjList[i]->getElement(k) == j) {
                return true;
            }
        }
    }

    return false;
}

void GraphList::print() const {
    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        for (int j = 0; j < adjList[i]->getLength(); j++) {
            cout << adjList[i]->getElement(j);

            if (j != adjList[i]->getLength() - 1) {
                cout << " --> ";
            }
        }
        cout << endl;
    }
}

void GraphList::toggleEdge(int i, int j) {
    if (i >= 0 && i < v && j >= 0 && j < v) {
        bool existsFlag = false;

        for (int k = 0; k < adjList[i]->getLength(); k++) {
            if (adjList[i]->getElement(k) == j) {
                adjList[i]->remove(k);
                e--;
                existsFlag = true;
                break;
            }
        }

        if (existsFlag && !directed) {
            for (int k = 0; k < adjList[j]->getLength(); k++) {
                if (adjList[j]->getElement(k) == i) {
                    adjList[j]->remove(k);
                    // include if keeping track of how many directed edges
                    // e--;
                    break;
                }
            }
        }

        if (!existsFlag) {
            adjList[i]->append(j);
            e++;

            if (!directed) {
                adjList[j]->append(i);
                // include if keeping track of how many directed edges
                // e++;
            }
        }
    }
}

#endif
