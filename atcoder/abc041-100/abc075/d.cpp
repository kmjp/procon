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

vector<ll> V;

int N,K;
ll X[51],Y[51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>X[i]>>Y[i], V.push_back(X[i]);
	
	sort(ALL(V));
	ll mi=1LL<<62;
	FOR(j,V.size()) FOR(i,j+1) {
		ll W=V[j]-V[i];
		
		vector<ll> YS;
		FOR(x,N) if(V[i]<=X[x] && X[x]<=V[j]) YS.push_back(Y[x]);
		sort(ALL(YS));
		
		FOR(x,YS.size()) if(x+K<=YS.size()) mi=min(mi,W*(YS[x+K-1]-YS[x]));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
