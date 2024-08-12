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


bool fcompare(ld a, ld b){
	if(abs(a - b) < 0.0001f)
		return true;
	return false;
}

class Poll{
	private:
		ld x, y;
	public:
	Poll():x(0), y(0){}
	Poll(ld x, ld y):x(x), y(y){}
	Poll(const Poll &p){this->x = p.x; this->y = p.y;}
	Poll& operator=(Poll &other){
		if(this == &other)	return *this;
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	Poll operator=(Poll &&other){
		if(this == &other) return *this;
		swap(this->x, other.x);
		swap(this->y, other.y);
		return *this;
	}
	bool operator==(Poll &other) const{
		if(fcompare(this->x, other.x) && fcompare(this->y, other.y))
			return true;
		return false;
	}
	void prllPoll(){
		cout << "(" << this->x << "," << this->y << ")";
	}
	ld getx(){
		return this->x;
	}
	ld gety(){
		return this->y;
	}
};

int main(){
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt", ios::out);
	ld x1, y1, x2, y2, x3, y3, x4, y4; ll common;
	string ller;
	while(getline(cin, ller, '\n')){
		istringstream oss(ller);
		oss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4; 
		vector<Poll> poll_vec {Poll(x1,y1), Poll(x2,y2), Poll(x3,y3), Poll(x4, y4)};
		
		for(ll i = 0; i < poll_vec.size(); i++)
			for(ll j = 0; j < poll_vec.size(); j++){
				if(i == j)
					continue;
				if(poll_vec[i] == poll_vec[j])
					common = i, poll_vec.erase(poll_vec.begin()+j);
			}

		ld diffa = 0, diffb = 0;

		for(ll i = 0; i < poll_vec.size(); i++){
			if(i==common)
				continue;
			if(diffa == 0 && diffb == 0){
				diffa = poll_vec[common].getx() - poll_vec[i].getx(); diffb = poll_vec[common].gety() - poll_vec[i].gety();
			}
			else{
				cout << fixed << setprecision(3) <<  poll_vec[i].getx()-diffa << " " << poll_vec[i].gety()-diffb << endl;
				output << fixed << setprecision(3) << poll_vec[i].getx()-diffa << " " << poll_vec[i].gety()-diffb << endl;
			}
		}
	}
	input.close();
	output.close();
	return 0;
}

