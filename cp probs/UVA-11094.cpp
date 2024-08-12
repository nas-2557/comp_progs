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

class Map{
	public:
		vector<vector<char>> world_map;
		int m, n;
		char land;
		pair<int, int> king_coords;
		vector<vector<bool>> visited;

		vector<pair<int, int>> findNeighbors(pair<int, int> point){
			vector<pair<int, int>> neighbors;
			int &a = point.first;
			int &b = point.second;
		
			for(auto i: {-1, 0, 1}){
					if((a+i >= 0 && a+i <= m-1) && (world_map[a+i][b] == land))
						neighbors.push_back(make_pair(a+i,b));
					if(world_map[a][(b+i < 0)? n-1:(b+i > n-1)? 0: b+i] == land)
						neighbors.push_back(make_pair(a, (b+i < 0)? n-1:(b+i > n-1)? 0: b+i));
			}
			return neighbors;
		}
		
		int findContSizedfs(pair<int, int> point){
			int &a = point.first;
			int &b = point.second;
			int cnt = 1;
			visited[a][b] = true;
			
			for(auto i: findNeighbors(point)){
				if(visited[i.first][i.second] == true || world_map[i.first][i.second] != land)
					continue;
				cnt += findContSizedfs(i);
			}
			return cnt;	
		}

		int ContSize(){
			findContSizedfs(king_coords);
			int max_cont_size = 0;
			for(int i = 0; i < m; i++)
				for(int j = 0; j < m; j++){
					if(visited[i][j] != true && world_map[i][j] == land)
						max_cont_size = max(max_cont_size, findContSizedfs(make_pair(i,j)));
				}
			return max_cont_size;
		}
};
 
int main(){
	fastIO();
	// ofstream fout;
	// ifstream fin;
	// fin.open("input.txt");
	// fout.open("output.txt");
	int m;
	while(cin >> m){
		Map mp; int ka, kb;
		mp.m = m;
		cin >> mp.n;
		mp.world_map = vector<vector<char>>(mp.m, vector<char>(mp.n, '.'));
		mp.visited = vector<vector<bool>>(mp.m, vector<bool>(mp.n, false));
		for(int i = 0; i < mp.m; i++)
			for(int j = 0; j < mp.n; j++)
				cin >> mp.world_map[i][j];
		cin >> ka >> kb;
		mp.king_coords = make_pair(ka, kb);
		mp.land = mp.world_map[ka][kb];
		cin.ignore(1000, '\n');
		int res = mp.ContSize();
		cout << res << endl;
		// fout << res << endl;
	}
	// fin.close();
	// fout.close();
	return 0;
}