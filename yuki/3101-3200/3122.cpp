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

static pair<int,int> const def={-1,-1};

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	
	V comp(V l,V r){
		int A[4]={l.first,l.second,r.first,r.second};
		sort(A,A+4);
		return {A[3],A[2]};
	};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={v,-1};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<pair<int,int>,1<<20> st;

int N,Q;
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) st.update(i,min(A[i],A[i+1]));
	while(Q--) {
		cin>>i>>x>>y;
		if(i==1) {
			x--;
			A[x]=y;
			if(x) st.update(x-1,min(A[x-1],A[x]));
			if(x<N-1) st.update(x,min(A[x],A[x+1]));
		}
		else {
			x--,y--;
			auto p=st.getval(x,y);
			int B[4]={A[x],A[y],p.first,p.second};
			sort(B,B+4);
			cout<<B[2]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
