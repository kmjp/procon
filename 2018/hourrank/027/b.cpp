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
ll P[303030];

vector<ll> L[303030];
vector<ll> R[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	
	set<ll> S;
	FOR(i,N) {
		if(i) {
			if(*S.begin()<P[i]) L[i].push_back(*S.begin());
			auto it=S.lower_bound(P[i]);
			if(it!=S.begin()) {
				it--;
				L[i].push_back(*it);
			}
		}
		S.insert(P[i]);
	}
	
	S.clear();
	for(i=N-1;i>=0;i--) {
		if(i!=N-1) {
			auto it=S.lower_bound(P[i]+1);
			if(it!=S.end()) R[i].push_back(*it);
			it=S.end();
			it--;
			if(*it>P[i]) R[i].push_back(*it);
		}
		S.insert(P[i]);
	}
	ll ret=-1LL<<61;
	
	FOR(i,N) {
		FORR(l,L[i]) FORR(r,R[i]) ret=max(ret,l*r*P[i]);
	}
	
	if(ret==-1LL<<61) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
