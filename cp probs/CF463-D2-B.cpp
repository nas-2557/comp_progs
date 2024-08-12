//pylons
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


int main(){
	fastIO();
	int n, a;
	int cost = 0;

	cin >> n;
	vector<int> pylons;
	pylons.push_back(0);

	for(int i = 0; i < n ; i++){
		cin >> a;
		pylons.push_back(a);
	}
	cout << *max_element(pylons.begin(), pylons.end()) << endl;
	return 0;
}