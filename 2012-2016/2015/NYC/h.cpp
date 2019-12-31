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

class UF {
	public:
	static const int ufmax=100052;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { int i; FOR(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int operator[](int x) {return (ufpar[x]==x)?(x):(ufpar[x] = operator[](ufpar[x]));}
	int count(int x) { return ufcnt[operator[](x)];}
	void unite(int x,int y) {
		x = operator[](x); y = operator[](y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};

int N;
ll X[101000],Y[101000];
pair<ll,int> P[101000];

ll ok(ll val) {
	UF uf;
	int i;
	
	FOR(i,N) P[i]=make_pair(X[i],i);
	sort(P,P+N);
	for(i=N-1;i>=0;i--) {
		if(P[i].first-P[0].first<val) break;
		uf.unite(P[0].second,P[i].second);
	}
	FOR(i,N) {
		if(P[N-1].first-P[i].first<val) break;
		uf.unite(P[N-1].second,P[i].second);
	}
	FOR(i,N) P[i]=make_pair(Y[i],i);
	sort(P,P+N);
	for(i=N-1;i>=0;i--) {
		if(P[i].first-P[0].first<val) break;
		uf.unite(P[0].second,P[i].second);
	}
	FOR(i,N) {
		if(P[N-1].first-P[i].first<val) break;
		uf.unite(P[N-1].second,P[i].second);
	}
	int cnt=0;
	FOR(i,N) if(uf[i]==i) cnt++;
	return cnt==1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[i]=x+y;
		Y[i]=x-y;
	}
	ll ret=0;
	for(i=30;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
