//Kings Path
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

vector<pair<ll,ll>> findNeighbors(const pair<ll, ll> &node, const multimap<ll, pair<ll, ll>> &valid_tiles){
	const ll &i = node.first;
	const ll &j = node.second;
	vector<pair<ll,ll>> neighbors;
	ll limit = 1e9 -1;
	for(auto a: vector<pair<int, int>>{{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}){
		ll nextx = i + a.first;
		ll nexty = j + a.second; 
		
		if(nextx > limit || nexty > limit || nextx < 0 || nexty < 0)
			continue;

		auto it = valid_tiles.find(nextx);
		while(it != valid_tiles.end() && it->first == nextx){
			pair<ll, ll> range = it->second;
			if(nexty <= range.second && nexty >= range.first){
				neighbors.push_back(make_pair(nextx, nexty)); break;
			}
			it++;
		}

	}
	return neighbors;
}

bool isVisited(pair<ll, ll> &node, vector<pair<ll ,ll>> &vec){
	auto it = find_if(vec.begin(), vec.end(), [&node](const pair<ll, ll> &val) { return val == node;});
	if(it!=vec.end())
		return true;
	return false;
}

vector<pair<ll,ll>> BFSPath(const pair<ll, ll> &start, const pair<ll, ll> &end, multimap<ll, pair<ll, ll>> &valid_tiles){
	queue<vector<pair<ll, ll>>> q;
	vector<pair<ll,ll>> path;
	map<pair<ll, ll>, bool> visited;

	path.push_back(start);
	q.push(path);
	visited[start] = true;
	
	while(!q.empty()){
		vector<pair<ll, ll>> front = q.front();
		q.pop();

		if(front[front.size()-1] == end)
			return front;

		for(auto &i: findNeighbors(front[front.size()-1], valid_tiles)){
			if(visited[i] == true)
				continue;
			if(isVisited(i, front))
				continue;
			vector<pair<ll, ll>> newpath(front);
			newpath.push_back(i);
			visited[i] = true;
			q.push(newpath);
		}
	}	
	return vector<pair<ll, ll>>(0);
}

int BFSPathcnt(const pair<ll, ll> &start, const pair<ll, ll> &end, multimap<ll, pair<ll, ll>> &valid_tiles){
	queue<tuple<pair<ll, ll>, pair<ll, ll>, int>> q;
	map<pair<ll, ll>, bool> visited;
	tuple<pair<ll, ll>, pair<ll, ll>, int> path; 

	path = {start, start, 0};
	q.push(path);
	visited[start] = true;
	
	while(!q.empty()){
		tuple<pair<ll, ll>, pair<ll, ll>, int> front = q.front();
		q.pop();

		if(get<1>(front) == end)
			return get<2>(front);

		for(auto &i: findNeighbors(get<1>(front), valid_tiles)){
			if(visited[i] == true)
				continue;
			// if(isVisited(i, front))
			// 	continue;
			tuple<pair<ll, ll>, pair<ll, ll>, int> newpath(front);
			get<1>(newpath) = i;
			get<2>(newpath)++;
			visited[i] = true;
			q.push(newpath);
		}
	}	
	return -1;
}

int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	pair<ll, ll> start, end;
	int n;
	ll a, b, c;
	multimap<ll, pair<ll, ll>> valid_tiles;

	cin >> start.first >> start.second >> end.first >> end.second;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		valid_tiles.insert({a, make_pair(b, c)});
	}
	
	// int steps = BFSPath(start, end, valid_tiles).size()-1;
	// cout << steps << endl;
	cout << BFSPathcnt(start, end, valid_tiles) << endl;
	// fout.close();
	return 0;
}