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
using namespace std;
#define ll long long int
#define ld long double


class Overlap{
	private:
		struct Rectangle{
			ll llx, lly, urx, ury;
		};
		Rectangle rect1, rect2;
	public:
	void getRect1(ll llx, ll lly, ll urx, ll ury){
		rect1.llx = llx, rect1.lly = lly, rect1.urx = urx, rect1.ury = ury;
	}
	void getRect2(ll llx, ll lly, ll urx, ll ury){
		rect2.llx = llx, rect2.lly = lly, rect2.urx = urx, rect2.ury = ury;
	}
	tuple<ll, ll, ll, ll> findOverlap(){
		ll x1, x2, y1, y2; 
		
		bool flagx = false, flagy = false;
		tie(x1, x2, y1, y2) = tie(rect2.llx, rect2.urx, rect2.lly, rect2.ury);
		if(tie(rect1.llx, rect1.urx, rect1.lly, rect1.ury) == tie(rect2.llx, rect2.urx, rect2.lly, rect2.ury))
			return make_tuple(x1, y1, x2, y2);
		if(rect1.llx >= rect2.llx && rect1.llx < rect2.urx)
			x1 = rect1.llx, flagx = true;
		if(rect1.urx > rect2.llx && rect1.urx <= rect2.urx)
			x2 = rect1.urx, flagx = true;
		if(rect1.lly >= rect2.lly && rect1.lly < rect2.ury)
			y1 = rect1.lly, flagy = true;
		if(rect1.ury > rect2.lly && rect1.ury <= rect2.ury)
			y2 = rect1.ury, flagy = true;
		if(flagx == true && flagy == true)
			return make_tuple(x1, y1, x2, y2);
		
		if(rect2.llx >= rect1.llx && rect2.llx < rect1.urx)
			flagx = true;
		if(rect2.urx > rect1.llx && rect2.urx <= rect1.urx)
			flagx = true;
		if(rect2.lly >= rect1.lly && rect2.lly < rect1.ury)
			flagy = true;
		if(rect2.ury > rect1.lly && rect2.ury <= rect1.ury)
			flagy = true;
		if(flagx == true && flagy == true)
			return make_tuple(x1, y1, x2, y2);

		return make_tuple(0,0,0,0);
}

};

int main(){
	//auto fp = freopen("output.txt","w", stdout);
	ll t;
	ll urx, ury, llx, lly;
	Overlap o;
	tuple<ll, ll, ll, ll> coords;
	cin >> t;
	cin.ignore(1000,'\n');
	while(t--){
		cin >> llx >> lly >> urx >> ury;
		o.getRect1(llx, lly, urx, ury);
		cin >> llx >> lly >> urx >> ury;
		o.getRect2(llx, lly, urx, ury);
		cin.ignore(1000,'\n');
		coords = o.findOverlap();
		if(coords != make_tuple(0,0,0,0))
			cout << get<0>(coords) << " " << get<1>(coords) << " " << get<2>(coords) << " " << get<3>(coords) << endl;
		else
			cout << "No Overlap" << endl;
		if(t != 0)
			cout << endl;
	}
	//afclose(fp);
	return 0;
}