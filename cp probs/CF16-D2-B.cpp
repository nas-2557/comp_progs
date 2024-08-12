//Burglar and Matchsticks
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
#include<valarray>
using namespace std;
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fr(n) for (int i = 0; i < (n); i++)

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

bool match_listSort(pair<int, int> a, pair<int,int> b){
	return a.second > b.second;
}
int main(){
	fastIO();
	int n, m, ai, bi;
	string vals;
	vector<pair<int, int>> match_list(m);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		// cin >> vals;
		// istringstream iss(vals);
		// iss >> ai >> bi;
		cin >> ai >> bi;
		match_list.push_back(make_pair(ai, bi));
	}
	sort(match_list.begin(), match_list.end(), match_listSort);

	int rem = n, cnt = 0;
	auto iter = match_list.begin();
	while(rem >= (*iter).first && iter != match_list.end()){
		cnt += (*iter).first * (*iter).second;
		rem -= (*iter).first;
		iter++;
	}
	if(iter != match_list.end()) cnt += rem * (*iter).second;
	rem = 0;

	cout << cnt << endl;

	return 0;
}