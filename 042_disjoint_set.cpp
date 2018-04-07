/*
ª•÷ ºØ∫œ
*/
#include<iostream>
#include<vector>

using namespace std;

class DisjointSet
{
	public:
		vector<int> rank, p;
		
		DisjointSet(){}
		DisjointSet(int size)
		{
			rank.resize(size,0);
			p.resize(size,0);
			for(int i = 0; i < size; i++)
				makeSet(i);
		}
		
		void makeSet(int x)
		{
			p[x] = x;
			rank[x] = 0;
		}
		
		bool same(int x, int y)
		{
			return findSet(x) == findSet(y);
		}
		
		void unite(int x, int y)
		{
			link(findSet(x), findSet(y));
		}
		
		void link(int x, int y)
		{
			if( rank[x] > rank[y] )
			{
				p[y] = x;
			}
			else
			{
				p[x] = y;
				if( rank[x] == rank[y] )
				{
					rank[y]++;
				}	
			}
		}
		
		int findSet(int x)
		{
			if( x!= p[x] )
			{
				p[x] = findSet(p[x]);
			}
			return p[x];
		}
};

int main()
{
	int i, n, a, b, q, t;
	
	scanf("%d %d", &n, &q);
	
	DisjointSet ds = DisjointSet(n);
	
	for(i = 0; i < q; i++)
	{
		scanf("%d %d %d", &t, &a, &b);
		if(t == 0)
		{
			ds.unite(a,b);
		}			
		else if(t == 1)
		{
			if(ds.same(a, b))
				printf("1\n");
			else
				printf("0\n");
		}
	}
	
	return 0;
}
/*
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
*/