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
		map<int, map<int, vector<int>>> adj_list;
		vector<vector<pair<int,int>>> paths;
		map<int, bool> visited_col;

		bool isVisited(int node, vector<pair<int, int>> &path){
			for(auto i: path){
				if(node == i.first)
					return true;
			}
			return false;
		}
		
	public:
		Graph(int v, int e):v(v), e(e){}
		void addEdge(int a, int b, int c){
			adj_list[a][b].push_back(c);
			adj_list[b][a].push_back(c);
		}

		void bfs(int start, int end){
			paths.clear();
			visited_col.clear();
			queue<vector<pair<int, int>>> q;
			q.push({{start, -1}});

			while(!q.empty()){
				vector<pair<int, int>> path = q.front();
				q.pop();
				pair<int, int> last = path[path.size()-1];

				if(last.first == end && !visited_col[last.second]){ 
						paths.push_back(path); 
						visited_col[last.second] = true;
						continue;
					}

				for(auto i = adj_list[last.first].begin(); i != adj_list[last.first].end(); i++){
					if(isVisited(i->first, path))	continue;
					for(auto j : i->second){
						if(path.size() != 1)	if(j != last.second)	continue;
						vector<pair<int, int>> newpath(path);
						newpath.push_back({i->first, j});
						q.push(newpath);
					}
				}
			}
		}

		void printPaths(){
			for(auto i: paths){
				for(auto j: i){
					cout << "(" << j.first << "," << j.second << ")" << " ";
				}
				cout << endl;
			}
		}

		void printCnt(){
			cout << paths.size();
		}	
};
 
int main(){
	fastIO();
	// ofstream fout;
	// ifstream fin;
	// fout.open("output.txt");
	// fin.open("input.txt");
	// FILE *fp = freopen("output.txt", "w", stdout);
	int v, e, q;
	cin >> v >> e; Graph g(v,e);
	while(e--){
		int a, b, c;
		cin >> a >> b >> c;
		g.addEdge(a, b, c);
	}

	cin >> q;
	while(q--){
		int start, target;
		cin >> start >> target;
		g.bfs(start, target);
		g.printCnt();
		cout << endl;
	}
	// fclose(fp);
	// fout.close();
	// fin.close();
	return 0;
}