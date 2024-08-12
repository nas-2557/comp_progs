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
using namespace std;
#define ll long long int
#define ld long double


class LadyChimpFinder{
	private:
		vector<ll> lh;
		ll BSfirst(ll val){
			ll start = 0;
			ll end = lh.size()-1;
			ll mid;
			while(start < end){
				mid = start +(end-start)/2;
				if(val > lh[mid]) start = mid+1;
				else end = mid;
			}
			return start;
		}
		
		ll BSlast(ll val){
			ll start = 0;
			ll end = lh.size()-1;
			ll mid;
			while(start < end){
				mid = 1 + start + (end-start)/2;
				if(val < lh[mid]) end = mid-1;
				else start = mid;
			}
			return start;
		}

	public:
		LadyChimpFinder(vector<ll> lh):lh(move(lh)){}
		pair<ll,ll> findMates(ll qhval){
			ll f = BSfirst(qhval);
			ll l = BSlast(qhval);
			ll first, last;

			if(f > 0 && f < lh.size()-1)	first = lh[--f];
			else{
				if(f == lh.size()-1){
					if(lh[f] < qhval)	first = lh[f];
					else	first = lh[--f];
				}
				else	first = -1; 
			}
			
			if(l < lh.size() - 1)	last = lh[++l];
			else	last = -1;
			
			return make_pair(first, last);
		}

};

int main(){
	ll lhsize, qhsize;
	ll h;
	vector<ll>lh, qh;
	cin >> lhsize;
	while(lhsize--){
		cin >> h;
		lh.push_back(h);
	}
	cin >> qhsize;
	while(qhsize--){
		cin >> h;
		qh.push_back(h);
	}
	LadyChimpFinder lcf(lh);
	for(auto i: qh){
		pair<ll, ll> mates;
		mates = lcf.findMates(i);
		if(mates.first == -1)	cout << "X" << " ";
		else cout << mates.first << " ";
		if(mates.second == -1) cout << "X" << endl;
		else cout << mates.second << endl;
	}
	return 0;
}

