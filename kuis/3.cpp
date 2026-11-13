#include <iostream>
#include <vector>
#include <queue>
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
        cout << "\t";
        for (int i = 0; i < V; i++) cout << char('A' + i) << "\t";
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << char('A' + i) << "\t";
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool> visited(V, false);
        queue<int> titikvisit;

        visited[startVertex] = true;
        titikvisit.push(startVertex);

        cout << "BFS dari " << char('A' + startVertex) << " : ";

        while (!titikvisit.empty()) {
            int currentVertex = titikvisit.front();
            titikvisit.pop();

            cout << char('A' + currentVertex) << " ";

            for (int i = 0; i < V; i++) {
                if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    titikvisit.push(i);
                }
            }
        }
        cout << endl;
    }

    void dfs(int startVertex) {
        vector<bool> visited(V, false);
        cout << "DFS dari " << char('A' + startVertex) << " : ";
        dfsUntil(startVertex, visited);
        cout << endl;
    }

    void dfsUntil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true;
        cout << char('A' + currentVertex) << " ";

        for (int i = 0; i < V; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                dfsUntil(i, visited);
            }
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

    void shortestPath(int source, int destination) {
        vector<int> distance;
        vector<int> parent;

        dijkstra(source, distance, parent);

        cout << "\nRute Terpendek dari " << char('A' + source)
            << " ke " << char('A' + destination) << ":" << endl;

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

    graph.addEdge(0, 1, 4);  // A-B
    graph.addEdge(0, 2, 2);  // A-C
    graph.addEdge(1, 2, 1);  // B-C
    graph.addEdge(1, 3, 5);  // B-D
    graph.addEdge(1, 4, 3);  // B-E
    graph.addEdge(2, 3, 8);  // C-D
    graph.addEdge(2, 4, 6);  // C-E
    graph.addEdge(3, 4, 2);  // D-E
    graph.addEdge(3, 5, 4);  // D-F
    graph.addEdge(4, 5, 3);  // E-F

    graph.printAdjMatrix();

    graph.bfs(0);
    graph.dfs(0);

    vector<int> distance, parent;
    graph.dijkstra(0, distance, parent);

    cout << "\nJarak terpendek dari vertex A:" << endl;
    for (int i = 0; i < 6; i++) {
        if (distance[i] == INT_MAX)
            cout << "A ke " << char('A' + i) << " : Tidak terjangkau" << endl;
        else
            cout << "A ke " << char('A' + i) << " : " << distance[i] << " km" << endl;
    }

    char start, destination;
    cout << "\nMasukkan vertex awal (A-F): ";
    cin >> start;
    cout << "Masukkan vertex tujuan (A-F): ";
    cin >> destination;

    if (start < 'A' || start > 'F' ||
        destination < 'A' || destination > 'F') {
        cout << "\nVertex tidak valid!" << endl;
    } else {
        graph.shortestPath(start - 'A', destination - 'A');
    }

    return 0;
}