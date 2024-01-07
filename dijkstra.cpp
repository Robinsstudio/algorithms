#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NODES = 1000;
const int MAX_DISTANCE = 1000 * 1000 * 1000;

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
	int N, E, F, T;
	scanf("%d%d%d%d", &N, &E, &F, &T);

	int distances[N];
	int parents[N];

	for (int i = 0; i < N; i++) {
		distances[i] = MAX_DISTANCE;
	}

	vector<Node> graph[N];

	for (int i = 0; i < E; i++) {
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);

		graph[A - 1].push_back(Node(B - 1, L));
		graph[B - 1].push_back(Node(A - 1, L));
	}

	priority_queue<Node, vector<Node>, greater<Node>> queue;

	int startingNode = F - 1;
	visitedNodes[startingNode] = true;
	distances[startingNode] = 0;
	queue.push(Node(startingNode, 0));

	while (!queue.empty()) {
		Node node = queue.top();
		queue.pop();

		for (int i = 0; i < graph[node.id].size(); i++) {
			Node neighbor = graph[node.id][i];

			if (!visitedNodes[neighbor.id]) {
				int distance = distances[node.id] + neighbor.distance;

				if (distances[neighbor.id] > distance) {
					distances[neighbor.id] = distance;
					parents[neighbor.id] = node.id;
				}

				visitedNodes[node.id] = true;
				queue.push(Node(neighbor.id, distance));
			}
		}
	}

	int endingNode = T - 1;
	printf("%d\n", distances[endingNode]);
	printf("%d ", endingNode + 1);

	int node = endingNode;
	while (node != startingNode) {
		node = parents[node];
		printf("%d ", node + 1);
	}

	return 0;
}