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


 
int main(){
	fastIO();
	// ofstream fout;
	// ifstream fin;
	// fout.open("output.txt");
	// fin.open("input.txt");
	int n;
	while(cin >> n){
		if(n == 0)	break;
		int a, b, s = 0, o = 0;
		vector<pair<int, int>> points;
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			points.push_back({a, b});
		}
		pair<int, int> mid_point = points[n/2];
		for(auto &i: points){
			if(i.first > mid_point.first && i.second > mid_point.second || i.first < mid_point.first && i.second < mid_point.second)
				s++;
			else if(i.first > mid_point.first && i.second < mid_point.second || i.first < mid_point.first && i.second > mid_point.second)
				o++;
		}
		cout << s << " " << o << endl;
	}
	// fout.close();
	// fin.close();
	return 0;
}