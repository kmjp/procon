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
ll W,H;
ll L[301010];
ll S[301010];
ll from[301010],to[301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>W>>H;
	FOR(i,N) {
		cin>>L[i];
		S[i+1]=S[i]+L[i]+1;
	}
	FOR(i,N) S[N+i+1]=S[N+i]+L[i]+1;
	FOR(i,N) S[2*N+i+1]=S[2*N+i]+L[i]+1;
	
	FOR(i,N) from[i]=W/S[N]*N;
	W%=S[N];
	x=0;
	FOR(i,N) {
		while(S[x+1]-S[i]-1<=W) x++;
		from[i]+=x-i;
	}
	
	ll ret=0;
	while(H) {
		
		if(H%2) ret += from[ret%N];
		FOR(i,N) to[i]=from[(i+from[i])%N]+from[i];
		swap(from,to);
		
		H>>=1;
	}
	cout<<(ret+N-1)/N<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
