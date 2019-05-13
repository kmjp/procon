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

int N,Q;
ll A[101010];
ll S[101010];
ll T[101010];
ll X;

int ok(int v) {
	if(v>N) return 0;
	
	int aa=(v+1)/2;
	int re=N-aa;
	int x=lower_bound(A,A+N,X-(A[re]-X))-A;
	return (x+v<=N);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		T[i+1]=(i>=1?T[i-1]:0)+A[i];
	}
	
	while(Q--) {
		cin>>X;
		int turn=0;
		for(i=20;i>=0;i--) {
			if(ok(turn+(1<<i))) turn+=1<<i;
		}
		
		int a=(turn+1)/2;
		if(turn%2) turn++;
		
		ll ret=S[N]-S[N-turn/2];
		if(turn<N) ret+=T[N-turn];
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
