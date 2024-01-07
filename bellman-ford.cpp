#include <cstdio>
#include <vector>

using namespace std;

const int MAX_DISTANCE = 1000 * 1000 * 1000;

struct Edge {
	int nodeA;
	int nodeB;
	int weight;
};

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	int distances[N];
	int parents[N];

	for (int i = 0; i < N; i++) {
		distances[i] = MAX_DISTANCE;
	}

	int startingNode = 0;
	distances[startingNode] = 0;

	vector<Edge> edges(E);

	for (int i = 0; i < E; i++) {
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);

		edges[i].nodeA = A - 1;
		edges[i].nodeB = B - 1;
		edges[i].weight = L;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < E; j++) {
			Edge edge = edges[j];
			int distance = distances[edge.nodeA] + edge.weight;

			if (distances[edge.nodeB] > distance) {
				distances[edge.nodeB] = distance;
				parents[edge.nodeB] = edge.nodeA;
			}
		}
	}

	bool cycles = false;
	for (int i = 0; !cycles && i < E; i++) {
		Edge edge = edges[i];

		if (distances[edge.nodeB] > distances[edge.nodeA] + edge.weight) {
			cycles = true;
		}
	}

	if (cycles) {
		printf("ERREUR");
	} else {
		int endingNode = N - 1;
		printf("%d\n", distances[endingNode]);
		printf("%d ", endingNode + 1);

		int node = endingNode;
		while (node != startingNode) {
			node = parents[node];
			printf("%d ", node + 1);
		}
	}

	return 0;
}