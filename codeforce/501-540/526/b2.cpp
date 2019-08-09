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
ll S,V[1010];

int ok(ll v) {
	ll tot=0;
	int i;
	FOR(i,N) {
		if(V[i]<v) return 0;
		tot+=V[i]-v;
	}
	return tot>=S;

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	ll tot=0;
	FOR(i,N) {
		cin>>V[i];
		tot+=V[i];
	}
	
	if(tot<S) return _P("-1\n");
	
	ll ma=0;
	for(i=30;i>=0;i--) if(ok(ma+(1<<i))) ma+=(1<<i);
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
