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

ll P,Q,A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q>>A;
	P+=100;
	Q+=100;
	A*=100;
	ll ret=0;
	for(i=1;i<=100000000;i++) {
		ll a=(i*P);
		ll b=(i*Q)+A;
		if(a/100<b/100) ret++;
	}
	ll a=(100000001*P);
	ll b=(100000001*Q)+A;
	if(a/100<b/100) ret+=900000000;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
