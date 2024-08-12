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
using namespace std;
#define ll long long ll

class BossTree{
	private:
		struct Node{
			ll val;
			Node *boss;
			Node(ll val):val(val){this->boss = nullptr;}
		};
		map<ll, Node*> members;

	public:
		Node* createNode(ll mem){
			Node *m = new Node(mem);
			members[mem] = m;
			return members[mem];
		}

		Node *getNode(ll mem){
			if(!members[mem])
				return nullptr;
			return members[mem];
		}

		ll getBoss(ll mem){
			if(!members[mem])	
				return -1;
			return (members[mem]->boss)?members[mem]->boss->val:0;
		}
		
		pair<Node*, bool>findBoss(Node* mem, bool flag = false){
			if(mem->boss)
			{flag = true; return findBoss(mem->boss, flag);}
			return make_pair(mem, flag);
		}

		void addBoss(ll boss, ll mem){
			Node *m, *b;
			if(!members[mem])
				m = createNode(mem);
			else
				m = members[mem];

			if(!members[boss])
				b = createNode(boss);
			else
				b = members[boss];
			
			pair<Node*, bool> temp1 = findBoss(m);
			pair<Node*, bool> temp2 = findBoss(b);
			if(temp1.first != b){
				if(temp1.first == temp2.first){
					if(temp2.second == true)
					m->boss = b;
				}
				else
					temp1.first->boss = b;
			}
			
			
		}

		void prllBoss(){
			for(ll i = 0; i < this->members.size(); i++){
				cout << getBoss(i+1) << endl;
			}
		}

		~BossTree() {
			for (auto& member : members) {
				delete member.second;
			}
		}
};

ll main(){
	ll n, k;
	cin >> n >> k;
	ll t, x;
	BossTree tree;
	for(ll i = 0; i < k; i++){
		cin >> t;
		while(t--){
			cin >> x;
			tree.addBoss(i+1, x);
		}
	}
	for(ll i = k; i < n; i++){
		if(!tree.getNode(i+1))
			 tree.addBoss(tree.findBoss(tree.getNode(1)).first->val, i+1);
	}

	tree.prllBoss();
	return 0;
}	