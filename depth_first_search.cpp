#include <cstdio>
#include <vector>

using namespace std;

const int MAX_NODES = 1000;

vector<int> graph[MAX_NODES];
bool visitedNodes[MAX_NODES];

void visit(int node) {
	printf("%d\n", node + 1);

	for (int i = 0; i < graph[node].size(); i++) {
		int neighbor = graph[node][i];

		if (!visitedNodes[neighbor]) {
			visitedNodes[neighbor] = true;
			visit(neighbor);
		}
	}
}

int main() {
	int N, E;
	scanf("%d%d", &N, &E);


	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		graph[A - 1].push_back(B - 1);
		graph[B - 1].push_back(A - 1);
	}

	int startingNode = 0;
	visitedNodes[startingNode] = true;
	visit(startingNode);

	return 0;
}