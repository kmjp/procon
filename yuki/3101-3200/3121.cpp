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
int SX,SY;
int GX,GY;
string S[40];

int dp[40][40][4010][3];

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	divp[0]=divp[1]=1;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>H>>W;
	cin>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,H) cin>>S[y];
	if(SX>GX) {
		FOR(y,H) reverse(ALL(S[y]));
		SX=W-1-SX;
		GX=W-1-GX;
	}
	if(SY>GY) {
		FOR(y,H) if(y<H-1-y) swap(S[y],S[H-1-y]);
		SY=H-1-SY;
		GY=H-1-GY;
	}
	
	S[GY][GX]=S[SY][SX]='.';
	FOR(y,H) FOR(x,W) FOR(i,4000) dp[y][x][i][0]=dp[y][x][i][1]=dp[y][x][i][2]=1<<30;
	deque<int> Q;
	dp[SY][SX][0][0]=0;
	Q.push_back(SY*10000000+SX*100000);
	int ret=1<<30;
	while(Q.size()) {
		int cy=Q.front()/10000000;
		int cx=Q.front()/100000%100;
		int cur=Q.front()/10%10000;
		int z=Q.front()%10;
		Q.pop_front();
		if(cur>4000) continue;
		int co=dp[cy][cx][cur][z];
		if(cy==GY&&cx==GX&&cur&&z) {
			int R=cur;
			int L=cur-(GX-SX);
			int D=co;
			int U=co-(GY-SY);
			if(R-L==1&&L>2) continue;
			if(D-U==1&&D>2) continue;
			while(L<10000&&(divp[L]||divp[R])) L++,R++;
			while(D<10000&&(divp[D]||divp[U])) U++,D++;
			if(divp[L]==0&&divp[R]==0&&divp[D]==0&&divp[U]==0) ret=min(ret,L+R+U+D);
		}
		
		FOR(i,4) {
			int dx[4]={-1,1,0,0};
			int dy[4]={0,0,-1,1};
			int tx=cx+dx[i];
			int ty=cy+dy[i];
			if(tx<0||tx>=W||ty<0||ty>=H||S[ty][tx]=='#') continue;
			if(i==1) {
				if(chmin(dp[ty][tx][cur+1][z],dp[cy][cx][cur][z])) Q.push_front(ty*10000000+tx*100000+(cur+1)*10+z);
			}
			if(i==3) {
				if(chmin(dp[ty][tx][cur][min(2,z+1)],dp[cy][cx][cur][z]+1)) Q.push_back(ty*10000000+tx*100000+cur*10+min(2,z+1));
			}
			if(i==0||i==2) {
				if(chmin(dp[ty][tx][cur][z],dp[cy][cx][cur][z])) Q.push_front(ty*10000000+tx*100000+cur*10+z);
			}
			
		}
	}
	if(ret>1<<29) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
