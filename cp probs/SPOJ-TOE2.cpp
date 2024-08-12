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

class TTT{
	private:
		vector<vector<char>> ttt;
		map<char, bool> xo_win {{'X', false}, {'O', false}};
		map<char, int> xo_cnt {{'X', 0}, {'O', 0}};
		vector<vector<bool>> visited{3, vector<bool>(3, false)};

		void BFS(pair<int, int> start){
			queue<pair<int, int>> q;
			vector<pair<int,int>> sg;
			map<int,int> i_cnt {{0, 0}, {1,0}, {2,0}};
			map<int,int> j_cnt {{0, 0}, {1,0}, {2,0}};
			int iej = 0;
			int ipj = 0;
			char cur_val = ttt[start.first][start.second];

			q.push(start);
			visited[start.first][start.second] = true;

			while(!q.empty()){
				pair<int, int> front = q.front();
				q.pop();
				const int &i = front.first;
				const int &j = front.second;

				sg.push_back(make_pair(i, j));
				i_cnt[i]++;
				j_cnt[j]++;
				if(i==j)	iej++;
				else if(i+j == 2)	ipj++;
				xo_cnt[cur_val]++;

				for(pair<int, int> c: vector<pair<int,int>>{{0,1},{1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}}){
					if(i+c.first < 0 || j+c.second < 0 || i+c.first >= 3 || j+c.second >= 3) 
						continue;
					if(visited[i+c.first][j+c.second] || ttt[i+c.first][j+c.second] != cur_val )
						continue;
					visited[i+c.first][j+c.second] = true;
					q.push(make_pair(i+c.first, j+c.second));
				}
			}

			for(int i = 0; i < 3; i++)
				if(i_cnt[i] == 3 || j_cnt[i] == 3 || ipj == 3 || iej == 3)
					this->xo_win[cur_val] = true;
		}

	public:
		TTT(vector<vector<char>> ttt): ttt(move(ttt)){}

		bool isValidGame(){
			vector<vector<pair<int, int>>> sgs;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++){
					if(visited[i][j] || ttt[i][j] == '.')
						continue;
					BFS(make_pair(i,j));
				}
			if(xo_cnt['X'] - xo_cnt['O'] == 1){
				if(xo_win['O'] == true)
					return false;
				return true;
			}
			else if(xo_cnt['X'] - xo_cnt['O'] == 0){
				if(xo_win['X'] == true)
					return false;
				return true;
			}
			return false;	
		}

		bool isValidFinalState(){
			vector<vector<pair<int, int>>> sgs;
			for(int i = 0; i < 3; i++)
				for(int j = 0; j < 3; j++){
					if(visited[i][j] || ttt[i][j] == '.')
						continue;
					BFS(make_pair(i,j));
				}
			if(xo_cnt['X'] - xo_cnt['O'] == 1){
				if(xo_win['X'] == true)
					return true;
				return false;
			}
			else if(xo_cnt['X'] - xo_cnt['O'] == 0){
				if(xo_win['O'] == true)
					return true;
				return false;
			}
			return false;	
		}
};	


int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	string n;
	vector<vector<char>> ttt(3, vector<char>(3));
	while(cin >> n){
		if(n == "end") break;
		istringstream iss(n);
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++)
				iss >> ttt[i][j];
		}
		TTT Ttt(ttt);
		// fout << (Ttt.isValidGame()?"valid":"invalid") << endl;
		cout << (Ttt.isValidFinalState()?"valid":"invalid") << endl;
		cin.ignore(1000, '\n');
	}
	// fout.close();
	return 0;
}