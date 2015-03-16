#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_Stair {
public:
	vector<V> val,lcnt,cnt;
	SegTree_Stair(){val=vector<V>(NV*2,-1);lcnt=cnt=vector<V>(NV*2,0);};
	int find(int e,V v) {
		if(e>=NV) return val[e]>v;
		if(v>val[e*2+1]) return find(e*2,v);
		return lcnt[e]+find(e*2+1,v);
	}
	
	void update(int e, V v) {
		e += NV;
		val[e]=v;
		lcnt[e]=0;
		cnt[e]=(v>=0);
		while(e>1) {
			e>>=1;
			val[e]=max(val[e*2],val[e*2+1]);
			lcnt[e]=find(e*2, val[e*2+1]);
			cnt[e]=lcnt[e] + cnt[e*2+1];
		}
	}
};

int N,M;
int L[201000],R[201000],H[201000];
int P[201000],res[201000];
int ev[401000];

SegTree_Stair<int,1<<18> seg;


void solve() {
	int i,j,k,l,r,x,y; string s;
	MINUS(ev);
	
	cin>>N;
	FOR(i,N) cin>>L[i]>>R[i]>>H[i], ev[L[i]]=ev[R[i]]=i;
	
	cin>>M;
	FOR(i,M) cin>>P[i], ev[P[i]]=i;
	
	FOR(i,401000) if(ev[i]!=-1) {
		if(L[ev[i]]==i) seg.update(ev[i],H[ev[i]]);
		if(R[ev[i]]==i) seg.update(ev[i],-1);
		if(P[ev[i]]==i) res[ev[i]] = seg.cnt[1];
	}
	FOR(i,M) _P("%d\n",res[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
