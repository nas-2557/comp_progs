#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
#include<map>
using namespace std;
#define ll long long int

map<char, short> tile {{'x', 0}, {'@', 1}, {'.', 2}};

class BattleShip{
	private:
		vector<vector<char>> tiles;
		vector<vector<bool>> visited;
		ll size;

		bool dfs(ll r, ll c)
		{
			bool flag = false;
			this->visited[r][c] = true;

			if(this->tiles[r][c] == 'x')
				flag = true;

			for(auto i: vector<ll>{-1, 1}){
				ll x = r + i;
				ll y = c + i;

				if(x >= 0 && x < size)
					if(tile[this->tiles[x][c]] != 2 && this->visited[x][c] == false)
						if(dfs(x, c) == true)
							flag = true;

				if(y >= 0 && y < size)
					if(tile[this->tiles[r][y]] !=2 && this->visited[r][y] == false)
						if(dfs(r, y) == true)
							flag = true;
			}	
			return flag;
		}
	
	public:
		BattleShip(vector<vector<char>> tiles, ll size):tiles(move(tiles)), size(move(size)){
			this->visited = vector<vector<bool>>(size, vector<bool>(size, false));
		}

		friend ll find_ships(BattleShip &b);
};

ll find_ships(BattleShip &b){
	ll cnt = 0;
	for(ll i = 0; i < b.size; i++)
		for(ll j = 0; j < b.size; j++){
				if(tile[b.tiles[i][j]] != 2 && b.visited[i][j] == false)
					if(b.dfs(i, j) == true)
						cnt++;
			}
	return cnt;
}


int main(){
	ll t, c=1, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<vector<char>> tiles = vector<vector<char>>(n, vector<char>(n, 'o'));
		for(ll i = 0; i < n; i++)
			for(ll j = 0; j < n; j++)
				cin >> tiles[i][j];
		BattleShip b {BattleShip(tiles, n)};
		cout << "Case " << c++ << ": " << find_ships(b) << endl;
	}
}	