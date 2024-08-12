#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
#define ll long long ll

ll gcd(ll a, ll b){
	if(b==0)
		return a;
	return gcd(b, (a%b));
}

ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

ll divisors(ll lvl, ll id, const ll arr[], ll target, ll l = 1){
	if(id == 5)
		return 0;
	ll res = 0;
	
	res += divisors(lvl, id+1, arr, target, l );

	l = lcm(arr[id], l);
	res += (lvl%2==0)?target/l:-target/l;

	res += divisors(lvl+1, id+1, arr, target, l);
	return res;
}
ll main()
{
	ll t;
	ll n, m, a, d, ar[4];
	cin >> t;
	while (t--){
		cin >> n >> m >> a >> d;
		ar[0] = a;
		ar[1] = a + d;
		ar[2] = a + 2 * d;
		ar[3] = a + 3 * d;
		ar[4] = a + 4 * d;

		cout << (m-n+1)-(divisors(0, 0, ar, m) - divisors(0, 0, ar, n-1)) << endl;
	}
	return 0;
}

