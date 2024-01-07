#include <cstdio>

const int MAX_NODES = 500;
const int MAX_DISTANCE = 1000 * 1000 * 1000;

int distances[MAX_NODES][MAX_NODES];

int main() {
	int N, E;
	scanf("%d%d", &N, &E);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			distances[i][j] = MAX_DISTANCE;
		}
		distances[i][i] = 0;
	}

	for (int i = 0; i < E; i++) {
		int A, B, L;
		scanf("%d%d%d", &A, &B, &L);

		distances[A - 1][B - 1] = L;
		distances[B - 1][A - 1] = L;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int distance = distances[j][i] + distances[i][k];
				if (distances[j][k] > distance) {
					distances[j][k] = distance;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", distances[i][j]);
		}
		printf("\n");
	}

	return 0;
}