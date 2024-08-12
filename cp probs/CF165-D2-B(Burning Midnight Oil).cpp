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

ll fn(ll v, ll k){
	ll tot = 0;
	while(v > 0){
		tot += v;
		v/=k;
	}
	return tot;
}

ll BSearch(ll n, ll k, function<ll(ll, ll)> fn){
	ll start = 1;
	ll end = n;
	ll mid;
	while(start < end){
		mid = start + (end-start)/2;
		if(fn(mid, k) < n)	start = mid + 1;
		else	end = mid;
	}
	//if(fn(start, k) < n)	return -1;
	return start;
}

int main(){
	ll n, k;
	cin >> n >> k;
	cout <<BSearch(n, k, fn) << endl;
	return 0;
}

