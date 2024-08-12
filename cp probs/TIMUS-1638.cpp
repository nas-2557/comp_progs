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
	// ofstream fout;
	// fout.open("output.txt");
	int sh, co, st, end;
	cin >> sh >> co >> st >> end;

	int voldist = st - end;
	if(voldist < 0)
		cout << (abs(voldist) - 1) * sh + abs(voldist) * 2 * co;
	else
		cout << (voldist + 1) * sh + voldist * 2 * co;
	// fout.close();
	return 0;
}