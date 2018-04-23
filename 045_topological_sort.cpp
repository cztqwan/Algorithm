/*
拓扑排序（广度优先搜索实现）
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;
static const int MAX = 100000;
static const int INFTY = 1 << 29;

vector<int> G[MAX];
list<int> out;
bool V[MAX];
int N;
int indeg[MAX];

void bfs(int s) {
    queue<int> q;
    q.push(s);
	V[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        out.push_back(u);
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && !V[v]) {
                V[v] = true;
                q.push(v);
            }
        }
    }
}

void tsort() {
    for (int i = 0; i < N; i++) {
        indeg[i] = 0;
    }

    for (int u = 0; u < N; u++) {
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            indeg[v]++;
        }
    }


    for (int u = 0; u < N; u++) {
        if (indeg[u] == 0 && !V[u])
            bfs(u);
    }

    for (list<int>::iterator it = out.begin(); it != out.end(); it++)
        cout << *it << endl;
}
int main()
{
    int s, t, M;
    scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
        V[i] = false;
    }
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        G[s].push_back(t);
    }

    tsort();
    return 0;
}
/*
6 6
0 1
1 2
3 1
3 4
4 5
5 2
*/