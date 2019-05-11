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

int N;
ll T[202020];
ll S,A[202020],B[202020];
vector<int> ev[202020];

int ok(ll v) {
	int i;
	FOR(i,N) ev[i].clear();
	FOR(i,N) {
		if(A[i]<v) return 0;
		ll d=(A[i]-v)/B[i];
		ll L=max(T[i]-d,0LL);
		ll R=T[i]+d;
		ev[L].push_back(R);
	}
	
	multiset<int> T;
	FOR(i,N) {
		FORR(e,ev[i]) T.insert(e);
		while(T.size() && *T.begin()<i) return 0;
		if(T.empty()) return 0;
		T.erase(T.begin());
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>T[i]>>A[i]>>B[i];
		T[i]--;
	}
	
	ll ret=-1LL<<30;
	for(i=30;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
