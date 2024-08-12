//Petya And Countryside#include<iostream>
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
#include<functional>
#include<valarray>
using namespace std;
#define ll long long int
#define ld long double
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define fr(n) for (int i = 0; i < (n); i++)

void fastIO(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

class LLgardnode{
	private:
		int height;
		LLgardnode* left;
		LLgardnode* right;

	public:
		LLgardnode(int height, LLgardnode *left = nullptr, LLgardnode *right = nullptr):height(move(height)), left(move(left)), right(move(right)){
		}
		void setRight(LLgardnode *node){
			this->right = node;
		}
		void setLeft(LLgardnode *node){
			this->left = node;
		}
		LLgardnode *getRight(){
			return this->right;
		}
		LLgardnode *getLeft(){
			return this->left;
		}
		int getVal(){
			return this->height;
		}
};

class LLgard{
	private:
		vector<LLgardnode*> llnodes;

	public:
		LLgard(){}
		void addNode(int val){
			LLgardnode *node = new LLgardnode(val);
			if(llnodes.size() == 0)
				this->llnodes.push_back(node);
			else{
				this->llnodes[this->llnodes.size()-1]->setRight(node);
				node->setLeft(this->llnodes[llnodes.size()-1]);
				this->llnodes.push_back(node);
			}
		}

		int findRange(LLgardnode * llnode){
			LLgardnode* lsrch = llnode;
			LLgardnode* rsrch = llnode;
			int cntl = 0, cntr = 0;
			while(lsrch){
				cntl++;
				if(lsrch->getLeft() == nullptr)
					break;
				if(lsrch->getLeft()->getVal() > lsrch->getVal())
					break;
				lsrch = lsrch->getLeft();
			}
			while(rsrch){
				cntr++;
				if(rsrch->getRight() == nullptr)
					break;
				if(rsrch->getRight()->getVal() > rsrch->getVal())
					break;
				rsrch = rsrch->getRight();
			}
			return cntl+cntr-1;
		}

		int findMaxRange(){
			int max = 0, temp;
			for(auto i: this->llnodes){
				temp = findRange(i);
				if(temp > max)
					max = temp;
			}
			return max;
		}

		~LLgard(){
			for(auto i: llnodes){
				delete i;
			}
		}

		LLgard(LLgard&) = delete;
		LLgard(LLgard&&) = delete;
		LLgard& operator=(LLgard&) = delete;
};

int main(){
	fastIO();
	int n, val;
	string vals;
	LLgard llgard;
	cin >> n;
	cin.ignore(1000, '\n');
	getline(cin, vals, '\n');
	istringstream oss(vals);
	while(n--){
		oss >> val;
		llgard.addNode(val);
	}
	cout << llgard.findMaxRange() << endl;
	return 0;
}


