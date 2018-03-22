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

int N;
int mi[201][201];
int SX,SY,GX,GY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,N) mi[y][x]=1<<30;
	cin>>SY>>SX>>GY>>GX;
	
	int dx[]={-1,1,2,1,-1,-2};
	int dy[]={-2,-2,0,2,2,0};
	string S[]={"UL", "UR", "R", "LR", "LL", "L"};
	mi[GY][GX]=0;
	
	queue<int> Q;
	Q.push(GY*1000+GX);
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		FOR(i,6) {
			int ty=cy+dy[i];
			int tx=cx+dx[i];
			if(tx<0 || tx>=N || ty<0||ty>=N) continue;
			if(mi[ty][tx]>mi[cy][cx]+1) {
				mi[ty][tx]=mi[cy][cx]+1;
				Q.push(ty*1000+tx);
			}
		}
		
	}
	if(mi[SY][SX]>=1<<30) return _P("Impossible\n");
	
	vector<string> R;
	while(GY!=SY || GX!=SX) {
		FOR(i,6) {
			int ty=SY+dy[i];
			int tx=SX+dx[i];
			if(tx<0 || tx>=N || ty<0||ty>=N) continue;
			if(mi[ty][tx]==mi[SY][SX]-1) {
				R.push_back(S[i]);
				SY=ty;
				SX=tx;
				break;
			}
		}
	}
	
	
	cout<<R.size()<<endl;
	FOR(i,R.size()) {
		cout<<R[i];
		if(i!=R.size()-1) cout<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
