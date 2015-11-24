#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[15],Y[15];
ll dp[1<<13][15][4];
ll dist[15][15][4][4];

ll di(ll DX,ll DY,int s,int t) {
	if(s>0) return di(-DY,DX,s-1,(t+3)%4);
	vector<int> V;
	
	if(DY>=0 && DX<=0) V={4,6,8,4};
	else if(DY<0 && DX<=0) V={4,6,2,2};
	else if(DY==0 && DX>0) V={0,0,6,4};
	else if(DX>0 && DY>0) V={4,4,6,4};
	else if(DX>0 && DY<0) V={4,0,0,2};
	else assert(0);
	
	return abs(DX)+abs(DY)+V[t];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i+1]>>Y[i+1];
	N++;
	
	FOR(i,N) FOR(j,N) if(i!=j) {
		FOR(x,4) FOR(y,4) dist[i][j][x][y] = di(X[j]-X[i],Y[j]-Y[i],x,y);
	}
	FOR(i,4) dp[1][0][i]=0;
	for(int mask=2;mask<1<<N;mask++) {
		FOR(x,4) FOR(i,N) if(mask&(1<<i)) {
			dp[mask][i][x]=1LL<<40;
			FOR(j,N) if((mask&(1<<j)) && (i!=j)) {
				FOR(y,4) dp[mask][i][x] = min(dp[mask][i][x],dp[mask^(1<<i)][j][y] + dist[j][i][y][x]);
			}
		}
	}
	
	ll mi=1LL<<40;
	FOR(i,4) FOR(j,N) mi=min(mi,dp[(1<<N)-1][j][i]);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
