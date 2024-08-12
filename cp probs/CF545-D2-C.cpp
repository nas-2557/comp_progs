// Woodcutters
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

class Woodcutter{
	public:
		vector<pair<ll, ll>> trees;
		int cutcount = 0;
		vector<vector<int>> mem; 
		enum lststate {NOT = 0, LEFT, RIGHT};

		bool overlap(int posn, int dir, int last_dir){
			if(dir == RIGHT && posn+1 < trees.size()){
				if(trees[posn].first + trees[posn].second < trees[posn+1].first)
					return false;
				else return true;
			}	
			else if(dir == LEFT && posn-1 >= 0){
				if(last_dir == RIGHT){
					if(trees[posn].first - trees[posn].second > trees[posn-1].first + trees[posn-1].second)
						return false;
					else return true;
				}
				else{
					if(trees[posn].first - trees[posn].second > trees[posn-1].first)
						return false;
					else return true;
				}
			}
			else
				return false;
		}

		int indepTree(int pos){
			bool flagl = true, flagll = true, flagr = true, flagrr= true;
			if(pos - 1 > 0){
				if(trees[pos-1].first + trees[pos-1].second < trees[pos].first - trees[pos].second)
					flagll = true, flagl = true;
				else if(trees[pos-1].first < trees[pos].first - trees[pos].second)
					flagl = true, flagll = false;	
				else
					flagll = false, flagl = false;
			}
			if(pos + 1 < trees.size()){
				if(trees[pos+1].first - trees[pos+1].second > trees[pos].first + trees[pos].second)
					flagrr = true, flagr= true;
				else if(trees[pos+1].first > trees[pos].first + trees[pos].second)
					flagr = true, flagrr = false;
				else
					flagrr = false, flagr = false;	
			}

			if(flagll == true && flagrr == true)
				return 2;
			else if(flagl == false && flagr == false)
				return 1;
			else 
				return 0;
		}

		int maxTreesdp(int i, int ltstate, int startpos, int endpos){
			if(i == endpos)
				return 0;
			int &res = this->mem[i][ltstate];
			if(res != -1)
				return res;

			int resl = 0, resr = 0, resn = 0;
			
			if(!overlap(i, LEFT, ltstate))
				resl = maxTreesdp(i+1, LEFT, startpos, endpos) + 1;
			if(!overlap(i, RIGHT, ltstate))
				resr = maxTreesdp(i+1, RIGHT, startpos, endpos) + 1;
			resn  = maxTreesdp(i+1, NOT, startpos, endpos);

			if(resl >= resr && resl >= resn)
				res = resl;
			else if(resr >= resl && resr >= resn)
				res = resr;
			else res = resn;
			return res;
		}

		int maxTrees(){
			int startpos = 0;
			int endpos = 0;
			for(int i = 0; i < this->trees.size(); i++){
				int status = indepTree(i);
				if(status != 0){
					if(status == 2)
						this->cutcount++;
					endpos = i;
					this->cutcount += maxTreesdp(startpos, NOT, startpos, endpos);
					startpos = endpos+1;
				}
				else if(i == trees.size()-1){
					endpos = i+1;
					this->cutcount += maxTreesdp(startpos, NOT, startpos, endpos);
				}
			}
			return this->cutcount;
		}
};

int main(){
	fastIO();
	// ofstream fout;
	// fout.open("output.txt");
	ll n, x, h;
	Woodcutter W;
	cin >> n;
	W.mem = vector<vector<int>>(n, vector<int>(3, -1));
	while(n--){
		cin >> x >> h;
		W.trees.push_back(make_pair(x, h));
	}
	cout << W.maxTrees() << endl;
	// fout.close();
	return 0;
}