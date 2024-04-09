#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W;
string A[202];
int N;
int R[303],C[303],E[303];

int dp[303][202][202];

int can[303][303];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int SY,SX,TY,TX;
	FOR(y,H) {
		cin>>A[y];
		FOR(x,W) {
			if(A[y][x]=='S') {
				SY=y,SX=x;
				A[y][x]='.';
			}
			if(A[y][x]=='T') {
				TY=y,TX=x;
				A[y][x]='.';
			}
		}
	}
	cin>>N;
	FOR(i,N) {
		cin>>R[i]>>C[i]>>E[i];
		R[i]--,C[i]--;
		FOR(y,H) FOR(x,W) dp[i][y][x]=1<<20;
		queue<int> Q;
		dp[i][R[i]][C[i]]=0;
		Q.push(R[i]*W+C[i]);
		while(Q.size()) {
			int cy=Q.front()/W;
			int cx=Q.front()%W;
			Q.pop();
			FOR(j,4) {
				int d[]={0,1,0,-1};
				int ty=cy+d[j];
				int tx=cx+d[j^1];
				if(ty<0||ty>=H||tx<0||tx>=W) continue;
				if(A[ty][tx]=='#'||dp[i][ty][tx]<1<<20) continue;
				dp[i][ty][tx]=dp[i][cy][cx]+1;
				Q.push(ty*W+tx);
			}
		}
	}
	
	FOR(i,N) {
		FOR(j,N) {
			if(dp[i][R[j]][C[j]]<=E[i]) can[i][j]=1;
		}
	}
	FOR(k,N) FOR(i,N) FOR(j,N) can[i][j]|=can[i][k]&can[k][j];
	
	
	FOR(i,N) if(R[i]==SY&&C[i]==SX) {
		FOR(j,N) if(can[i][j]&&dp[j][TY][TX]<=E[j]) {
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
