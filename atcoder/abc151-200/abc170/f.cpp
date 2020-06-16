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

int H,W,K;
int SY,SX,TY,TX;
string S[1010101];
vector<int> D[4][1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	cin>>SY>>SX>>TY>>TX;
	SY--,SX--,TY--,TX--;
	FOR(y,H) {
		cin>>S[y];
		FOR(i,4) D[i][y].resize(W);
	}
	
	FOR(y,H) FOR(x,W) FOR(i,4) D[i][y][x]=1<<30;
	priority_queue<pair<int,int>> Q;
	FOR(i,4) {
		D[i][SY][SX]=0;
		Q.push({0,i*1000000+SY*W+SX});
	}
	while(Q.size()) {
		int co=-Q.top().first;
		int dir=Q.top().second/1000000;
		int cy=Q.top().second%1000000/W;
		int cx=Q.top().second%1000000%W;
		Q.pop();
		
		if(D[dir][cy][cx]!=co) continue;
		
		
		if(cy==TY&&cx==TX) {
			cout<<(co+K-1)/K<<endl;
			return;
		}
		int dy[4]={0,1,0,-1};
		int dx[4]={1,0,-1,0};
		FOR(i,4) {
			if(i==dir) {
				int ty=cy+dy[i];
				int tx=cx+dx[i];
				if(ty<0 ||ty>=H || tx<0 || tx>=W || S[ty][tx]=='@') continue;
				if(D[i][ty][tx]>co+1) {
					D[i][ty][tx]=co+1;
					Q.push({-D[i][ty][tx], i*1000000+ty*W+tx});
				}
			}
			else {
				int nco=(co+K-1)/K*K;
				if(D[i][cy][cx]>nco) {
					D[i][cy][cx]=nco;
					Q.push({-D[i][cy][cx], i*1000000+cy*W+cx});
				}
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
