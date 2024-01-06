#include <cstdio>
#include <vector>

using namespace std;

const int MAX_NODES = 1000;

const int NOT_VISITED = 0;
const int VISITING = 1;
const int VISITED = 2;

vector<int> graph[MAX_NODES];

int visitedNodes[MAX_NODES];
int sortedNodes[MAX_NODES];

bool cycles = false;
int currentIndex = 0;

void visit(int node) {
	for (int i = 0; i < graph[node].size(); i++) {
		int neighbor = graph[node][i];

		if (visitedNodes[neighbor] == NOT_VISITED) {
			visitedNodes[neighbor] = VISITING;
			visit(neighbor);
		} else if (visitedNodes[neighbor] == VISITING) {
			cycles = true;
		}
	}

	sortedNodes[currentIndex++] = node + 1;
	visitedNodes[node] = VISITED;
}

void startVisiting(int node) {
	if (visitedNodes[node] == VISITED) {
		return;
	}

	visitedNodes[node] = VISITING;
	visit(node);
}

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		graph[B - 1].push_back(A - 1);
	}

	for (int i = 0; i < N; i++) {
		startVisiting(i);
	}

	if (cycles) {
		printf("-1");
	} else {
		for (int i = 0; i < N; i++) {
			printf("%d ", sortedNodes[i]);
		}
	}

	return 0;
}