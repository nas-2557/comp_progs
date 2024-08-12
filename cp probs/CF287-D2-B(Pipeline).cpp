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

ll fn(ll n, ll k){
	ll t1 = ((2*k) + (1-n)) * n;
	ll tf = t1/2 - n + 1;
	return tf;
}

ll binSearch(ll n, ll k, function<ll(ll, ll)> fn){
	if(n == 1) return 0;
	ll start = 1;
	assert(k >= 2);
	ll end = k-1;
	ll mid;
	while(start < end){
		mid = start + (end-start)/2;
		if(n > fn(mid, k)) start = mid + 1; 
		else end = mid;
	}
	if(fn(start, k) < n)
		return -1;
	return start;
}

int main(){
	ll n, k;
	cin >> n >> k;
	cout << binSearch(n, k, fn) << endl;
	return 0;
}

