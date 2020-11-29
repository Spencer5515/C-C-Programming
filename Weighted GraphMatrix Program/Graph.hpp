#ifndef GRAPH_H
#define GRAPH_H

#include "ArrayStack.hpp"

class Graph {
    protected:
        // the number of vertices
        int v;

        // the number of edges
        int e;

        // undirected (false) or directed (true)
        bool directed;

        // marking array for traversals
        bool* marking;

        // stack for topological sort
        ArrayStack<int>* S;

        // the depth-first search algorithm
        virtual void dfs(int) = 0;

        // the breadth-first search algorithm
        virtual void bfs(int) = 0;

        // the topological sort algorithm
        virtual void topoSort(int) = 0;

    public:
        // default constructor
        Graph() : v(0), e(0), directed(false) { }

        // destructor
        virtual ~Graph() { }

        // determine if the graph is directed or undirected
        virtual bool isDirected() const { return directed; }

        // determine if an edge exists
        virtual bool isEdge(int, int) const = 0;

        // return the number of vertices
        virtual int numVertices() const { return v; }

        // return the number of edges
        virtual int numEdges() const { return e; }

        // print a representation of the graph
        virtual void print() const = 0;

        // toggle the existence of an edge
        virtual void toggleEdge(int, int) = 0;

        // traverse the graph for DFS (0), BFS (1), or topological sort (2)
        virtual void traverse(int algoFlag) {
            // set all markings to unvisited (false)
            for (int i = 0; i < v; i++) {
                marking[i] = false;
            }

            // for each unvisited vertex, call the appropriate algorithm
            for (int i = 0; i < v; i++) {
                if (!marking[i]) {
                    if (algoFlag == 0) {
                        dfs(i);
                    }
                    else if (algoFlag == 1) {
                        bfs(i);
                    }
                    else if (algoFlag == 2) {
                        topoSort(i);
                    }
                }
            }

            // output the stack if performing topological sort
            if (algoFlag == 2) {
                while (!S->isEmpty()) {
                    cout << S->top() << ' ';
                    S->pop();
                }
            }
        }
};

#endif
