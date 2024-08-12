#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
using namespace std;
#define ll long long 

class PicGraph
{
	private:
		vector<vector<short>> pic;
		vector<vector<bool>> verified;
		ll n;
		ll cnt;

		bool dfs(ll r, ll c){
			if(pic[r][c]!=1)
				return false;
			verified[r][c] = true;
			
			for(auto i: vector<ll>{-1,0,1})
				for(auto j: vector<ll>{-1,0,1}){
						ll x = r + i;
						ll y = c + j;
						if((x >= 0 && y >= 0)&&(x < this->n && y < this->n) && (x != r || y != c))
							if(verified[x][y]==0)
								dfs(x,y);
				}	
			return true;	
		}
	public:
		PicGraph(vector<vector<short>> pic, ll n): pic(move(pic)), n(move(n)){
			assert(n == this->pic[0].size());
			this->verified = vector<vector<bool>>(n, vector<bool>(n, 0));
			this->cnt = 0;
		}
	
		ll count_targets(){
			for(ll i = 0; i < n; i++)
				for(ll j = 0; j < n; j++){
					if(pic[i][j] == 1 && verified[i][j] == 0)
						if(dfs(i,j))
							cnt++;
				}
			return cnt;
		}
};

vector<short> i_tokenizer(const string &lleger){
	vector<short> line;
	for(ll i = 0; i < lleger.length(); i++)
		line.push_back(lleger[i]-'0');
	return line;
}

int main(){
	ll n; ll cases = 0;
	string line;
	while(cin >> n){
		if(n == -1)
			break;
		cases++;
		vector<vector<short>> pic(n, vector<short>(n, 0));
		for(ll i = 0; i < n; i++){
			cin >> line;
			pic[i] = i_tokenizer(line);
		}
		PicGraph picture(pic, n);
		cout << "Image number " << cases << " contains " << picture.count_targets() << " war eagles." << endl;
	}
	return 0;
}	