#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
#define ull unsigned long long ll
ull embed_count(ll n, ll m, ll c)
{
	ull col_diff = m-8;
	ull row_diff = n-8;
	ull res = ((row_diff+1)*(col_diff+1));
		if(res%2!=0 && c==1)
			res = res/2 + 1;
		else
			res/=2;
			
	return res;
}

ll main()
{
	ll rows, cols, corner;
	vector<ull> results;
	while(cin >> rows >> cols >> corner){
		if(rows == 0 && cols == 0 && corner == 0)
			break;
		//cout << embed_count(rows, cols, corner)<< endl;
		results.push_back(embed_count(rows, cols, corner));
	}
	for(auto i: results)
		cout << i << endl;
	return 0;
}