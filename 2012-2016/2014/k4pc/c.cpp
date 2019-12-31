#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int P[100001];
int W[100001];
ll C[100001];
vector<int> E[100001];
int D[100001],L[100001],R[100001];
int id;

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val,mi;
	static V const def=1<<30, nolink=-1<<30;
	SegTree_3(){val.resize(NV*2); mi.resize(NV*2);clear();};
	void clear() { for(int i=0;i<NV*2;i++) val[i]=mi[i]=def; }
	V comp(V l,V r){ return min(l,r);};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return mi[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]=mi[k]=v;
		}
		else if(l < y && x < r) {
			if(val[k]!=nolink) mi[k*2]=mi[k*2+1]=val[k*2]=val[k*2+1]=val[k], val[k]=nolink;
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			mi[k]=comp(mi[k*2],mi[k*2+1]);
		}
	}
};

SegTree_3<int,1<<18> st;

void dfs(int cur,int d) {
	L[cur]=id++;
	D[cur]=d;
	int i;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		dfs(tar,d+W[tar]);
	}
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x>>W[i+1];
		E[x-1].push_back(i+1);
	}
	dfs(0,0);
	
	FOR(i,N) {
		if(E[i].size()==0) st.update(L[i],L[i]+1,D[i]);
	}
	while(Q--) {
		cin>>x;
		x--;
		st.update(L[x],R[x],1<<30);
		y=st.getval(0,N);
		if(y>=1<<30) y=-1;
		cout<<y<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
