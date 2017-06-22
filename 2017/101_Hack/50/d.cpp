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

const int MAT=400;
struct Mat { double v[MAT][MAT]; };
Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	static Mat r;
	int x,y,z;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) if(a.v[x][z]) FOR(y,n) if(b.v[z][y]) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
	}
	return r;
}

int H,W,Q;
string S[404];
int tar[400];
vector<int> to[20][20];
int SY,SX;
vector<int> G;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	static Mat m;
	cin>>H>>W>>Q;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) tar[y*20+x]=y*20+x;
	FOR(i,Q) {
		int X1,Y1,X2,Y2;
		cin>>Y1>>X1>>Y2>>X2;
		Y1--,X1--,Y2--,X2--;
		tar[Y1*20+X1]=Y2*20+X2;
		tar[Y2*20+X2]=Y1*20+X1;
	}
	FOR(y,H) FOR(x,W) {
		if(S[y][x]=='A') SY=y, SX=x, S[y][x]='O';
		if(S[y][x]=='%') G.push_back(y*20+x), S[y][x]='*';
		if(S[y][x]=='*') to[y][x].push_back(y*20+x);
		if(S[y][x]=='O') {
			if(y && S[y-1][x]!='#') to[y][x].push_back(tar[(y-1)*20+x]);
			if(y<H-1 && S[y+1][x]!='#') to[y][x].push_back(tar[(y+1)*20+x]);
			if(x && S[y][x-1]!='#') to[y][x].push_back(tar[y*20+x-1]);
			if(x<W-1 && S[y][x+1]!='#') to[y][x].push_back(tar[y*20+x+1]);
			if(to[y][x].empty()) to[y][x].push_back(y*20+x);
		}
	}
	FOR(y,H) FOR(x,W) {
		FORR(e,to[y][x]) m.v[y*20+x][e] = 1.0/to[y][x].size();
	}
	FOR(i,50) m=mulmat(m,m);
	
	double ret=0;
	FORR(e,G) ret+=m.v[SY*20+SX][e];
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
