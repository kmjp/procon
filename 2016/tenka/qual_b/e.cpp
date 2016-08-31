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

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<61;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};


SegTree_1<ll,1<<15> st[2];
int N,M;
ll S[202020];
pair<ll,int> P[202020];
int R[202020];
ll dp[20202][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		S[i+1]=S[i]+x;
		P[i]={S[i+1],i};
	}
	sort(P,P+N);
	FOR(i,N) R[P[i].second+1]=i+1;
	
	memset(dp,0x3f,sizeof(dp));
	FOR(i,N) dp[i+1][1]=abs(S[i+1]);
	for(i=2;i<=M;i++) {
		FOR(x,st[0].val.size()) st[0].val[x]=st[1].val[x]=1LL<<61;
		
		for(x=1;x<=N;x++) {
			dp[x][i] = min(st[0].getval(0,R[x])+S[x],st[1].getval(R[x],N+1)-S[x]);
			st[0].update(R[x],dp[x][i-1]-S[x]);
			st[1].update(R[x],dp[x][i-1]+S[x]);
		}
	}
	
	cout<<dp[N][M]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
