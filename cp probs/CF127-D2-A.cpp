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
using namespace std;
#define ll long long int
#define ld long double

class Signature{
	private:
		vector<pair<short, short>> signature;
		ld distance;
		ld dist(short x1, short y1, short x2, short y2){
			return (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
		}
	public:
		void setPolls(ll x, ll y){
			signature.push_back(make_pair<short, short>(x,y));
		}
		ld totalDist(){
			ld total_dist = 0;
			for(ll i = 1; i < signature.size(); i++){
				total_dist += dist(signature[i-1].first, signature[i-1].second, signature[i].first, signature[i].second);
			}
			return total_dist;
		}	
};

int main(){
	ll n, k;
	ll x, y;
	cin >> n >> k;
	Signature sign;
	while(n--){
		cin >> x >> y;
		sign.setPolls(x, y);
	}
	ld time = (sign.totalDist()/50)*k;
	cout << fixed << setprecision(9) << time << endl;
}