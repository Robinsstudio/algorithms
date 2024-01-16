#include <cstdio>
#include <vector>

using namespace std;

const int MAX_NODES = 1000;
const int MAX_EDGES = 10000;

struct Edge {
	int id;
	int node;

	Edge(int id, int node): id(id), node(node) {}
};

vector<Edge> graph[MAX_NODES];
bool visitedEdges[MAX_EDGES];

void visit(int node) {
	for (int i = 0; i < graph[node].size(); i++) {
		Edge edge = graph[node][i];

		if (!visitedEdges[edge.id]) {
			visitedEdges[edge.id] = true;
			visit(edge.node);
		}
	}

	printf("%d ", node + 1);
}

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		graph[A - 1].push_back(Edge(i, B - 1));
		graph[B - 1].push_back(Edge(i, A - 1));
	}

	bool hasEvenDegree = true;
	for (int i = 0; hasEvenDegree && i < N; i++) {
		if (graph[i].size() % 2 == 1) {
			hasEvenDegree = false;
		}
	}

	if (hasEvenDegree) {
		visit(0);
	} else {
		printf("-1");
	}

	return 0;
}