#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    private:
        int V;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int jumlahVertex) {
            V = jumlahVertex;
            adjMatrix.resize(V, vector<int>(V, 0));
        }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:" << endl;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void dijkstra(int source, vector<int>& distance, vector<int>& parent) {
        vector<bool> visited(V, false);

        distance.assign(V, INT_MAX);
        parent.assign(V, -1);

        distance[source] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;

            for (int j = 0; j < V; j++) {
                if (!visited[j] &&
                    (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX)
                break;

            visited[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance = distance[u] + adjMatrix[u][v];

                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }
    }

    void printPath(int destination, vector<int>& parent) {
        vector<int> path;

        int current = destination;

        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        for (int i = path.size() - 1; i >= 0; i--) {
            cout << char('A' + path[i]);

            if (i > 0)
                cout << " -> ";
        }
    }

    void shortestFromA() {
        vector<int> distance;
        vector<int> parent;

        dijkstra(0, distance, parent);

        cout << "\nRute Terpendek dari Lokasi A:" << endl;

        for (int i = 0; i < V; i++) {
            cout << "A ke " << char('A' + i) << " : ";

            if (distance[i] == INT_MAX) {
                cout << "Tidak terjangkau" << endl;
            } else {
                printPath(i, parent);
                cout << " | Jarak: " << distance[i] << " km" << endl;
            }
        }
    }

    void recommendRoute(int source, int destination) {
        vector<int> distance;
        vector<int> parent;

        dijkstra(source, distance, parent);

        cout << "\nRekomendasi Rute Tercepat:" << endl;

        if (distance[destination] == INT_MAX) {
            cout << "Lokasi tidak terjangkau!" << endl;
        } else {
            cout << "Rute: ";
            printPath(destination, parent);

            cout << "\nTotal Jarak: " << distance[destination] << " km" << endl;
        }
    }
};

int main() {
    Graph graph(6);

    char start, destination;

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 5);
    graph.addEdge(1, 4, 3);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 6);
    graph.addEdge(3, 4, 2);
    graph.addEdge(3, 5, 4);
    graph.addEdge(4, 5, 3);

    graph.printAdjMatrix();

    graph.shortestFromA();

    cout << "\nMasukkan lokasi awal (A-F): ";
    cin >> start;

    cout << "Masukkan lokasi tujuan (A-F): ";
    cin >> destination;

    if (start < 'A' || start > 'F' ||
        destination < 'A' || destination > 'F') {
        cout << "\nLokasi tidak valid!" << endl;
    } else {
        graph.recommendRoute(start - 'A', destination - 'A');
    }

    return 0;
}