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
ll A[202020];
ll L[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	ll ret=-1LL<<60;
	ll cur=0;
	ll mi=0;
	ll ma=-1LL<<30;
	ll best=-1LL<<30;
	FOR(i,N) {
		cur+=A[i];
		ma=max(ma,cur);
		best=max(best,cur-mi);
		L[i]=best;
		mi=min(mi,cur);
	}
	cur=0;
	mi=0;
	ma=-1LL<<30;
	best=-1LL<<30;
	for(i=N-1;i>=1;i--) {
		cur+=A[i];
		ma=max(ma,cur);
		best=max(best,cur-mi);
		ret=max(ret,L[i-1]*best);
		mi=min(mi,cur);
	}
	cur=0;
	mi=1LL<<30;
	ma=0;
	best=1LL<<30;
	FOR(i,N) {
		cur+=A[i];
		mi=min(mi,cur);
		best=min(best,cur-ma);
		L[i]=best;
		ma=max(ma,cur);
	}
	cur=0;
	mi=1LL<<30;
	ma=0;

	best=1LL<<30;
	for(i=N-1;i>=1;i--) {
		cur+=A[i];
		mi=min(mi,cur);
		best=min(best,cur-ma);
		ret=max(ret,L[i-1]*best);
		ma=max(ma,cur);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
