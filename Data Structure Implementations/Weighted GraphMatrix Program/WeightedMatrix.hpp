#ifndef WEIGHTED_MATRIX_H
#define WEIGHTED_MATRIX_H

#include "ArrayQueue.hpp"
#include "WeightedGraph.hpp"
#include <climits>
#include <iomanip>
#include <iostream>
using namespace std;

class WeightedMatrix : public WeightedGraph {
    private:
        int** adjMatrix;

    protected:
        // the breadth-first search algorithm
        virtual void bfs(int) override;

        // the depth-first search algorithm
        virtual void dfs(int) override;

        // helper method for Dijkstra's algorithm
        // brute-force approach of finding minimum vertex
        virtual int findMin() const override;
        
        // the topological sort algorithm
        virtual void topoSort(int) override;

    public:
        // constructor
        WeightedMatrix(int, bool);

        // destructor
        virtual ~WeightedMatrix();

        // add an edge from vertex i [argument 1] to vertex j [argument 2]
        // with weight w [argument 3]
        virtual void addEdge(int, int, int) override;

        // Dijkstra's algorithm for computing shortest distance costs
        virtual void dijkstra(int) override;

        // determine if an edge exists
        virtual bool isEdge(int, int) const override;

        // print a representation of the graph
        virtual void print() const override;

        // remove an edge from vertex i [argument 1] to vertex j [argument 2]
        virtual void removeEdge(int, int) override;
};

void WeightedMatrix::addEdge(int i, int j, int w) {
    // TODO
	adjMatrix[i][j] = w;
	adjMatrix[j][i] = w;
	e++;
}

void WeightedMatrix::removeEdge(int i, int j) {
    // TODO
	adjMatrix[i][j] = 0;
	adjMatrix[j][i] = 0;
	e--;
}

int WeightedMatrix::findMin() const {
    // TODO
    int min = INT_MAX, index;
              
	for (int i = 0; i < 6; i++) {
		if(marking[i] == 0 && distances[i] <= min)      {
			min = distances[i];
			index = i;
		} // if
	} // for loop
	return index;
}

void WeightedMatrix::dijkstra(int s) {
    // TODO
	for (int i = 0; i < v; i++) {
		distances[i] = INT_MAX;
		marking[i] = false;	
	} // for loop
	
	distances[s] = 0;         
	
	for (int i = 0; i < v; i++) {
		int m = findMin();
		marking[m] = true;

		for (int i = 0; i < v; i++) {
			if(!marking[i] && adjMatrix[m][i] && distances[m] != INT_MAX && distances[m] + adjMatrix[m][i] < distances[i]) {
				distances[i] = distances[m] + adjMatrix[m][i];
			} // if
		} // for loop
	} // for loop

    // print out the distances
    cout << "Using source vertex: " << s << endl;
    cout << "v | d\n";
    cout << "------\n";
    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        if (distances[i] == INT_MAX) {
            cout << "infinity\n";
        }
        else {
            cout << distances[i] << endl;
        }
    }
}

WeightedMatrix::WeightedMatrix(int numV, bool dirFlag) {
    v = numV;
    directed = dirFlag;
    adjMatrix = new int*[v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new int[v];

        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    S = new ArrayStack<int>(v);
    marking = new bool[v];
    distances = new int[v];
}

WeightedMatrix::~WeightedMatrix() {
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] marking;
    delete S;
    delete[] distances;
}

void WeightedMatrix::bfs(int s) {
    ArrayQueue<int> Q(v);

    Q.enqueue(s);
    marking[s] = true;
    int i = -1;

    while (!Q.isEmpty()) {
        i = Q.front();
        Q.dequeue();

        cout << i << ' ';

        for (int j = 0; j < v; j++) {
            if (isEdge(i, j) && !marking[j]) {
                marking[j] = true;
                Q.enqueue(j);
            }
        }
    }
}

void WeightedMatrix::dfs(int i) {
    marking[i] = true;

    cout << i << ' ';

    for (int j = 0; j < v; j++) {
        if (isEdge(i, j) && !marking[j]) {
            dfs(j);
        }
    }
}

bool WeightedMatrix::isEdge(int i, int j) const {
    return i >= 0 && i < v && j >= 0 && j < v && adjMatrix[i][j] != 0;
}

void WeightedMatrix::print() const {
    cout << "    ";
    for (int i = 0; i < v; i++) {
        cout << setw(4) << left << i;
    }
    cout << endl;

    cout << setw(4 * v + 4) << setfill('-') << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < v; i++) {
        cout << i << " | ";
        for (int j = 0; j < v; j++) {
            cout << setw(4) << left << adjMatrix[i][j];
        }
        cout << endl;
    }
}

void WeightedMatrix::topoSort(int i) {
    marking[i] = true;

    for (int j = 0; j < v; j++) {
        if (isEdge(i, j) && !marking[j]) {
            topoSort(j);
        }
    }

    S->push(i);
}

#endif
