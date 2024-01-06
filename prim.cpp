#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODES = 1000;

bool visitedNodes[MAX_NODES];

struct Node {
	int id;
	int distance;

	Node(int id, int distance): id(id), distance(distance) {}

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
};

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	vector<Node> graph[N];

	for (int i = 0; i < E; i++) {
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);

		graph[A - 1].push_back(Node(B - 1, L));
		graph[B - 1].push_back(Node(A - 1, L));
	}

	priority_queue<Node, vector<Node>, greater<Node>> queue;

	int sum = 0;
	queue.push(Node(0, 0));

	while (!queue.empty()) {
		Node node = queue.top();
		queue.pop();

		if (visitedNodes[node.id]) {
			continue;
		}

		visitedNodes[node.id] = true;
		sum += node.distance;

		for (int i = 0; i < graph[node.id].size(); i++) {
			queue.push(graph[node.id][i]);
		}
	}

	printf("%d", sum);
	return 0;
}