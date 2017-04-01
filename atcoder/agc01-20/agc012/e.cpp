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

int N,V;
int X[202020],id[202020];
pair<ll,int> P[202020];
int ret[202020],imos[202020];

int ML;
int L[202020][20],R[202020][20];
int Ldp[1<<20];
int Rdp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V;
	FOR(i,N) cin>>x, P[i]={x,i};
	sort(P,P+N);
	FOR(i,N) id[P[i].second]=i, X[i]=P[i].first;
	
	while(1<<ML <= V) ML++;
	ML++;
	
	FOR(i,20) {
		FOR(x,N) {
			if(x && X[x]-X[x-1]<=V>>i) L[x][i]=L[x-1][i];
			else L[x][i]=x;
		}
		for(x=N-1;x>=0;x--) {
			if(x<N-1 && X[x+1]-X[x]<=V>>i) R[x][i]=R[x+1][i];
			else R[x][i]=x;
		}
	}
	
	MINUS(Ldp);
	FOR(i,1<<ML) Ldp[i]=-2,Rdp[i]=N+1;
	Ldp[0]=-1;
	Rdp[0]=N;
	
	for(int mask=0;mask<1<<ML;mask++) {
		FOR(i,ML) if((mask & (1<<i))==0) {
			if(Ldp[mask]==N-1) Ldp[mask | (1<<i)] = N-1;
			else if(Ldp[mask]>=-1) Ldp[mask | (1<<i)] = max(Ldp[mask | (1<<i)], R[Ldp[mask]+1][i]);
			if(Rdp[mask]==0) Rdp[mask | (1<<i)] = 0;
			else if(Rdp[mask]<=N) Rdp[mask | (1<<i)] = min(Rdp[mask | (1<<i)], L[Rdp[mask]-1][i]);
		}
	}
	
	for(int mask=0;mask<1<<ML;mask+=2) {
		int mask2=((1<<ML)-2)^mask;
		if(Ldp[mask]+1>=Rdp[mask2]) {
			FOR(i,N) ret[i]=1;
			break;
		}
		if(R[Ldp[mask]+1][0]+1>=Rdp[mask2]) {
			imos[Ldp[mask]+1]++;
			imos[R[Ldp[mask]+1][0]+1]--;
		}
	}
	
	FOR(i,N) {
		imos[i+1]+=imos[i];
		ret[i] |= imos[i];
		if(ret[id[i]]) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
