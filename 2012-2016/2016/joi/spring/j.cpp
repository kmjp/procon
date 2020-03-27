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
string S[1202];
int SY,SX,TY,TX;
vector<pair<int,int>> E[1002][1002];
vector<int> Q[1020202];
int D[1002][1002];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	cin>>SY>>SX>>TY>>TX;
	SY--,TY--,SX--,TX--;
	
	FOR(y,H) {
		int px=W-1;
		for(x=W-2;x>=0;x--) {
			if(S[y][x]=='.') {
				if(px>x+1) {
					E[y][x].push_back({1,y*1000+px-1});
					E[y][x].push_back({2,y*1000+x+1});
				}
			}
			else {
				px=x;
			}
		}
		FOR(x,W) {
			if(S[y][x]=='.') {
				if(px<x-1) {
					E[y][x].push_back({1,y*1000+px+1});
					E[y][x].push_back({2,y*1000+x-1});
				}
			}
			else {
				px=x;
			}
		}
	}
	FOR(x,W) {
		int py=H-1;
		for(y=H-1;y>=0;y--) {
			if(S[y][x]=='.') {
				if(py>y+1) {
					E[y][x].push_back({1,(py-1)*1000+x});
					E[y][x].push_back({2,(y+1)*1000+x});
				}
			}
			else {
				py=y;
			}
		}
		FOR(y,H) {
			if(S[y][x]=='.') {
				if(py<y-1) {
					E[y][x].push_back({1,(py+1)*1000+x});
					E[y][x].push_back({2,(y-1)*1000+x});
				}
			}
			else {
				py=y;
			}
		}
	}
	
	
	FOR(y,H) FOR(x,W) D[y][x]=5101010;
	D[SY][SX]=0;
	Q[0].push_back(SY*1000+SX);
	int co;
	FOR(co,1020100) {
		FORR(q,Q[co]) {
			int cy=q/1000;
			int cx=q%1000;
			if(D[cy][cx]!=co) continue;
			if(cy==TY&&cx==TX) return _P("%d\n",co);
			FORR(e,E[cy][cx]) {
				int ty=e.second/1000;
				int tx=e.second%1000;
				if(D[ty][tx]>co+e.first) {
					D[ty][tx]=co+e.first;
					Q[D[ty][tx]].push_back(ty*1000+tx);
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
