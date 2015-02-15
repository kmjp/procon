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

ll N,D,T;
ll X[150];

map<ll,vector<pair<ll,ll> > > M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>T;
	FOR(i,N) {
		cin>>X[i];
		M[(D+X[i]%D)%D].push_back(make_pair(X[i]-D*T,X[i]+D*T));
	}
	
	ll ret=0;
	ITR(it,M) {
		vector<pair<ll,ll> > V=it->second;
		ll mi=-1LL<<60,ma=-(1LL<<60)-D;
		sort(V.begin(),V.end());
		FOR(i,V.size()) {
			if(V[i].first>ma) {
				ret+=(ma-mi)/D+1;
				mi=V[i].first;
			}
			ma=V[i].second;
		}
		ret+=(ma-mi)/D+1;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
