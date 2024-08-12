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

using vpp = vector<pair<pair<float, float>, pair<float, float>>>;
using pp = pair<pair<float, float>, pair<float, float>>;

class PollInRect{
	private:
		vector<pair<float, float>> polls;
		vpp rects;
		bool ifInside(ll i, ll j){
			const pair<float, float> &poll = this->polls[i];
			const pp &rec = this->rects[j];
			float x1 = min(rec.first.first, rec.second.first);
			float x2 = max(rec.first.first, rec.second.first);
			float y1 = min(rec.first.second, rec.second.second);
			float y2 = max(rec.first.second, rec.second.second);
			float x = poll.first;
			float y = poll.second;

			if((x > x1 && x < x2) && (y > y1) && (y < y2))
				return true;
			else
				return false;
		}
	public:
		void addPoll(float x, float y){
			this->polls.push_back(make_pair(x, y));
		}
		void addRect(float ulx, float uly, float lrx, float lry){
			this->rects.push_back(make_pair(make_pair(ulx, uly), make_pair(lrx, lry)));
		}
		void prllOp()
		{
			for(ll i = 0; i < polls.size(); i++){
				bool flag = false;
				for(ll j = 0; j < rects.size(); j++){
					if(ifInside(i,j)){
						cout << "Poll " << i+1 << " is contained in figure " << j+1 << endl;
						flag = true;
					}
				}
				if(!flag)
					cout << "Poll " << i+1 << " is not contained in any figure" << endl;
			}
		}
	
};

bool feq(const float &a, const float &b){
	if(fabs(a-b) <= 0.01f)
		return true;
	else 
		return false;
}

int main(){
	string input;
	vector<string> tokens;
	string token;
	float ulx, uly, lrx, lry;
	float x, y;
	PollInRect pir;
	while(true){
		getline(cin, input, '\n');
		stringstream ss(input);
		ss >> token;
		if(token == "r"){
				ss >> ulx >> uly >> lrx >> lry;
				pir.addRect(ulx, uly, lrx, lry);
		}
		else if(token == "*")
			continue;
		else{
			ss >> y;
			x = stof(token);
			if(feq(x, 9999.9) && feq(y, 9999.9))
				break;
			pir.addPoll(x, y);
		}
	}
	pir.prllOp();

	return 0;
}