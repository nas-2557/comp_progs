#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<fstream>
#include<cmath>
#include<functional>
#include<valarray>
#include<numeric>
#include<queue>
#include<optional>
// #include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3")
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fr(n) for (int i = 0; i < n; i++)
 
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class Graph{
	private:
		int v, e;
		vector<vector<int>> edgelist;

		class DSU{
			private:
				map<int, int> parent;
				map<int, int> rank;
			public:
				DSU(int v){
					for(int i = 1; i <= v; i++){
						parent[i] = -1;
						rank[i] = 1;
					}
				}

				int find(int f){
					if(parent[f] == -1)
						return f;
					return parent[f] = find(parent[f]);
				}

				void uni(int a, int b){
					int x = find(a);
					int y = find(b);

					if(x == y)
						return;

					if(rank[x] < rank[y])
						parent[x] = y;
					else if(rank[y] < rank[x])
						parent[y] = x;
					else
						parent[y] = x;
						rank[x]++;
				}

		};
	
	public:
		Graph(int v, int e):v(v), e(e){}

		void addEdge(int a, int b, int w){
			edgelist.push_back({a, b, w});
			sort(edgelist.begin(), edgelist.end(), [](vector<int>&a, vector<int>&b){return a[2] < b[2];});
		}

		pair<int, vector<vector<int>>> kruskal(vector<int> igno = {-1, -1, -1}){
			DSU D(v);
			int sum = 0;
			vector<vector<int>> res;
			for(auto &i: edgelist){
				if(i == igno)
					continue;
				int &a = i[0], &b = i[1], w = i[2];
				int x = D.find(a), y = D.find(b);
				if(x!=y){
					D.uni(a,b);
					sum += w;
					res.push_back({a, b, w});
				}
			}
			if(res.size() != v-1)
				sum = INT_MAX;
			return {sum, res};	
		}

		pair<int, int> twoCosts(){
			vector<vector<int>> res;
			int sum1, sum2 = INT_MAX, temp;
			tie(sum1, res) = kruskal();
			sort(res.begin(), res.end(), [](vector<int>&a, vector<int>&b){return a[2] < b[2];});
			for(int i = 0; i < res.size(); i++){
				tie(temp, ignore) = kruskal(res[i]);
				if(temp <= sum2)
					sum2 = temp;
			}
			return {sum1, sum2};
		}
};

int main(){
	ofstream fout("output.txt");
	int t;
	cin >> t;
	while(t--){
		int n, m, a, b, w, sum1, sum2;
		cin >> n >> m;
		Graph G(n, m);
		while(m--){
			cin >> a >> b >> w;
			G.addEdge(a, b, w);	
		}
		tie(sum1, sum2) = G.twoCosts();
		cout << sum1 << " " << sum2 << endl;
		fout << sum1 << " " << sum2 << endl;
	}
	fout.close();
}