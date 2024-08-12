#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

vector<ll> asteroid(const vector<ll>& istream)
{
    stack<ll> as;
    ll top, newtop=0, x;
    

    for(auto i : istream)
    {
        if(i > 0)
            as.push(i);
        else if(i<0)
        {   
            if(as.empty() || as.top()<0)
            {
                as.push(i);
            }
            else
            {
                while(true)
                {
                    top = as.top();
                    if(top < 0)
                        break;
                    x = top + i;

                    if(x > 0)
                    {
                        newtop = top;
                        as.pop();
                        break;
                    }   
                    else if(x < 0)
                    {
                        newtop = i;
                        as.pop();
                        
                    }
                    else if(x == 0)
                    {
                        as.pop();
                        newtop = 0;
                        break;
                    }
                
                }  
                if(newtop!=0)
                    as.push(newtop);
                
            }
        }

    }

    vector<ll> newas(as.size());
    for(auto i = newas.rbegin(); i!=newas.rend(); i++)
        {
            *i = as.top();
            as.pop();
        }
    return newas;

}

vector<ll> tokenizer(string s)
{
    stringstream ss(s);
    vector<ll> v;
    string i;
    while(!ss.eof())
    {
        getline(ss, i, ' ');
        v.push_back(stoi(i));
    }
    return v;
}

ll main()
{
    while(true)
    {
        vector<ll> input_stream;
        string input;
        cout<< "Enter asteroid sizes(+ve and -ve llegers):\t";
        getline(cin, input);
        input_stream = tokenizer(input);
        for(auto i: asteroid(input_stream))
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}