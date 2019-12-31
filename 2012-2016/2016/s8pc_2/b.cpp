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

ll N;
int Q;
int A[25];
set<ll> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) cin>>A[i];
	
	ll ret=0;
	for(int mask=0;mask<1<<Q;mask++) {
		ll di=1;
		
		FOR(i,Q) if(mask&(1<<i)) di=min(di*A[i],1LL<<50);
		if(di>N) continue;
		ll tmp=di;
		FOR(i,Q) {
			if(mask&(1<<i)) {
				if(di%A[i]!=0) break;
				di/=A[i];
			}
			else {
				if(di%A[i]==0) break;
			}
		}
		if(i==Q) S.insert(tmp);
	}
	cout<<S.size()<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
