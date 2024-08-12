//Barcode
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
	vector<int> dotsum;
	vector<vector<vector<int>>> tab;
	int x, y, m, n;
	enum colo {BLACK = 0, WHITE = 1};

	int repPix(){
		vector<int> colo {BLACK, WHITE};
		vector<int> cntvals;
			
		for(int i = m; i >= 0; i--)
			for(int j = y; j >= 1; j--)
				for(int k = 0; k <= 1; k++){
					int cntb = dotsum[i];
					int cntw = n - cntb;
					int ansb = INT_MAX, answ = INT_MAX;
					if(i == 0)
						return min((cntb+tab[1][1][BLACK]), (cntw+tab[1][1][WHITE]));
					if(i == m){
						if(j < x)
							tab[i][j][k] = INT_MAX;
						else
							tab[i][j][k] = 0;
						continue;
					}
					if(j < y){
						//Choose same color
						if(k == WHITE){	answ = tab[i+1][j+1][WHITE]; answ = (answ!=INT_MAX)? answ+cntw: INT_MAX;}
						else if(k == BLACK){ ansb = tab[i+1][j+1][BLACK]; ansb = (ansb!=INT_MAX)? ansb+cntb: INT_MAX;}
					}
					if(j >= x){
						//Choose diff color
						if(k == WHITE){ ansb = tab[i+1][1][BLACK]; ansb = (ansb!=INT_MAX)? ansb+cntb: INT_MAX;}
						else if(k == BLACK){ answ = tab[i+1][1][WHITE]; answ = (answ!=INT_MAX)? answ+cntw: INT_MAX;}
					}
					tab[i][j][k] = min(ansb, answ);
				}
		return tab[0][0][0];
	}
};
 
int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	Barcode B;
	cin >> B.n >> B.m >> B.x >> B.y;
	B.tab = vector<vector<vector<int>>>(B.m+1, vector<vector<int>>(B.y+1, vector<int>(2, INT_MAX)));
	B.dotsum = vector<int>(B.m, 0);
	B.barcode = vector<vector<char>>(B.n, vector<char>(B.m, 'o'));
	for(int i = 0; i < B.n; i++)
		for(int j = 0; j < B.m; j++){
			cin >> B.barcode[i][j];
			if(B.barcode[i][j] == '.') B.dotsum[j]++;
		} 
	int ans = B.repPix();
	cout << ans << endl;
	//fout.close();
	return 0;
}