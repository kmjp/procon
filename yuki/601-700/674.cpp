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

ll D;
int Q;
ll A[303030],B[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>Q;
	vector<ll> V;
	V.push_back(-1);
	V.push_back(1LL<<60);
	FOR(i,Q) {
		cin>>A[i]>>B[i];
		V.push_back(A[i]-1);
		V.push_back(A[i]);
		V.push_back(B[i]);
		V.push_back(B[i]+1);
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	set<ll> S;
	FOR(i,V.size()) S.insert(V[i]);
	
	ll ret=0;
	FOR(i,Q) {
		while(1) {
			auto it=S.lower_bound(A[i]);
			if(*it>B[i]) break;
			S.erase(*it);
		}
		auto it=S.lower_bound(B[i]);
		ll ed=*it;
		it--;
		ll st=*it;
		ret=max(ret,ed-st);
		cout<<ret-1<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
