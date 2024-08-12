#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
#define ll long long int 
//seed(x + 1) = [seed(x) + ST EP]%MOD

class RNG
{
	private:
		static ll rng(ll prev_rng, ll step, ll mod)
		{	return (prev_rng+step)%mod;}
	public:
		static bool rng_seq_test(ll step, ll mod)
		{
			ll s1 {0};
			ll s2 {1};
			ll x, y, prev_rng, cur_rng;
			x = rng(s1, step, mod);
			y = rng(x, step, mod);

			for(ll i = 0; i < mod; i++)
			{
				if(i==0)
					prev_rng = s2;
				else
					prev_rng = cur_rng;
				cur_rng = rng(prev_rng,step,mod);
				if(prev_rng==x)
					if(cur_rng==y)
						return true;
					else
						return false;
			}
			return false;
		}
};

int main()
{
	ll mod, step;
	vector<tuple<ll, ll, bool>> results;
	while(cin >> step >> mod && step != -1)
		results.push_back(make_tuple(step, mod, RNG::rng_seq_test(step, mod)));
	
	for (const auto& result : results) 
	{
	ll step_val = get<0>(result);
	ll mod_val = get<1>(result);
	bool is_good_choice = get<2>(result);

	cout << right << setw(10) << step_val << right << setw(10) << mod_val << left << setw(4) << "";
	if (is_good_choice)
		cout << "Good Choice" << endl;
	else
		cout << "Bad Choice" << endl;
	cout << endl;
    }
	

    return 0;

}