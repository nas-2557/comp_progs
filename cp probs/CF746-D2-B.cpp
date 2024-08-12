//Decoding
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
	int n, lo, hi;
	cin >> n;
	string str, str2(n,'0');
	cin >> str;
	lo = (n-1)/2;
	hi = (n-1)/2 + 1;
	if(str.length()%2 != 0){
		str2[lo] = str[0];
		lo-=1;
		str.erase(0,1);
	}
	for(int i = 0; i < str.length(); i+=2){
		str2[lo] = str[i];
		str2[hi] = str[i+1];
		hi++;
		lo--;
	}
	cout << str2 << endl;
	return 0;
}