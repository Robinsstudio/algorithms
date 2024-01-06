#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODES = 1000;

bool visitedNodes[MAX_NODES];

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	vector<int> graph[N];

	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		graph[A - 1].push_back(B - 1);
		graph[B - 1].push_back(A - 1);
	}

	queue<int> queue;

	int startingNode = 0;
	visitedNodes[startingNode] = true;
	queue.push(startingNode);

	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();

		printf("%d\n", node + 1);

		for (int i = 0; i < graph[node].size(); i++) {
			int neighbor = graph[node][i];

			if (!visitedNodes[neighbor]) {
				visitedNodes[neighbor] = true;
				queue.push(neighbor);
			}
		}
	}

	return 0;
}