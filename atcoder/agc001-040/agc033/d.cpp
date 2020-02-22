
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
string A[202];
int dp[200][200];

short R[190][190][190][18]; //y1,y2,x,n
short D[190][190][190][18]; //x1,x2,y,n

int ok(int y1,int y2,int x1,int x2) {
	if(y2>H || x2>W) return 0;
	int num=dp[y2][x2]-dp[y1][x2]-dp[y2][x1]+dp[y1][x1];
	return num==0 || num==(y2-y1)*(x2-x1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>A[y];
		FOR(x,W) {
			dp[y+1][x+1]=dp[y+1][x]+dp[y][x+1]-dp[y][x];
			if(A[y][x]=='#') dp[y+1][x+1]++;
		}
	}
	
	int y1,y2,x1,x2;
	FOR(y1,H) for(y2=y1+1;y2<=H;y2++) {
		FOR(x,W) {
			R[y1][y2][x][0]=x;
			for(i=8;i>=0;i--) if(ok(y1,y2,x,R[y1][y2][x][0]+(1<<i))) R[y1][y2][x][0]+=1<<i;
		}
		FOR(i,17) R[y1][y2][W][i]=W;
	}
	FOR(x1,W) for(x2=x1+1;x2<=W;x2++) {
		FOR(y,H) {
			D[x1][x2][y][0]=y;
			for(i=8;i>=0;i--) if(ok(y,D[x1][x2][y][0]+(1<<i),x1,x2)) D[x1][x2][y][0]+=1<<i;
		}
		FOR(i,17) D[x1][x2][H][i]=H;
	}
	
	if(R[0][H][0][0]==W) return _P("0\n");
	for(i=1;i<=17;i++) {
		FOR(y1,H) for(y2=y1+1;y2<=H;y2++) FOR(x,W) R[y1][y2][x][i]=R[y1][y2][R[y1][y2][x][i-1]][i-1];
		FOR(x1,W) for(x2=x1+1;x2<=W;x2++) FOR(y,H) D[x1][x2][y][i]=D[x1][x2][D[x1][x2][y][i-1]][i-1];
		FOR(y1,H) FOR(x1,W) {
			for(y2=y1+1;y2<=H;y2++) {
				x=R[y1][y2][x1][i];
				D[x1][x][y1][i]=max(D[x1][x][y1][i],(short)y2);
			}
			for(x2=x1+1;x2<=W;x2++) {
				y=D[x1][x2][y1][i];
				R[y1][y][x1][i]=max(R[y1][y][x1][i],(short)x2);
			}
			for(y=H-1;y>y1;y--) R[y1][y][x1][i]=max(R[y1][y][x1][i],R[y1][y+1][x1][i]);
			for(x=W-1;x>x1;x--) D[x1][x][y1][i]=max(D[x1][x][y1][i],D[x1][x+1][y1][i]);
		}
		if(R[0][H][0][i]==W) return _P("%d\n",i);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
