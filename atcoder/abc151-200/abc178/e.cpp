#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[202020],Y[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	ll maP=-1LL<<60,miP=1LL<<60;
	ll maN=-1LL<<60,miN=1LL<<60;
	
	
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		maP=max(maP,X[i]+Y[i]);
		miP=min(miP,X[i]+Y[i]);
		maN=max(maN,X[i]-Y[i]);
		miN=min(miN,X[i]-Y[i]);
	}
	
	cout<<max(maP-miP,maN-miN)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
