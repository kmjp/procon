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

int N,L;
int X[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N-1) cin>>X[i+1], X[i+1]+=100000;
	X[0]=100000;
	FOR(i,N-1) if(abs(X[i]-X[i+1])>=L) return _P("-1\n");
	ll tot=0;
	int ret=0;
	for(i=N-1;i>=0;i--) {
		if(i<=N-2) {
			ll mul=2*(N-1-i);
			if(tot<=X[i+1]*mul||(X[i+1]+L)*mul<=tot||tot<=X[i]*mul||(X[i]+L)*mul<=tot) ret++;
		}
		
		tot += 2*X[i]+L;
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
