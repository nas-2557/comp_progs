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
#include<cmath>
#include<functional>
#include<valarray>
#include<numeric>
#include<queue>
#include<optional>
// #include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3")
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fr(n) for (int i = 0; i < n; i++)
#define EPS 10e-6

bool deq(double a, double b){
    return fabs(a - b) <= EPS;
}

class IntersectingLines{
    private:

    double find_Slope(pair<int, int> &p1, pair<int, int> &p2){
        if(deq(p2.first, p1.first))
            return 10e6;
        return  static_cast<double>(p2.second - p1.second)/static_cast<double>(p2.first - p1.first);
    }   

    double find_Intercept(pair<int, int> &p1, pair<int, int> &p2){ 
        double slope = find_Slope(p1, p2);
        if(slope == 10e6)
            return p2.first;
        return p2.second - slope*p2.first;
    }

    pair<double, double> find_Intersect(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3, pair<int, int> &p4){
        double m1 = find_Slope(p1, p2);
        double m2 = find_Slope(p3, p4);
        double c1 = find_Intercept(p1, p2);
        double c2 = find_Intercept(p3, p4);
        pair<double, double> p;
        if(deq(m1, 10e6) == 1){
            p.first = p1.first;
            p.second = (m2*p.first) + c2;
        }
        else if(deq(m2, 10e6 == 1)){
            p.first = p3.first;
            p.second = (m1*p.first) + c1;
        }
        else{
            p.first = (c2 - c1)/(m1 - m2);
            p.second = (m1*p.first) + c1;
        }
        return p;
    }
    public:

        void intLines(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> &p3, pair<int, int> &p4){
            double m1 = find_Slope(p1, p2);
            double m2 = find_Slope(p3, p4);
            double c1 = find_Intercept(p1, p2);
            double c2 = find_Intercept(p3, p4);
            pair<double, double> p;

            if(m1 == m2)
                if(c1 == c2) cout << "LINE" << endl;
                else    cout << "NONE" << endl;
            else{ 
                p = find_Intersect(p1, p2, p3, p4);
                cout << fixed << setprecision(2) << "POINT " << p.first << " " << p.second << endl;
            }
        }

};



int main(){
    // FILE *fp = freopen("output.txt", "w",  stdout); 
    pair<int, int> p1, p2, p3, p4;
    int n; IntersectingLines i;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while(n--){
        cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;
        i.intLines(p1, p2, p3, p4);
    }
    cout << "END OF OUTPUT" << endl;
    // fclose(fp);
    return 0;
}