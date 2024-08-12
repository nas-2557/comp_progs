#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
using std::vector, std::cout, std::ostringstream, std::cin, std::cout, std::string, std::endl, std::istringstream, std::reverse, std::swap;
#define MAX 260


string multiply(string a, string b)
{
	ll arr[MAX], carry = 0, c;
	string op;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	// if(b.length() > a.length())
	// 	swap(a,b);
	memset(arr,0,sizeof(arr));
	
	for(ll i = 0; i<b.length(); i++)
	{	for(ll j = 0; j<a.length(); j++)
		{
			c = i+j;
			ll x = ((ll)a[j] - '0') * ((ll)b[i] - '0');
			arr[c] += x;
			if((arr[c]/10)>0)
			{
				arr[c+1] += arr[c]/10;
				arr[c]%=10;
				if(i==b.length()-1)
					c++;
			}
		}

	}
	for(ll i = 0; i<=c; i++)
		op += std::to_string(arr[i]);
	reverse(op.begin(), op.end());
	return op;
}
ll main()
{
	string a, b;
	while (cin>>a && cin>>b)
		cout<<multiply(a,b)<<endl;
}