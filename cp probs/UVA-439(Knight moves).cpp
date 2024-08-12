//Knight moves
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

pair<int, int> giveCoords(string c){
	map<char, int> ltn{{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}};
	if(c[0] <= 'a' && c[0] >= 'h')
		return make_pair(-1, -1);
	return make_pair(ltn[c[0]], (int)(c[1]-'0'));
}

vector<pair<int,int>> giveNeighbours(pair<int, int> coords){
	vector<pair<int, int>> neighbors;
	int &i = coords.first;
	int &j = coords.second;
	for(auto c: vector<pair<int, int>>{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}}){
		if(c.first + i <= 0 || c.second + j <= 0 || c.first + i > 8 || c.second + j > 8)
			continue;
		neighbors.push_back(make_pair(c.first + i, c.second + j));
	}
	return neighbors;
}

bool isVisited(const vector<pair<int, int>> &path , const pair<int, int> &node){
	for(auto &i: path)
		if(node == i)
			return true;
	return false;
}

vector<vector<pair<int, int>>>BFSPath(const pair<int, int> &start, const pair<int, int> &end){
	queue<vector<pair<int, int>>> q;
	vector<vector<pair<int, int>>> paths;
	vector<pair<int,int>> init_path;

	init_path.push_back(start);
	q.push(init_path);


	while(!q.empty()){
		vector<pair<int, int>> front = q.front();
		q.pop();

		if(front[front.size()-1] == end){
			paths.push_back(front);
			break;
		}

		for(auto &i: giveNeighbours(front[front.size()-1])){
			if(isVisited(front, i))
				continue;
			vector<pair<int, int>> newpath(front);
			newpath.push_back(i);
			q.push(newpath);
		}
	}
	return paths;
}

int BFSPathcnt(const pair<int, int> &start, const pair<int, int> &end){
	queue<vector<pair<int, int>>> q;
	vector<vector<pair<int, int>>> paths;
	vector<pair<int,int>> init_path;

	init_path.push_back(start);
	q.push(init_path);


	while(!q.empty()){
		vector<pair<int, int>> front = q.front();
		q.pop();

		if(front[front.size()-1] == end){
			return front.size()-1;
		}

		for(auto &i: giveNeighbours(front[front.size()-1])){
			if(isVisited(front, i))
				continue;
			vector<pair<int, int>> newpath(front);
			newpath.push_back(i);
			q.push(newpath);
		}
	}
	return -1;
}

int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	string st, end;
	while(cin >> st >> end){
		pair<int, int> s = giveCoords(st);
		pair<int, int> e = giveCoords(end);
		// for(auto i: BFSPath(s, e)){
		// 	for(auto j: i){
		// 		cout << '(' << j.first << ',' << j.second << ')' << " ";
		// 	}
		// 	cout << endl;
		// }
		int sol = BFSPathcnt(s, e);
		cout << "To get from " << st <<" to " << end << " takes " << sol << " knight moves." << endl;
		// fout << "To get from " << st <<" to " << end << " takes " << sol << " knight moves." << endl;

	}
	// fout.close();
	return 0;
}