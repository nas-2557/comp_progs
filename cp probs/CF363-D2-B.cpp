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
	//ofstream fout;
	//fout.open("output.txt");
	int n, k, h, minh = INT_MAX, min_ind, val;
	vector<int> fence;
	cin >> n >> k;
	while(n--){
		cin >> h;
		fence.push_back(h);
	}
	for(int i = 1; i < fence.size(); i++)
		fence[i] = fence[i] + fence[i-1];
	for(int i = k-1; i < fence.size(); i++){
		if((val = fence[i] - ((i-k >= 0)?fence[i-k]:0)) < minh){
			minh = val;
			min_ind = i-k+1+1;
		}
	}
	cout << min_ind << endl;
	return 0;
}