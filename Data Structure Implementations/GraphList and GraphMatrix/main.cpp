#include "GraphList.hpp"
#include "GraphMatrix.hpp"

int main() {
    // variables
    Graph* g = nullptr;
    int userChoice = 8;
    int numV = 0;
    bool b = false;

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
        cout << "8. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << endl;

        switch (userChoice) {
            case 1:
                do {
                    cout << "Enter how many vertices are in the graph: ";
                    cin >> numV;
                } while (numV <= 0);

                cout << "Enter 0 for undirected or 1 for directed: ";
                cin >> b;

                do {
                    cout << "Enter 0 for adjacency matrix "
                         << "or 1 for adjacency list: ";
                    cin >> userChoice;
                } while (userChoice != 0 && userChoice != 1);

                delete g;

                if (userChoice == 0) {
                    g = new GraphMatrix(numV, b);
                }
                else {
                    g = new GraphList(numV, b);
                }

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
                delete g;
                break;
        }
    } while (userChoice != 8);

    // terminate
    return 0;
}
