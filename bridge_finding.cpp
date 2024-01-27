#include <cstdio>
#include <vector>

using namespace std;

const int MAX_NODES = 1000;
const int MAX_EDGES = 10000;

struct Edge {
	int id;
	int nodeA;
	int nodeB;

	Edge(int id, int nodeA, int nodeB): id(id), nodeA(nodeA), nodeB(nodeB) {}
};

vector<Edge> graph[MAX_NODES];
vector<Edge> bridges;

bool visitedNodes[MAX_NODES];
bool visitedEdges[MAX_EDGES];
int depths[MAX_NODES];

int visit(int node, int depth) {
	if (visitedNodes[node]) {
		return depths[node];
	}

	visitedNodes[node] = true;
	depths[node] = depth;

	int minDepth = depth;

	for (int i = 0; i < graph[node].size(); i++) {
		Edge edge = graph[node][i];

		if (!visitedEdges[edge.id]) {
			visitedEdges[edge.id] = true;

			int childMinDepth = visit(edge.nodeB, depth + 1);

			if (childMinDepth > depth) {
				bridges.push_back(edge);
			}

			if (minDepth > childMinDepth) {
				minDepth = childMinDepth;
			}
		}
	}

	return minDepth;
}

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		graph[A - 1].push_back(Edge(i, A - 1, B - 1));
		graph[B - 1].push_back(Edge(i, B - 1, A - 1));
	}

	for (int i = 0; i < N; i++) {
		visit(i, 0);
	}

	for (Edge bridge : bridges) {
		printf("%d %d\n", bridge.nodeA + 1, bridge.nodeB + 1);
	}

	return 0;
}