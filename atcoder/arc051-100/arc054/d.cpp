#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;

template<class V,int MV> struct Dyn_SegTree {
	struct IntNode {
		IntNode(){ val=0, left=right=NULL;}
		V val;
		IntNode *left,*right;
	};
	vector<IntNode*> pool;
	IntNode root;
	IntNode* getent() {
		pool.push_back(new IntNode);
		return pool.back();
	};
	~Dyn_SegTree(){
		FORR(r,pool) delete r;
	}
	
	void add(int k,ll v,int l,int r,IntNode* node) { //val[k]+=v
		if(k<l || k>=r) return;
		node->val += v;
		if(node->val>=mo) node->val -= mo;
		if(l+1==r) return;
		int m=(l+r)>>1;
		if(k>=l && k<m) {
			if(node->left==NULL) node->left=getent();
			add(k,v,l,m,node->left);
		}
		if(k>=m && k<r) {
			if(node->right==NULL) node->right=getent();
			add(k,v,m,r,node->right);
		}
	}
	void add(int k,V v){ add(k,v,0,MV,&root);}
	
	V sum(int k,int l,int r,IntNode* node) { //sum(val[0..(k-1)])
		if(l==r || k<l) return 0;
		if(k>=r) return node->val;
		V v=(node->left?sum(k,l,(l+r)>>1,node->left):0)+(node->right?sum(k,(l+r)>>1,r,node->right):0);
		if(v>=mo) v-=mo;
		return v;
	}
	//sum(val[0..k])
	V sum(int k){ return sum(k+1,0,MV,&root);}
};

struct Node {
	ll X,Y;
	ll mul;
	ll sum;
	unordered_map<int,ll> D;
	Dyn_SegTree<int,1<<17> ds;
};

list<Node> pool;
vector<Node*> S;
int N;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		
		if(x>0) {
			pool.insert(pool.end(),Node());
			Node* n=&pool.back();
			n->X = n->Y = 0;
			n->mul=n->sum=n->D[x]=1;
			n->ds.add(x,1);
			S.push_back(n);
		}
		if(x==0) {
			pool.insert(pool.end(),Node());
			Node* n=&pool.back();
			Node* t=S.back();
			S.pop_back();
			Node* s=S.back();
			S.pop_back();
			
			n->X = (s->X + t->X)%mo;
			n->Y = (s->Y + t->Y)%mo;
			
			if(s->D.size()<t->D.size()) {
				FORR(sr,s->D) {
					ll small=t->ds.sum(sr.first-1)*t->mul%mo;
					ll same=t->D[sr.first]*t->mul%mo;
					
					(n->X += sr.second*s->mul%mo*(small%mo))%=mo;
					(n->Y += sr.second*s->mul%mo*((t->sum-same+mo)%mo))%=mo;
				}
			}
			else {
				FORR(sr,t->D) {
					ll small=s->ds.sum(sr.first-1)*s->mul%mo;
					ll same=s->D[sr.first]*s->mul%mo;
					ll large=((s->sum-small-same)%mo+mo)%mo;
					
					(n->X += sr.second*t->mul%mo*(large%mo))%=mo;
					(n->Y += sr.second*t->mul%mo*((s->sum-same+mo)%mo))%=mo;
				}
				swap(s,t);
			}
			
			n->mul=t->mul;
			n->sum=s->sum+t->sum;
			swap(n->D,t->D);
			swap(n->ds.root,t->ds.root);
			swap(n->ds.pool,t->ds.pool);
			
			ll rev=modpow(n->mul);
			FORR(sr,s->D) {
				ll v=sr.second*s->mul%mo;
				(n->D[sr.first] += v*rev)%=mo;
				n->ds.add(sr.first,v*rev%mo);
			}
			
			S.push_back(n);
		}
		if(x<0) {
			Node* n=S.back();
			ll a=-x;
			n->X = (n->X*a+(a*(a-1)/2)%mo*n->Y)%mo;
			n->Y = a*a%mo*n->Y%mo;
			(n->mul *= a)%=mo;
			(n->sum *= a)%=mo;
		}
	}
	
	cout<<S[0]->X<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
