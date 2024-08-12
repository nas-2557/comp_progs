#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<complex>
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
		int s, p;
		vector<pair<int, int>> vertices;

		double dist(pair<int, int> a, pair<int, int> b){
			complex<double> x(a.first, a.second);
			complex<double> y(b.first, b.second);
			return abs(x - y);
		}

	public:
		Graph(int s, int p):s(s), p(p){}

		void addVertex(int a, int b){
			vertices.push_back({a,b});
		}

		vector<pair<double, int>> prim(){
			map<int, bool> mst;
			auto doubleGreater = [](pair<double, int> &a, pair<double, int> &b){return a.first > b.first;}; //smallest value pri
			auto doubleLess = [](pair<double, int> &a, pair<double, int> &b){return a.first < b.first;}; //largest value pri
			priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(doubleGreater)> pq(doubleGreater);
			priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(doubleLess)> respq(doubleLess);
			vector<pair<double, int>> res;
			pq.push({0, 0});

			while(!pq.empty()){
				pair<double, int> front = pq.top();
				pq.pop();
				double &w = front.first; int &v = front.second;
				if(mst[v])	continue;
				mst[v] = true;
				respq.push(front);
				for(int i = 0; i < p; i++){
					if(mst[i] || i == v)
						continue;
					pq.push({dist(vertices[v], vertices[i]), i});
				}
			}

			while(!respq.empty()){
				res.push_back(respq.top());
				respq.pop();
			}
			return res;
		}

		double minD(){
			vector<pair<double, int>> res = prim();
			res.erase(res.begin(), res.begin() + this->s-1);
			return (res.begin())->first;
		}
};

int main(){
	ofstream fout("output.txt");
	int t;
	cin >> t;
	while(t--){
		int s, p;
		cin >> s >> p;
		Graph G(s, p);
		while(p--){
			int x, y;
			cin >> x >> y;
			G.addVertex(x, y);
		}
		cout << fixed << setprecision(2) << G.minD() << endl;
		fout << fixed << setprecision(2) << G.minD() << endl;
	}
	fout.close();
	return 0;
}