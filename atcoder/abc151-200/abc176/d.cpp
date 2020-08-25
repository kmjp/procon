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
int SY,SX,GY,GX;
string S[1010];
int D[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) D[y][x]=1010101;
	}
	
	deque<int> Q;
	D[SY][SX]=0;
	Q.push_front(SY*1000+SX);
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop_front();
		
		if(cy==GY&&cx==GX) {
			cout<<D[cy][cx]<<endl;
			return;
		}
		
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=cy+dd[i];
			int tx=cx+dd[i^1];
			if(ty<0||ty>=H||tx<0||tx>=W||S[ty][tx]=='#') continue;
			if(D[ty][tx]>D[cy][cx]) {
				D[ty][tx]=D[cy][cx];
				Q.push_front(ty*1000+tx);
			}
		}
		for(int ty=max(0,cy-2);ty<=min(H-1,cy+2);ty++) {
			for(int tx=max(0,cx-2);tx<=min(W-1,cx+2);tx++) {
				if(S[ty][tx]=='.'&&D[ty][tx]>D[cy][cx]+1) {
					D[ty][tx]=D[cy][cx]+1;
					Q.push_back(ty*1000+tx);
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
