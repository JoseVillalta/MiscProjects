// UVa 10034 - Freckles

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;

struct edge {
	double cost;
	int dest;
};

bool operator <(const edge & a, const edge & b) {
	return a.cost > b.cost;
}

int main() {
	int c;
	for (cin >> c; c; c--) {
		double x[100], y[100], d[100][100];
		int n;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			for (int j = 0; j < i; j++)
				d[j][i] = d[i][j] = pow(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2), 0.5);
		}

		priority_queue<edge> q;
		bool marked[100];
		memset(marked, false, n);
		double sol = 0;
		int m = 0;

		for (int j = 1; j < n; j++) {
			marked[m] = true;
			for (int i = 1; i < n; i++) {
				edge e;
				e.cost = d[m][i];
				e.dest = i;
				q.push(e);
			}
			if (!q.empty()) {
				edge min = q.top();
				while (marked[min.dest]) {
					q.pop();
					min = q.top();
				}
				m = min.dest;
				sol += min.cost;
			}
		}

		printf("%.2f\n", sol);
		if (c > 1)
			cout << endl;
	}
	return 0;
}