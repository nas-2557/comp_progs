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
		map<int, vector<pair<int, int>>> adj_list;
	
	public:
		Graph(int v, int e):v(v), e(e){}
		void addEdge(int a, int b, int w){
			adj_list[a].push_back({w, b});
			adj_list[b].push_back({w, a});
		}

		int prim(){
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
			map<int, int> resmst;
			map<int, bool> mst;
			int sum = 0;
			pair<int, int> rep = {-1, INT_MAX};
			pq.push({0, 1});

			while(!pq.empty()){
				pair<int, int> front = pq.top();
				pq.pop();
				int &node = front.second;

				if(mst[node]){
					rep = {node, front.first};
					continue;
				}
				sum += front.first;
				resmst[node] = front.first;
				mst[node] = true;
				for(auto &i: adj_list[node]){
					int &nnode = i.second;
						if(!mst[nnode])
							pq.push(i);
				}
			}

			return sum;
		}


};

int main(){
	ofstream fout("output.txt");
	int t;
	cin >> t;
	while(t--){
		int n, m, sum1, a, b, w;
		cin >> n >> m;
		Graph G(n, m);
		while(m--){
			cin >> a >> b >> w;
			G.addEdge(a, b, w);
		}
		sum1 = G.prim();
		cout << sum1 << endl;
	}
	fout.close();
}