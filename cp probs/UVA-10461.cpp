//Difference
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
using namespace std;
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

void Time(int node, const map<int, int> &nodes, const map<int, vector<int>> &adj_nodes, int &cnt, map<int, bool> &visited){
	visited[node] = true;
	cnt += nodes.at(node);
	auto i = adj_nodes.find(node);
	if(i == adj_nodes.end())
		return;
	for(auto i: adj_nodes.at(node)){
		if(visited[i] == true)
			continue;
		Time(i, nodes, adj_nodes, cnt, visited);
	}

}

int Time(int node, const map<int, int> &nodes, const map<int, vector<int>> &adj_nodes){
	map<int, bool> visited;
	int cnt = -nodes.at(node);
	Time(node, nodes, adj_nodes, cnt, visited);
	return cnt;
}

int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	int v, e, t, x, y, q, qu, iter=0;
	while(true){
		stringstream ss;
		iter++;
		map<int, int> nodes;
		map<int, vector<int>> adj_nodes;
		map<int, vector<int>> adj_nodes_inv;
		int tot_time = 0;

		cin >> v >> e;
		if(v == 0 && e == 0)
			break;
		for(int i = 0; i < v; i++){
			cin >> t;
			nodes[i + 1] = t;
			tot_time += t;
		}
		while(e--){
			cin >> x >> y;
			adj_nodes[y].push_back(x);
			adj_nodes_inv[x].push_back(y);
		}
		cin >> q;
		while(q--){
			cin >> qu;
			int diff = tot_time - nodes[qu] - Time(qu, nodes, adj_nodes_inv) - Time(qu, nodes, adj_nodes);
			ss << diff << endl; 
		}
		cin.ignore(1000, '\n');
		cout << "Case #" << iter <<":" << endl;
		cout << ss.str() << endl;
		// fout << "Case #" << iter <<":" << endl;
		// fout << ss.str() << endl;
		
	}
	// fout.close();
	return 0;
}