#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
//#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<fstream>
#include<cmath>
#include<functional>
#include<valarray>
using namespace std;
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fr(n) for (int i = 0; i < (n); i++)

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

vector<int> crimcities;
int n, a;

int main(){
	fastIO();
	vector<int> crimcities;
int n, a;
	string input;
	int val;
	cin >> n >> a;
	cin.ignore(1000, '\n');
	getline(cin, input, '\n');
	istringstream iss(input);
	for(int i = 0; i < n; i++){
		iss >> val;
		crimcities.push_back(val);
	}

	int both_dis = min(n-a, a-1);
	int cnt = 0;

	for(int i = 0; i < n; i++){
		if(crimcities[i]==1){
			if(i >= a-1-both_dis && i <= a-1){
				if(i != a-1){
					if(crimcities[i] == crimcities[a+a-i-2])
						cnt += 2;
				}
				else	
					cnt++;
			}
			else
				cnt++;
		}
		if(i == a-1)	i+=both_dis;
	}
	
	int res = cnt;
	cout << res << endl;

	return 0;
}