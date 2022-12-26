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
ll A,B,C;
ll G[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C;
	FOR(i,N) cin>>G[i];
	sort(G,G+N);
	ll ret=0;
	ll L=-1,R=0;
	FOR(i,N) {
		while(L<N-1 && G[L+1]+A<G[i]+B) L++;
		while(R<N && G[R]+C<=G[i]+B) R++;
		
		ret+=(L+1)*(N-R);
		if(L>=i) ret-=(N-R);
		if(R<=i) ret-=(L+1);
		if(L>=R) ret-=(L-R+1);
		if(L>=i && R<=i) ret+=2;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
