#include "GraphList.hpp"
#include "GraphMatrix.hpp"
#include <fstream>

void loadGraph(string, Graph*&);

int main() {
    // variables
    Graph* g = nullptr;
    int userChoice = 9;
    int numV = 0;
    string s = "";

    // menu loop
    do {
        cout << endl;
        cout << "1. Create a new graph\n";
        cout << "2. Check if the graph is undirected or directed\n";
        cout << "3. Find the number of vertices\n";
        cout << "4. Find the number of edges\n";
        cout << "5. Check if an edge exists\n";
        cout << "6. Toggle an edge\n";
        cout << "7. Print the graph\n";
        cout << "8. Traverse the graph\n";
        cout << "9. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << endl;

        switch (userChoice) {
            case 1:
                cout << "Enter the filename to load (with file extension): ";
                cin >> s;
                
                loadGraph(s, g);

                break;

            case 2:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                if (g->isDirected()) {
                    cout << "The graph is directed\n";
                }
                else {
                    cout << "The graph is undirected\n";
                }

                break;

            case 3:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                cout << "Number of vertices: ";
                cout << g->numVertices() << endl;

                break;

            case 4:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                cout << "Number of edges: ";
                cout << g->numEdges() << endl;

                break;

            case 5:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                cout << "Enter the first vertex: ";
                cin >> userChoice;

                cout << "Enter the second vertex: ";
                cin >> numV;

                if (g->isEdge(userChoice, numV)) {
                    cout << "The edge from " << userChoice
                         << " to " << numV << " exists!\n";
                }
                else {
                    cout << "The edge from " << userChoice
                         << " to " << numV << " does not exist.\n";
                }

                break;

            case 6:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                cout << "Enter the first vertex: ";
                cin >> userChoice;

                cout << "Enter the second vertex: ";
                cin >> numV;

                g->toggleEdge(userChoice, numV);

                break;

            case 7:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                g->print();

                break;

            case 8:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                do {
                    cout << "Enter 0 for DFS, 1 for BFS, "
                         << "or 2 for topological sort: ";
                    cin >> userChoice;
                } while (userChoice < 0 || userChoice > 2);

                g->traverse(userChoice);
                cout << endl;

                break;

            case 9:
                delete g;
                break;
        }
    } while (userChoice != 9);

    // terminate
    return 0;
}

/*********** FILE FORMAT ***********
matrix (0) or list (1)
undirected (0) or directed (1)
number of vertices
number of edges
v_i v_j
<repeat for as many edges>
**********************************/

void loadGraph(string filename, Graph*& g) {
    ifstream inputFile(filename);
    bool t, d;
    int v, e, i, j;

    if (inputFile.fail()) {
        cout << "Unable to load file!\n";
        return;
    }

    delete g;
    g = nullptr;

    inputFile >> t;
    inputFile >> d;
    inputFile >> v;
    inputFile >> e;

    if (t) {
        g = new GraphList(v, d);
    }
    else {
        g = new GraphMatrix(v, d);
    }

    while (e > 0) {
        inputFile >> i >> j;
        g->toggleEdge(i, j);
        e--;
    }
}
