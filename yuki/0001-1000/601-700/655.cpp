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

int N,K;
ll P;
int D[4040][4040];
int L[4040][4040];
int R[4040][4040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>P;
	
	FOR(x,N) FOR(y,N) D[x][y]=101010;
	queue<pair<int,int>> Q;
	FOR(i,K) {
		cin>>x>>y;
		x--,y--;
		D[x][y]=0;
		Q.push({x,y});
	}
	
	while(Q.size()) {
		x=Q.front().first;
		y=Q.front().second;
		Q.pop();
		
		int dx[6]={-1,0,-1,1,0,1};
		int dy[6]={-1,-1,0,0,1,1};
		FOR(i,6) {
			int tx=x+dx[i];
			int ty=y+dy[i];
			if(tx<0 || tx>=N || ty<0 || ty>tx) continue;
			if(D[tx][ty]>D[x][y]+1) {
				D[tx][ty]=D[x][y]+1;
				Q.push({tx,ty});
			}
		}
	}
	
	for(x=N-1;x>=0;x--) {
		FOR(y,x+1) {
			L[x][y]=D[x][y]+L[x+1][y];
			R[x][y]=D[x][y]+R[x+1][y+1];
		}
	}
	
	ll ret=0;
	for(x=N-1;x>=0;x--) {
		ll S=0;
		for(int LL=0,RR=-1;LL<=x;LL++) {
			
			if(RR<=LL) RR=LL, S=0;
			while(RR<=x&&S+(R[x-(RR-LL)][LL]-R[x+1][RR+1])<P) {
				S+=(R[x-(RR-LL)][LL]-R[x+1][RR+1]);
				RR++;
			}
			ret+=x+1-RR;
			S-=(L[x-(RR-1-LL)][LL]-L[x+1][LL]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
