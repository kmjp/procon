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
int nex[402020],pre[402020];
int tar[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) {
		nex[i]=pre[i]=N+i;
		nex[N+i]=pre[N+i]=i;
	}
	FOR(i,Q) {
		int F,T,X;
		cin>>F>>T>>X;
		X+=N;
		
		int FT=pre[F];
		int PT=pre[X];
		int TT=pre[T];
		
		nex[PT]=F;
		pre[F]=PT;
		pre[X]=TT;
		TT[nex]=X;
		nex[FT]=T;
		pre[T]=FT;
	}
	
	for(i=1;i<=N;i++) {
		x=nex[i];
		while(x>N) {
			tar[x-N]=i;
			x=nex[x];
		}
	}
	for(i=1;i<=N;i++) cout<<tar[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
