	//Combination
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

	int gcd(int a, int b){
		if(b==0)	return a;
		return gcd(b, a%b);
	}

	ll comb(int n, int r){
		if(r < n-r) r = n - r;
		ll prod = 1;
		vector<int> numerator;
		vector<int> denominator;
		for(int i = n; i > r; i--)
			numerator.push_back(i);
		for(int i = n-r; i > 0; i--)
			denominator.push_back(i);
		for(auto &i: denominator){
			for(auto &j: numerator){
				int g;
				if(i == 1)	break;
				int a = i;
				int b = j;
				g = gcd(a, b);
				if(g != 1)
					i /= g, j/=g;
			}
		}
		for(auto i: numerator)
			prod *= i;
		return prod;
	}

	int main(){
		fastIO();
		int n, r;
		ofstream fout;
		fout.open("output.txt");
		vector<int> numerator;
		while(cin >> n >> r){
			if(n == 0 && r == 0)
				break;
			cout << n << " things taken " << r << " at a time is " << comb(n, r) << " exactly." << endl;
			fout << n << " things taken " << r << " at a time is " << comb(n, r) << " exactly." << endl;
		}
		return 0;
	}