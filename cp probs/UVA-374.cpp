//Big Mod
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

	ll modpower(ll a, ll x, ll m){
		ll val = 1;
		if(x == 0)
			return 1;
		val = modpower(a, x/2, m);
		val = (val*val)%m;
		if(x%2 != 0)
			val = (val*a)%m;
		return val;
	}

	ll modpower2(ll base, ll exp, ll mod) {
		long long result = 1;
		while (exp > 0) {
			if (exp % 2 == 1) { // 
				result = (result * base) % mod;
			}
			base = (base * base) % mod; 
			exp = exp / 2; 
		}
		return result;
	}

	int main(){
		fastIO();
		ll b, p, m;
		while(cin >> b >> p >> m){
		cout << modpower(b, p, m) << endl;
		cin.ignore(1000,'\n');
		}
		return 0;
	}