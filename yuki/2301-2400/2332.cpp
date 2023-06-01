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

int N,M;
int A[202020],B[202020],C[202020];
ll dp[202020];

template<typename V> struct LeChaoTree {
	static const V inf=3LL<<60;
	const ll range=1<<20;
	const bool cmptype=false; //true:max false:min
	struct node {
		node(V a=0,V b=-inf) : A(a),B(b){ le=ri=NULL;}
		V val(ll x) { return A*x+B;}
		V A,B;  // Ax+B
		node *le, *ri;
	};
	
	node* root;
	LeChaoTree() { root=new node(0,-inf);}
	
	void add(node* n, V a,V b,ll L,ll R,ll T) {
		
		if(T<=L) return;
		
		ll M=(L+R)/2;
		if(T>=R) {
		
			bool lef=(n->val(L) > a*L+b);
			bool mid=(n->val(M) > a*M+b);
			bool ri=(n->val(R) > a*R+b);
			
			if(lef&&ri) return;
			if(!lef&&(!ri || R-L==1)) {
				n->A=a;
				n->B=b;
				return;
			}
		}
		
		if(R-L==1) return;
		if(!n->ri) n->ri=new node();
		if(!n->le) n->le=new node();
		add(n->ri,a,b,M,R,T);
		add(n->le,a,b,L,M,T);
	}
	
	void add(V a,V b,V T) { 
		add(root,-a,-b,0,range,T);
	}
	
	V query(ll x) {
		V ret=-inf;
		node* cur=root;
		ll L=0, R=range;
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

using VT = vector<int>;

vector<int> Zalgo(VT s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	vector<int> X;
	FOR(i,N) {
		cin>>A[i];
		X.push_back(A[i]);
	}
	X.push_back(0);
	FOR(i,M) {
		cin>>B[i];
		X.push_back(B[i]);
	}
	auto Z=Zalgo(X);
	FOR(i,M) cin>>C[i];
	
	FOR(i,M+1) dp[i]=1LL<<60;
	dp[0]=0;
	lct.add(0,0,1);
	FOR(i,M) {
		x=Z[N+1+i];
		if(x==0) continue;
		ll v=lct.query(i);
		lct.add(C[i],v-(1LL*i*C[i]),i+x+1);
		
	}
	
	ll v=lct.query(M);
	if(v==3LL<<60) v=-1;
	cout<<v<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
