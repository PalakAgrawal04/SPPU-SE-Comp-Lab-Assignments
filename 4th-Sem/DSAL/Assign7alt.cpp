#include <iostream>
#include <map>
#include <string>
#include <climits>

using namespace std;

const int MAX_DISTANCE = INT_MAX;

class Graph {
private:
    int **adjacencyMatrix;
    int vertexCount;
    int edgeCount;
    map<string, int> cityIndices;
    map<int, string> cityNames;

    void addEdge(string city1, string city2, int distance) {
        adjacencyMatrix[cityIndices[city1]][cityIndices[city2]] = distance;
        adjacencyMatrix[cityIndices[city2]][cityIndices[city1]] = distance;
    }

    int getMinimumKeyIndex(int key[], bool mst[]) {
        int minKey = INT_MAX;
        int minIndex = -1;
        for (int v = 0; v < vertexCount; ++v) {
            if (!mst[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

public:
    Graph() {
        cout << "Enter number of vertices: ";
        cin >> vertexCount;
        cout << "Enter number of edges: ";
        cin >> edgeCount;

        adjacencyMatrix = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            adjacencyMatrix[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++)
                adjacencyMatrix[i][j] = 0;
        }

        cout << "Add cities in order: " << endl;
        for (int i = 0; i < vertexCount; i++) {
            string cityName;
            cin >> cityName;
            cityIndices.insert(make_pair(cityName, i));
            cityNames.insert(make_pair(i, cityName));
        }

        cout << "Add the " << edgeCount << " edges" << endl;

        for (int i = 0; i < edgeCount; i++) {
            string city1, city2;
            int distance;
            cout << "City 1: ";
            cin >> city1;
            cout << "City 2: ";
            cin >> city2;
            cout << "Distance: ";
            cin >> distance;
            addEdge(city1, city2, distance);
        }
    }

    void displayGraph() {
        cout << "\nAdjacency Matrix of the graph:" << endl;
        for (int i = 0; i < vertexCount; i++) {
            for (int j = 0; j < vertexCount; j++) {
                cout << adjacencyMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void findMinimumSpanningTree() {
        int parent[vertexCount];
        int key[vertexCount];
        bool mst[vertexCount];

        for (int i = 0; i < vertexCount; i++) {
            key[i] = INT_MAX;
            mst[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < vertexCount - 1; count++) {
            int minKeyIndex = getMinimumKeyIndex(key, mst);
            mst[minKeyIndex] = true;

            for (int v = 0; v < vertexCount; v++) {
                if (adjacencyMatrix[minKeyIndex][v] != 0 && !mst[v] && adjacencyMatrix[minKeyIndex][v] < key[v]) {
                    parent[v] = minKeyIndex;
                    key[v] = adjacencyMatrix[minKeyIndex][v];
                }
            }
        }

        cout << "\n\nMinimum Spanning Tree (MST) of the given graph is: \n" << endl;
        cout << "\nEdge \t\t Weight\n";
        int mstCost = 0;
        for (int i = 1; i < vertexCount; i++) {
            cout << cityNames[parent[i]] << " <-> " << cityNames[i] << " \t " << adjacencyMatrix[i][parent[i]] << endl;
            mstCost += adjacencyMatrix[i][parent[i]];
        }
        cout << "\nTotal cost of the MST: " << mstCost << endl;
    }
};

int main() {
    Graph g;
    g.displayGraph();
    g.findMinimumSpanningTree();
    return 0;
}
