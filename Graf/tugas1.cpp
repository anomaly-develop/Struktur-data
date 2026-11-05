#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    private:
        int numberVertex;
        vector<vector<int>> adjMatrix;

    public:
        Graph(int banyakTitik) {
            numberVertex = banyakTitik;
            adjMatrix.resize(numberVertex, vector<int>(numberVertex, 0));
        }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numberVertex && j >= 0 && j < numberVertex) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
        } else {
            cout << "Index nonvalid" << endl;
        }
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:" << endl;

        for (int i = 0; i < numberVertex; i++) {
            for (int j = 0; j < numberVertex; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex) {
        vector<bool> visited(numberVertex, false);
        queue<int> titikvisit;

        visited[startVertex] = true;
        titikvisit.push(startVertex);

        cout << "\nUrutan BFS: ";

        while (!titikvisit.empty()) {
            int currentVertex = titikvisit.front();
            titikvisit.pop();

            cout << char('A' + currentVertex) << " ";

            for (int i = 0; i < numberVertex; i++) {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    titikvisit.push(i);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph graph(6);

    int jumlahEdge;
    char u, v;
    char startVertex;

    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    cout << "\nMasukkan hubungan antar vertex (A-F):" << endl;

    for (int i = 0; i < jumlahEdge; i++) {
        cout << "Edge " << i + 1 << " : ";
        cin >> u >> v;

        graph.addEdge(u - 'A', v - 'A');
    }

    graph.printAdjMatrix();

    cout << "\nMasukkan vertex awal (A-F): ";
    cin >> startVertex;

    if (startVertex < 'A' || startVertex > 'F') {
        cout << "Vertex tidak valid!" << endl;
    } else {
        graph.bfs(startVertex - 'A');
    }

    return 0;
}
