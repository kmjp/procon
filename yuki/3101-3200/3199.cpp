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

int H,W,M;
int dp[505][505][12];
string S[505];
int K[505][505];
int D[505][505];
int SY,SX,GY,GX;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>M;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) {
			FOR(i,M+1) dp[y][x][i]=1<<30;
			if(S[y][x]=='S') {
				S[y][x]='.';
				SX=x,SY=y;
			}
			if(S[y][x]=='G') {
				S[y][x]='.';
				GX=x,GY=y;
			}
			if(S[y][x]>='1'&&S[y][x]<='9') {
				K[y][x]=S[y][x]-'0';
				S[y][x]='.';
			}
			if(S[y][x]>='a'&&S[y][x]<='i') {
				D[y][x]=S[y][x]-'a'+1;
				S[y][x]='.';
			}
		}
	}
	dp[SY][SX][0]=0;
	queue<int> Q;
	Q.push(SY*100000+SX*10+0);
	while(Q.size()) {
		int cy=Q.front()/100000;
		int cx=Q.front()/10%1000;
		int cur=Q.front()%10;
		Q.pop();
		if(cy==GY&&cx==GX) {
			cout<<dp[cy][cx][cur]<<endl;
			return;
		}
		
		int d[]={0,1,0,-1};
		FOR(i,4) {
			int tx=cx+d[i];
			int ty=cy+d[i^1];
			if(tx<0||tx>=W||ty<0||ty>=H||S[ty][tx]=='#') continue;
			if(D[ty][tx]&&cur!=D[ty][tx]) continue;
			int tcur=cur;
			if(K[ty][tx]) tcur=K[ty][tx];
			if(chmin(dp[ty][tx][tcur],dp[cy][cx][cur]+1)) Q.push({ty*100000+tx*10+tcur});
		}
	}
	cout<<-1<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
