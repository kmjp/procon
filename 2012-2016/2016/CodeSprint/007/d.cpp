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
ll A[1010101];
ll S[1010101];
ll T[1010101];
ll p2[1010101];
ll p2r[1010101];
ll p2s[1010101];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p2r[0]=1;
	FOR(i,1010000) {
		p2[i+1]=p2[i]*2%mo;
		p2r[i+1]=p2r[i]*(mo+1)/2%mo;
	}
	for(i=1;i<=1000000;i++) p2s[i]=(p2s[i-1]+i*p2[1000001-i])%mo;
	
	ll ret=0;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>x;
		
		T[i]=T[i-1]+S[i-1]+x*((p2s[i-1]*p2r[1000001-(i-1)]+i)%mo);
		T[i] %= mo;
		S[i] = (S[i-1] + p2[i-1]*x)%mo;
		ret += T[i] * p2[max(0,N-1-i)] % mo;
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
