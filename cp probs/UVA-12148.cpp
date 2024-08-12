#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<cassert>
using namespace std;
#define ll long long int

class Date
{
	private:
		ll day;
		ll month;
		ll year;
		bool leap;
		static ll lims[12];

	public:
		Date(ll day, ll month, ll year):day(std::move(day)), month(std::move(month)), year(std::move(year))
		{this->validate();}

		void prll(){
			cout << this->day << " " << this->month << " " << this->year << endl;
		}
		void validate(){
			ll m = this->month;
			ll lim; this->leap = false;
			if(this->year/1000 <= 0)
				this->year = 2000; 
			if((this->year%4 == 0) && (this->year%100 != 0 || this->year%400 == 0))
				this->leap = true;
			lim = (m==1 && this->leap == true)?Date::lims[m]+1:Date::lims[m];
			if(this->day < 0)
				this->day = 1;
			if(this->day > lim)
				this->day = 1, this->month += 1, this->validate();
			if(this->month < 0) 
				this->month = 0;
			if(this->month > 12)
				this->month = 0, this->year += 1, this->validate();
			return;
		}

		Date next_day(){
			this->day+=1;
			this->validate();
			return *this;
		}

		bool operator ==(const Date &other){
			return std::tie(this->day, this->month, this->year) == std::tie(other.day, other.month, other.year);
		}
};	

ll Date::lims[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

tuple<ll, ll> result(const vector<Date> &date_vec, const vector<ll> &power_vec){
	assert(date_vec.size()==power_vec.size());
	ll consec_days {0};
	ll tot_power {0};

	for(ll i = 1; i < date_vec.size(); i++)
	{
		Date next_date = date_vec[i-1];
		next_date.next_day();
		if(next_date == date_vec[i]){
			consec_days++;
			tot_power += power_vec[i] - power_vec[i-1];
		}
	}
	return make_tuple(consec_days, tot_power);	
}

int main()
{ 	
	ll t;
	ll day, month, year, power;
	vector<ll> power_vec;
	vector<Date> date_vec;
	vector<tuple<ll,ll>> resu;

	while(cin >> t){
		if(t == 0)
			break;
		while(t--){
			cin >> day >> month >> year >> power;
			date_vec.push_back(Date(day, month-1, year));
			power_vec.push_back(power);
		}
		resu.push_back(result(date_vec, power_vec));
		date_vec.clear();
		power_vec.clear();
	}

	for(auto i: resu){
		cout << get<0>(i) << " " << get<1>(i) << "\n";
	}
	cout <<"\n";

	return 0;
}

