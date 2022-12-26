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
		add(root,a,b,0,range);
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

template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	SegTree_2(){
		val.resize(NV*2);
	};
	
	ll getval(int k,ll x) {
		int e=k+NV;
		ll ret=3LL<<60;
		while(e>=1) {
			ret=min(ret,val[e].query(x));
			e>>=1;
		}
		return ret;
	}
	
	void update(int x,int y, ll a,ll b,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k].add(a,b);
		}
		else if(l < y && x < r) {
			update(x,y,a,b,l,(l+r)/2,k*2);
			update(x,y,a,b,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<LeChaoTree<ll>,1<<17> st;

int N;
ll O[101010],C[101010],D[101010],X[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>O[i]>>C[i]>>D[i]>>X[i];
		if(C[i]==-1) C[i]=101000;
		X[i]=min(X[i],st.getval(O[i]-1,D[i])+D[i]*D[i]);
		st.update(O[i],C[i]+1,-2*D[i],X[i]+D[i]*D[i]);
		cout<<X[i]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
