#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<complex>
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

double dist(pair<int, int> a, pair<int, int> b){
			complex<double> x(a.first, a.second);
			complex<double> y(b.first, b.second);
			return abs(x - y);
		}

int main(){
	while(true){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dist({a,b}, {c, d}) << endl;
    }
    return 0;
}