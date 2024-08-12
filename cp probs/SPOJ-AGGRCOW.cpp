#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
//#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<fstream>
#include<cmath>
#include<functional>
using namespace std;
#define ll long long int
#define ld long double

bool can(vector<ll> &v, ll c, ll dist){
	long int cnt = 0;
	ll current = v[0];
	c--;
	for(int i = 0; i < v.size(); i++){
		if(v[i] - current >= dist){
			cnt ++;
			current = v[i];
			if(cnt >= c) break;
		}
	}
	if(cnt >= c)
		return true;
	return false;
}

ll minDist(vector<ll> &v, ll c){
	ll start = 1;
	ll end = v[v.size()-1];
	ll mid;
	while(start < end){
		mid = start + (end-start)/2;
		if(can(v, c, mid))	start = mid + 1;
		else end = mid;
	}
	return start - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	ll n, c, x;
	set<ll> s;
	vector<ll> v;
	cin >> t;
	while(t--){
		cin >> n >> c;
		for(int i = 0; i < n; i++){
			cin >> x;
			s.insert(x);
		}
		for(auto i: s)
			v.push_back(i);
		cout << minDist(v, c) << endl;
		s.clear();
		v.clear();
	}
	return 0;
}

