//Vacaations
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

class Vacation{
	public:
	vector<int> days;
	enum last_day_val {GYM = 0, CONTEST, REST};
	int n;
	vector<vector<int>> mem;

	int cntRest(int i, int last_day){
		if(i == n){
			return 0;
		}


		int &rest = mem[i][last_day];
		if(rest != INT_MAX)
			return rest;

		if((days[i] == 3 || days[i] == 1) && last_day != CONTEST)
			rest = min(rest, cntRest(i+1, CONTEST));
		if((days[i] == 3 || days[i] == 2) && last_day != GYM)
			rest = min(rest, cntRest(i+1, GYM));
		if(days[i] == 0 || (days[i] == 1 && last_day == CONTEST) || (days[i] == 2 && last_day == GYM))
			rest = min(rest, cntRest(i+1, REST)), rest++;
		
		return rest;
	}
};


int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	int a, n;
	Vacation V;
	cin >> n;
	V.mem = vector<vector<int>>(n, vector<int>(4, INT_MAX));
	V.n = n;
	for(int i = 0; i < n; i ++){
		cin >> a;
		V.days.push_back(a);
	}
	cout << V.cntRest(0, 3);
	// fout.close();
	return 0;
}