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

int N;
ll L[1000],C[1000];
ll mi=1LL<<60;

map<ll,ll> M[305];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	FOR(i,N) cin>>C[i];
	FOR(i,N) {
		M[i+1][L[i]]=C[i];
		ITR(it,M[i]) {
			ll X=__gcd(it->first,L[i]);
			if(M[i+1].count(X)==0) M[i+1][X]=it->second+C[i];
			else M[i+1][X]=min(M[i+1][X],it->second+C[i]);
			if(M[i+1].count(it->first)==0) M[i+1][it->first]=it->second;
			else M[i+1][it->first]=min(M[i+1][it->first],it->second);
		}
		M[i].clear();
		if(M[i+1].count(1)) mi=min(mi,M[i+1][1]);
	}
	
	if(mi>=1LL<<60) mi=-1;
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
