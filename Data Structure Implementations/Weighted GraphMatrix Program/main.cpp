#include "WeightedMatrix.hpp"
#include <fstream>

void loadGraph(string, WeightedGraph*&);

int main() {
    // variables
    WeightedGraph* g = nullptr;
    int userChoice = 11;
    int numV = 0;
	int weight = 0;
    string s = "";

    // menu loop
    do {
        cout << endl;
        cout << "1. Create a new graph\n";
        cout << "2. Check if the graph is undirected or directed\n";
        cout << "3. Find the number of vertices\n";
        cout << "4. Find the number of edges\n";
        cout << "5. Check if an edge exists\n";
        cout << "6. Add an edge\n";
		cout << "7. Remove an edge\n";
        cout << "8. Print the graph\n";
        cout << "9. Traverse the graph\n";
		cout << "10. Find shortest path\n";
        cout << "11. Exit\n\n";

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

				cout << "Enter the weight: ";
				cin >> weight;

                g->addEdge(userChoice, numV, weight);

                break;

			case 7:
				if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                cout << "Enter the first vertex: ";
                cin >> userChoice;

                cout << "Enter the second vertex: ";
                cin >> numV;

                g->removeEdge(userChoice, numV);

                break;

            case 8:
                if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

                g->print();

                break;

            case 9:
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

			case 10:
				if (g == nullptr) {
                    cout << "You must create a graph first!\n";
                    break;
                }

				cout << "Enter the source vertex: ";
                cin >> userChoice;

				g->dijkstra(userChoice);

				break;

            case 11:
                delete g;
                break;
        }
    } while (userChoice != 11);

    // terminate
	cout << "Program Terminating...\n";
    return 0;
}

void loadGraph(string filename, WeightedGraph*& g) {
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

    g = new WeightedMatrix(v, d);

    while (e > 0) {
        inputFile >> i >> j;
        g->toggleEdge(i, j);
        e--;
    }
}