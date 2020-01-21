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
ll A[202020];
ll S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	sort(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i];
	ll ma=0;
	for(i=1;i<N-1;i++) {
		int len=0;
		for(j=20;j>=0;j--) {
			if(i-(len+(1<<j))<0) continue;
			if(N-(len+(1<<j))<i) continue;
			if(A[i-(len+(1<<j))]+A[N-(len+(1<<j))]>2*A[i]) len+=1<<j;
		}
		ll ret=S[N]-S[N-len]+S[i]-S[i-len]-A[i]*2*len;
		ma=max(ma,ret);
		
	}
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
