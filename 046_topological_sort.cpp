/*
拓扑排序（深度优先搜索实现）
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

void dfs(int u) {
    V[u] = true;

    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if ( !V[v] )
            dfs(v);
    }
    out.push_front(u);
}

void tsort() {
    for (int i = 0; i < N; i++) {
        if ( !V[i] )
            dfs(i);
    }

    for (list<int>::iterator it = out.begin(); it != out.end(); it++)
        cout << *it << endl;
}
int main()
{
    int s, t, M;
    cin >> N >> M;
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