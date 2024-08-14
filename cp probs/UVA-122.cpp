#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<complex>
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
#pragma GCC optimize("O3")
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
	// FILE *fp = freopen("input.txt","r", stdin);
	// FILE *fp2 = freopen("output.txt","w", stdout);

	string str;
	vector<pair<int, string>> v;
	map<string, int> m;
	map<string, bool> visited;
	int cnt = 0;
	string str1, str2; int val;
	while(cin >> str){
		if(str == "()")goto skip;
		for(int i = 1; str[i] != ','; i++)	str1.push_back(str[i]);
		for(int i = str1.size()+2; i < str.size()-1; i++)	str2.push_back(str[i]);
		if(str1.size()!=0)	m[(str2.size()!=0)?str2:"X"] = stoi(str1);
		v.push_back({stoi(str1), str2});
		str1.clear(), str2.clear();
		continue;
		skip:
		sort(v.begin(), v.end(), [](pair<int, string> &a, pair<int, string> &b){return (a.second.size() == b.second.size())?a.second < b.second: a.second.size() < b.second.size();});
		for(auto i: v){
			if(i.second.size() == 0){if(visited["X"]) continue; cnt++, visited["X"] = true;}
			else if(i.second.size() == 1)	{if(visited[i.second]) continue; if(m["X"]) cnt++, visited[i.second] = true;}
			else{
				if(visited[i.second])	continue;
				string s = i.second;
				s.pop_back();
				if(m[s])	cnt++, visited[i.second] = true;
			}
		}	
		if(cnt == v.size())
			for(int i = 0; i < v.size(); i++){	
				cout << v[i].first; 
				if(i<v.size()-1) cout << " ";
			}
		else
			cout << "not complete";
		cout << endl;
		v.clear(), m.clear(), visited.clear(), cnt = 0;
    }
	// fclose(fp);
	// fclose(fp2);
    return 0;
}