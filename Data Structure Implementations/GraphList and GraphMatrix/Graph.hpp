#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    protected:
        // the number of vertices
        int v;

        // the number of edges
        int e;

        // undirected (false) or directed (true)
        bool directed;

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
};

#endif
