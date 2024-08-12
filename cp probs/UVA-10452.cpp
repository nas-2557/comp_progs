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

map<char, char> next_tile {{'@','I'}, {'I','E'}, {'E','H'}, {'H','O'}, {'O','V'}, {'V','A'}, {'A','#'}};
enum dir {left = 0, forth, right};
class CobPath{
	private:
		ll l, w;
		vector<vector<char>> tiles;
		vector<dir> path;

		void dfs(ll r, ll c){
			if(!next_tile[this->tiles[r][c]])
				return;
			if(this->tiles[(r!=0)?r-1:r][c] == next_tile[this->tiles[r][c]])
				path.push_back(forth), dfs(r-1,c);
			else if(this->tiles[r][(c!=0)?c-1:c] == next_tile[this->tiles[r][c]])
				path.push_back(dir::left), dfs(r,c-1);
			else if (this->tiles[r][(c!=w-1)?c+1:c] == next_tile[this->tiles[r][c]])
				path.push_back(dir::right), dfs(r,c+1);
			else 
				return;
			return;
		}
	public:
	CobPath(ll l, ll w, vector<vector<char>> tiles):l(l), w(w), tiles(tiles){}
	vector<dir> find_path(){
		auto pos = find(this->tiles[l-1].begin(), this->tiles[l-1].end(), '@');
		if(pos == this->tiles[l-1].end())
			return this->path;
		dfs(l-1,pos-this->tiles[l-1].begin());
		return this->path;
	}

};
int main(){
	ll t, l, w;
	vector<vector<char>> tiles;
	cin >> t;
	while(t--){
		cin >> l >> w;
		tiles = vector<vector<char>>(l, vector<char>(w,'o'));
		for(ll i = 0; i < l; i++)
			for(ll j = 0; j < w; j++)
				cin >> tiles[i][j];
		CobPath cobpath(l, w, tiles);
		for(auto i: cobpath.find_path())
			cout << ((i == forth)?"forth ":(i == dir::left)?"left ":"right ");
		cout << "\n";
	}
	return 0;
}	