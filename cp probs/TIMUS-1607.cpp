//Taxi
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

int form(int a1, int d1, int a2, int d2){
	if(a1 > a2)
		return a1;
	int res = (a2 - a1)/(d2 + d1);
	d2 = -d2;
	res ++;
	if((a1+(res-1)*d1) == (a2+(res-1)*d2))
		return (a1+(res-1)*d1);
	if((a1+(res)*d1) >= (a2+(res-1)*d2))
		return (a2+(res-1)*d2);
	return (a1+(res)*d1);
}

int main(){
	fastIO();
	//ofstream fout;
	//fout.open("output.txt");
	int a1, a2, d1, d2;
	cin >> a1 >> d1 >> a2 >> d2;
	cout << form(a1, d1, a2, d2) << endl;
	return 0;
}