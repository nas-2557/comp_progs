//Pi
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

	
	void combinations(vector<int> &vals, int n, vector<vector<int>> &combs){
		static vector<bool> visited = vector<bool>(n, false) ;
		static vector<int> comb;
		static int l = n;
		vector<int> unblock;
		if(n == 0){
			combs.push_back(comb);
			return;
		}
		
		for(int i = 0; i < vals.size(); i++){
			if(visited[i] == true)
				continue;
		
			visited[i] = true;
			unblock.push_back(i);
			comb.push_back(vals[i]);
			combinations(vals, n-1, combs);
			comb.pop_back();
		}
		for(auto i: unblock)
			visited[i] = false;
	}
	
	int gcd(int a, int b){
		if(b == 0)
			return a;
		return gcd(b, a%b);
	}

	double pi_calc(int cnt, int tot){
		if(cnt == 0)
			return 0;
		double x = (6.0*tot)/cnt;
		x = sqrt(x);
		return x;
	}

	int main(){
		fastIO();
		ofstream fout;
		fout.open("output.txt");
		int n;
		int x;
		int cnt = 0;
		double p;
		vector<int> vals;
		vector<vector<int>> combs;
		while(cin >> n){
			if(n==0)
				break;
			while(n--){
				cin >> x;
				vals.push_back(x);
			}
			combinations(vals, 2, combs);
			for(auto comb: combs){
				if(gcd(comb[0], comb[1]) ==1)
					cnt ++;
			}
			p = pi_calc(cnt, combs.size());
			if(p == 0){
				cout << "No estimate for this data set." << endl;
				fout << "No estimate for this data set." << endl;
			}
			else{
				cout << fixed << setprecision(6) << p << endl;
				fout << fixed << setprecision(6) << p << endl;
			}
			combs.clear();
			vals.clear();
			cnt = 0;
		}
		return 0;
	}