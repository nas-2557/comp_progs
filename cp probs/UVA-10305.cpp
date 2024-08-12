// Ordering Tasks
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
using namespace std;
#define ll long long int

class TaskGraph{
	private:
		map<ll, vector<short>> adj_list;
		map<ll, bool> visited;
		vector<short> topolist;
		ll size;

		void topoSort(ll node){
			visited[node] = true;
			for(auto i: adj_list[node]){
				if(visited[i] == true)
					continue;
				topoSort(i);
			}
			topolist.push_back(node);
		}

	public:
		TaskGraph(ll size): size(move(size)){}
		void addEdge(ll i, ll j){
			this->adj_list[j].push_back(i);
		}
		void findOrder(){
			for(ll i = 0; i < size;  i++){
				if(visited[i+1] == true)
					continue;
				topoSort(i+1);
			}
		}
		void prllList(){
			for(auto i: topolist){
				cout << i << " ";
			}
			cout << endl;
		}
};

int main(){
	ll n, m;
	ll i, j;
	while(cin >> n && cin >> m){
		if(n == 0 && n == 0){
			break;
		}
		TaskGraph tg(n);
		while(m--){
			cin >> i >> j;
			assert((i <= n)&&(j <= n));
			tg.addEdge(i,j);
		}
		tg.findOrder();
		tg.prllList();
	}
	
}