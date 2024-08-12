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
 
void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int gcd(int a, int b){
	if(b == 0)
		return a;
	return(gcd(b, a%b));
}

class LL{
	public:
		struct Node{
			int num, den;
			Node *left = nullptr;
			Node *right = nullptr;
			Node(int num, int den):num(num), den(den), left(nullptr), right(nullptr){}
		};

		enum dir {LEFT = 0, RIGHT};
		Node *index, *head;

		LL(){
			index = new Node(1,1);
			Node *l = new Node(0,1);
			Node *r = new Node(1,0);
			index->left = l;
			index->right = r;
			l->right = index;
			r->left = index;
			head = index->left;
		}

		int cmpFrac(int numa, int dena, int numb, int denb){
			if(numa * denb > numb * dena)
				return 1;
			else if(numa * denb < numb * dena)
				return 2;
			else return 0;
		}

		void ins(Node* n, int num, int den, int dir){
			Node *newn = new Node(num, den);
			if(dir == LEFT){ newn->left = n->left; newn->right = n; n->left = newn;}
			else if(dir == RIGHT){ newn->left = n; newn->right = n->right; n->right = newn;}
			index = newn;
			return;
		}

		string fracPath(int num, int den){
			int g = gcd(num, den);
			num /= g;
			den /= g;
			string s;
			if((den == 0)||(num == 0)||(num == 1 && den == 1))	return string();
			while(cmpFrac(index->num, index->den, num, den) != 0){
				if(cmpFrac(index->num, index->den, num, den) == 1){
					ins(index, index->left->num+index->num, index->left->den+index->den, LEFT);
					s.push_back('L');
				}
				else{
					ins(index, index->right->num+index->num, index->right->den+index->den, RIGHT);
					s.push_back('R');
				}
			}
			return s;
		}

		~LL(){
			while(head != nullptr){
				Node *temp = head;
				head = head->right;
				delete temp;
			}
		}

};


 
int main(){
	fastIO();
	// ofstream fout;
	// ifstream fin;
	// fout.open("output.txt");
	// fin.open("input.txt");
	int num, den;
	
	while(true){
		LL fracTree;
		cin >> num >> den;
		if(num == 1 && den == 1)	break;
		cout << fracTree.fracPath(num, den) << endl;
	}
	
	// fout.close();
	// fin.close();
	return 0;
}