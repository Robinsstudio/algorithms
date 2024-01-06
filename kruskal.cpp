#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int graphNodeA;
	int graphNodeB;
	int weight;

	bool operator<(const Edge& other) const {
		return weight < other.weight;
	}
};

struct TreeNode {
	int depth = 1;
	TreeNode* parent = this;
};

TreeNode* findRoot(TreeNode* node) {
	if (node->parent != node) {
		node->parent = findRoot(node->parent);
	}

	return node->parent;
}

bool mergeTrees(TreeNode* treeA, TreeNode* treeB) {
	TreeNode* rootA = findRoot(treeA);
	TreeNode* rootB = findRoot(treeB);

	if (rootA == rootB) {
		return false;
	}

	if (rootA->depth < rootB->depth) {
		rootA->parent = rootB;
		rootB->depth += rootA->depth;
		return true;
	}

	rootB->parent = rootA;
	rootA->depth += rootB->depth;
	return true;
}

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	TreeNode treeNodes[N];
	vector<Edge> edges(E);

	for (int i = 0; i < E; i++) {
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);

		edges[i].graphNodeA = A - 1;
		edges[i].graphNodeB = B - 1;
		edges[i].weight = L;
	}

	sort(edges.begin(), edges.end());

	int sum = 0;
	for (int i = 0; i < E; i++) {
		Edge edge = edges[i];

		if (mergeTrees(&treeNodes[edge.graphNodeA], &treeNodes[edge.graphNodeB])) {
			sum += edge.weight;
		}
	}

	printf("%d", sum);
	return 0;
}