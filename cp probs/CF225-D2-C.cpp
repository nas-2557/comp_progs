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
 
class Barcode{
	public:
		vector<vector<char>> barcode;
		int lower_lim, upper_lim;
		int n, m;
		vector<vector<vector<int>>> mem;
		vector<int> cntW;
		enum last_col{BLACK = 0, WHITE, NONE};
		
 
		int repPix(int i, int cnt, int last_colo){
			if(i == m){
				if(cnt < lower_lim)
					return 10e5;
				return 0;
			}

			if(mem[i][cnt][last_colo] != -2)
				return mem[i][cnt][last_colo];
 
			int cntw = cntW[i], cntb = n-cntw, answ = 10e5, ansb = 10e5, ans = 10e5;
			
			if(i==0){
				ansb = cntb + repPix(i+1, 1, BLACK);
				answ = cntw + repPix(i+1, 1, WHITE);
				goto skip;
			}
			if(cnt < upper_lim){
				//Choose same color
				if(last_colo == WHITE)	answ = cntw + repPix(i + 1, cnt+1, WHITE);
				else if(last_colo == BLACK)	ansb = cntb + repPix(i + 1, cnt+1, BLACK);
			}
			
			if(cnt >= lower_lim){
				//Choose diff color
				if(last_colo == WHITE) ansb = cntb + repPix(i+1, 1, BLACK);
				else if(last_colo == BLACK) answ = cntw + repPix(i+1, 1, WHITE);
			}
			skip:
			ans = min(ansb ,answ);
			mem[i][cnt][last_colo] = ans;
			return ans;
		}
};
 
int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	Barcode B;
	cin >> B.n >> B.m >> B.lower_lim >> B.upper_lim;
	B.mem = vector<vector<vector<int>>>(B.m, vector<vector<int>>(B.upper_lim+1, vector<int>(3, -2)));
	B.cntW = vector<int>(B.m, 0);
	B.barcode = vector<vector<char>>(B.n, vector<char>(B.m, 'o'));
	for(int i = 0; i < B.n; i++)
		for(int j = 0; j < B.m; j++){
			cin >> B.barcode[i][j];
			if(B.barcode[i][j] == '#')	B.cntW[j]++;
		}
	int ans = B.repPix(0, 0, 2);
	cout << ans << endl;
	//fout.close();
	return 0;
}