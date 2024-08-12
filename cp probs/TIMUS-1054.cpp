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

class Hanoi{
	public:
		int N;
		vector<int> dest_seq;
		int flag = false;

		int toh(int n, int a, int b, int aux){
			if(n == 0)	return 0;
			if(dest_seq[n-1] == a)
				return toh(n-1, a, aux, b);
			else if(dest_seq[n-1] == b)
				return pow(2, n-1) + toh(n-1, aux, b, a);
			return flag = true;
		}

};
 
int main(){
	fastIO();
	// ofstream fout;
	// ifstream fin;
	// fout.open("output.txt");
	// fin.open("input.txt");
	Hanoi H; int n; int x;
	cin >> n;
	const int a = n;
	H.N = n;
	while(n--){
		cin >> x;
		H.dest_seq.push_back(x);
	}

	int res = H.toh(H.N, 1, 2, 3);
	cout << ((H.flag == true)? -1: res) << endl;

	// fout.close();
	// fin.close();
	return 0;
}