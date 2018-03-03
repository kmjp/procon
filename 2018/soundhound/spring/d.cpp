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

int H,W;
ll P[10][505050];
ll F[10][505050];
ll R[505005];
ll L[505005];
ll L2[505005];
ll R2[505005];
ll C[10][505005];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>P[y][x];
	FOR(y,H) FOR(x,W) cin>>F[y][x];
	
	ll ma=0;
	FOR(x,W) {
		C[0][x]=P[0][x]-F[0][x];
		if(x) C[0][x]+=C[0][x-1];
		
	}
	for(x=W-2;x>=0;x--) {
		R[x]=max(0LL,R[x+1]+P[0][x+1]-F[0][x+1]-F[0][x]);
		C[0][x]+=R[x];
	}
	for(y=1;y<H;y++) {
		for(x=1;x<W;x++) L[x]=max(0LL,L[x-1]+P[y][x-1]-F[y][x-1]-F[y][x]);
		for(x=W-2;x>=0;x--) R[x]=max(0LL,R[x+1]+P[y][x+1]-F[y][x+1]-F[y][x]);
		FOR(x,W) C[y][x]=-1LL<<60;
		FOR(x,W) {
			L2[x]=C[y-1][x]+P[y][x]-F[y][x]+L[x];
			if(x) L2[x]=max(L2[x],L2[x-1]+P[y][x]-F[y][x]);
			C[y][x]=max(C[y][x],L2[x]+R[x]);
		}
		for(x=W-1;x>=0;x--) {
			R2[x]=C[y-1][x]+P[y][x]-F[y][x]+R[x];
			if(x<W-1) R2[x]=max(R2[x],R2[x+1]+P[y][x]-F[y][x]);
			C[y][x]=max(C[y][x],R2[x]+L[x]);
		}
	}
	
	FOR(x,W) cout<<C[H-1][x]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
