#include <cstdio>

struct Node {
	int depth = 1;
	Node* parent = this;
};

Node* findRoot(Node* node) {
	if (node->parent != node) {
		node->parent = findRoot(node->parent);
	}

	return node->parent;
}

bool mergeTrees(Node* treeA, Node* treeB) {
	Node* rootA = findRoot(treeA);
	Node* rootB = findRoot(treeB);

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
	int N, R;
	scanf("%d%d", &N, &R);

	Node nodes[N];

	for (int i = 0; i < R; i++) {
		int A, B;
		scanf("%d%d", &A, &B);

		if (mergeTrees(&nodes[A], &nodes[B])) {
			printf("%d %d\n", A, B);
		}
	}

	return 0;
}