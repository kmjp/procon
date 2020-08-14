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

ll P,Q;
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q;
	ll ret=0;
	// yoko
	ll cur=24;
	for(i=3;i<=P;i++) cur=cur*2%mo;
	ret+=cur;
	cur=24;
	for(i=3;i<=Q;i++) cur=cur*2%mo;
	ret+=cur;
	ret+=mo-24;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
