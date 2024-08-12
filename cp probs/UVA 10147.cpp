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

vector<pair<int, int>> edges;

class Graph{
	private:
		class DSU{
			private:
				vector<int> parent;
				vector<int> rank;
			
			public:
				DSU(int s){
					parent = vector<int>(s);
					for(int i = 0; i < s; i++)	parent[i] = i;
					rank = vector<int>(s, 1);
				}

				int find(int f){
					if(parent[f] == f)
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
					else{
						parent[y] = x;
						rank[x]++;
					}
				}
		};

		double dist(pair<int, int> &a, pair<int, int> &b){
			int &x1 = a.first, &x2 = b.first, &y1 = a.second, &y2 = b.second;
			double res = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
			return res;
		}

		void createEdges(){
		for(int i = 0 ; i < points.size()-1; i++){
			for(int j = i+1; j < points.size(); j++){
			edgelist.push_back({get<0>(points[i]), get<0>(points[j]), dist(get<1>(points[i]), get<1>(points[j]))});
			}
		}
		}

		vector<tuple<int, pair<int, int>>> points;
		vector<tuple<int, int, double>> edgelist;
		map<pair<int, int>, bool> perm_edges;

	public:
		void addPoint(int a, int b, int i){
			this->points.push_back({i, {a, b}});
		}

		void addPermEdge(int a, int b){
			perm_edges[{a, b}] = true;
		}

		void kruskal(){
			DSU D(points.size());
			bool flag = false;
			createEdges();
			for(auto i: perm_edges)	D.uni(i.first.first - 1, i.first.second - 1);
			sort(edgelist.begin(), edgelist.end(), [](tuple<int, int, double>a, tuple<int, int, double>b){ return get<2>(a) < get<2>(b);});
			for(auto i: edgelist){
				int &a = get<0>(i), &b = get<1>(i);
				// if(perm_edges[{a, b}]){
				// 	continue;
				// }
				int x = D.find(a-1); 
				int y = D.find(b-1);

				if(x+1 != y+1){
					cout << a << " " << b << endl;
					flag = true;
					edges.push_back({a,b});
					D.uni(a-1, b-1);
				}
			}
			if(!flag)
				cout << "No new highways need" << endl;
		}
};

int main(){
	ofstream fout;
	fout.open("output.txt");
	int t;
	cin >> t;
	cin.ignore(1000,'\n');
	while(t--){
		int n;
		Graph G;
		cin >> n;
		int i = 1;
		while(n--){
			int a, b;
			cin >> a >> b;
			G.addPoint(a, b, i);
			i++;
		}
		int e;
		cin >> e;
		while(e--){
			int a, b;
			cin >> a >> b;
			G.addPermEdge(a, b);
		}
		G.kruskal();
		if(edges.size() == 0)
		fout << "No new highways need" << endl;
		for(auto i: edges)	
		fout << i.first << " " << i.second << endl;
		if(t!=0) {fout << endl; cout << endl;}
		cin.ignore(1000, '\n');
	}
	fout.close();
}