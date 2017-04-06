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

int N,T;
int S[1010];
int X[1010];
int Y[1010];
int Q;
int near[1010];

int dist(int a,int b) {
	return abs(X[a]-X[b])+abs(Y[a]-Y[b]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) cin>>S[i]>>X[i]>>Y[i];
	FOR(i,N) {
		if(S[i]) near[i]=i;
		else {
			near[i]=-1;
			FOR(j,N) if(S[j] && i!=j && (near[i]==-1 || dist(i,j)<dist(i,near[i]))) near[i]=j;
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		
		int mi=dist(x,y);
		mi=min(mi,dist(x,near[x])+dist(y,near[y])+T);
		
		cout<<mi<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
