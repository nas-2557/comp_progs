//Virtual Friends
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

class DSU{
	private:
		int v;
		vector<int> parent, rank, cnt;

	public:
		DSU(int v):v(v){
			parent = vector<int>(v, -1);
			rank = vector<int>(v, 1);
			cnt = vector<int>(v, 1);
		}

		int find(int f){
			if(parent[f] == -1)
				return f;
			return parent[f] = find(parent[f]);
		}

		void uni(int a, int b){
			int x = find(a);
			int y = find(b);
			if(x == y)
				return;
			if(rank[x] < rank[y])	parent[x] = y , cnt[y] += cnt[x];
			else if(rank[y] < rank[x])	parent[y] = x, cnt[x] += cnt[y];
			else	parent[y] = x, rank[x]++, cnt[x] += cnt[y];
		}

		int giveCnt(int x){
			return cnt[find(x)];
		}

};

int main(){
	ofstream fout("output.txt");
	int t;
	cin >> t;
	while(t--){
		int n, i = 1; string str1, str2;
		map<string, int> names;
		cin >> n;
		DSU D(2*n);
		while(n--){
			cin >> str1 >> str2;
			if(!names[str1])
				names[str1] = i, i++;
			if(!names[str2])
				names[str2] = i, i++;
			D.uni(names[str1], names[str2]);
			cout << D.giveCnt(names[str1]) << endl;
			fout << D.giveCnt(names[str1]) << endl;
		}		
	}
	fout.close();
	return 0;
}