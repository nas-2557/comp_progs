#include<iostream>
#include <stack>
#include<map>
using namespace std;

bool valid(string i_stream)
    {
        bool flag = 0;
        stack<char> parantheses;
        for( auto i : i_stream)
            {
                if(i == '(')
                    parantheses.push(i), flag = true;
                else if(i==')')
                    {if(parantheses.empty())
                        return false;
                    parantheses.pop();
                    }
                else 
                    return false;
            }
        if(parantheses.empty() && flag == true)
            {
                return true;
            }
        return false;
    }

ll score_par(string i_stream)
    {   
        if(valid(i_stream)==0)
            return 0;
        stack<char> parantheses;
        ll score = 0, start = 0;
        bool flag = 0;

        for (ll i=0; i<i_stream.length(); i++)
            {
                if(i_stream[i] == '(')
                    parantheses.push('('), flag = true;
                else if(i_stream[i] ==')')
                    {
                        parantheses.pop();
                        if(parantheses.empty() && flag == true)
                            {   
                                if(start + 1 == i)
                                    score += 1;
                                else
                                    score += 2*score_par(i_stream.substr(start+1,(i-(start+1))));
                                start = i+1;
                            }
                    }
            }
        return score;
    }

ll main()
    {
        string input_stream;
        while(true)
            { 
            cout<<"Enter String of balanced parantheses: \t";
            cin >> input_stream;
            cout << score_par(input_stream) << '\n';
            }
        return 0;
    }