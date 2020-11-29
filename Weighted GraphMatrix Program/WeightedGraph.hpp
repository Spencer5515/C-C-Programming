#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include "Graph.hpp"

class WeightedGraph : public Graph {
    protected:
        // distance array for finding the shortest path
        int* distances;

        // helper method for Dijkstra's algorithm
        // brute-force approach of finding minimum vertex
        virtual int findMin() const = 0;

    public:
        // default constructor
        WeightedGraph() { }

        // destructor
        virtual ~WeightedGraph() { }

        // add an edge from vertex i [argument 1] to vertex j [argument 2]
        // with weight w [argument 3]
        virtual void addEdge(int, int, int) = 0;

        // Dijkstra's algorithm for computing shortest distance costs
        virtual void dijkstra(int) = 0;

        // remove an edge from vertex i [argument 1] to vertex j [argument 2]
        virtual void removeEdge(int, int) = 0;

        // toggle the existence of an edge (NOT ALLOWED)
        virtual void toggleEdge(int, int) override { return; }
};

#endif
