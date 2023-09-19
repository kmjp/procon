#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll A[303030];

template<typename V> struct LeChaoTree {
	static const V inf=3LL<<60;
	const ll range=1<<20;
	const bool cmptype=1; //true:max false:min
	struct node {
		node(V a=0,V b=-inf) : A(a),B(b){ le=ri=NULL;}
		V val(ll x) { return A*x+B;}
		V A,B;  // Ax+B
		node *le, *ri;
	};
	
	node* root;
	LeChaoTree() { root=new node(0,-inf);}
	
	void add(node* n, V a,V b,ll L,ll R) {
		ll M=(L+R)/2;
		
		bool lef=(n->val(L) > a*L+b);
		bool mid=(n->val(M) > a*M+b);
		bool ri=(n->val(R) > a*R+b);
		
		if(lef&&ri) return;
		if(!lef&&(!ri || R-L==1)) {
			n->A=a;
			n->B=b;
			return;
		}
		
		if(R-L==1) return;
		if(!n->ri) n->ri=new node();
		if(!n->le) n->le=new node();
		add(n->ri,a,b,M,R);
		add(n->le,a,b,L,M);
	}
	
	void add(V a,V b) { 
		if(!cmptype) a=-a,b=-b;
		add(root,a,b,-1LL<<30,1LL<<30);
	}
	
	V query(ll x) {
		V ret=-inf;
		node* cur=root;
		ll L=-1LL<<30, R=1LL<<30;
		while(cur) {
			ret=max(ret,cur->val(x));
			ll m=(L+R)/2;
			if(x<m) cur=cur->le, R=m;
			else cur=cur->ri, L=m;
			
		}
		
		if(!cmptype) ret=-ret;
		return ret;
	}
};
LeChaoTree<ll> lct; 

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	lct.add(0,0);
	ll ma=0;
	FOR(i,N) {
		cin>>A[i];
		ll v=lct.query(A[i]);
		ma=max(ma,v);
		lct.add(A[i],v);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
