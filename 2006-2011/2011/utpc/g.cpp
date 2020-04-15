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
ll L[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	sort(L,L+N);
	
	ll ma=0;
	ll ma1=-1LL<<60;
	
	for(i=N-3;i>=0;i--) {
		if(i>=2 && L[i]<L[i-1]+L[i-2]) ma=max(ma,L[i]+L[i-1]+L[i-2]+ma1);
		if(L[i+2]<L[i]+L[i+1]) ma1=max(ma1,L[i]+L[i+1]+L[i+2]);
	}
	FOR(i,N-5) {
		FOR(j,64) if(__builtin_popcount(j)==3) {
			vector<ll> V[2];
			FOR(x,6) V[(j>>x)&1].push_back(L[i+x]);
			if(V[0][2]<V[0][1]+V[0][0]&&V[1][2]<V[1][1]+V[1][0]) ma=max(ma,L[i]+L[i+1]+L[i+2]+L[i+3]+L[i+4]+L[i+5]);
		}
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
