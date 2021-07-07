#include <iostream>

using namespace std;

void traverse(int graph[][3], int n, bool** connected, int start, int current, bool* visited) {
	visited[current] = true;

	for (int i = 0; i < n; i++) {
		if (graph[i][current] && !visited[i]) {
			connected[start][i] = true;
			connected[i][start] = true;

			traverse(graph, n, connected, start, i, visited);
		}
	}
}

bool isConnected(int graph[][3], int n) {
	bool** connected = new bool*[n];
	for (int i = 0; i < n; i++) {
		connected[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			connected[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		bool* visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		traverse(graph, n, connected, i, i, visited);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i != j && connected[i][j] == false) {
				return false;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		delete[] connected[i];
	}
	delete[] connected;
	return true;
}

//int main() {
//
//	int connectedgraph[3][3] = {
//		{ 0, 0, 0 },
//		{ 1, 0, 0 },
//		{ 0, 1, 0 }
//	};
//
//	int graph[3][3] = {
//		{ 0, 1, 0 },
//		{ 0, 0, 0 },
//		{ 0, 1, 0 }
//	};
//
//	cout << isConnected(connectedgraph, 3);
//	cout << isConnected(graph, 3);
//
//	return 0;
//}