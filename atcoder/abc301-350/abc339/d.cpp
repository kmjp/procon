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

int N;
string S[66];


int dp[66][66][66][66];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) FOR(i,N) FOR(j,N) dp[y][x][i][j]=1<<30;
	
	int y1=-1,y2,x2,x1;
	FOR(y,N) {
		cin>>S[y];
		ll mask=0;
		FOR(x,N) {
			if(S[y][x]=='P') {
				S[y][x]='.';
				if(y1==-1) {
					y1=y;
					x1=x;
				}
				else {
					y2=y;
					x2=x;
				}
			}
		}
	}
	
	dp[y1][x1][y2][x2]=0;
	queue<int> Q;
	Q.push(y1*1000000+x1*10000+y2*100+x2);
	while(Q.size()) {
		int cy1=Q.front()/1000000;
		int cx1=Q.front()/10000%100;
		int cy2=Q.front()/100%100;
		int cx2=Q.front()%100;
		Q.pop();
		if(cy1==cy2&&cx2==cx1) {
			cout<<dp[cy1][cx1][cy2][cx2]<<endl;
			return;
		}
		int dy[]={0,1,0,-1};
		int dx[]={1,0,-1,0};
		FOR(i,4) {
			int ty1=cy1;
			int tx1=cx1;
			int ty2=cy2;
			int tx2=cx2;
			if(ty1+dy[i]>=0&&ty1+dy[i]<N&&tx1+dx[i]>=0&&tx1+dx[i]<N&&S[ty1+dy[i]][tx1+dx[i]]=='.') {
				ty1+=dy[i];
				tx1+=dx[i];
			}
			if(ty2+dy[i]>=0&&ty2+dy[i]<N&&tx2+dx[i]>=0&&tx2+dx[i]<N&&S[ty2+dy[i]][tx2+dx[i]]=='.') {
				ty2+=dy[i];
				tx2+=dx[i];
			}
			if(dp[ty1][tx1][ty2][tx2]==1<<30) {
				dp[ty1][tx1][ty2][tx2]=dp[cy1][cx1][cy2][cx2]+1;
				Q.push(ty1*1000000+tx1*10000+ty2*100+tx2);
			}
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
