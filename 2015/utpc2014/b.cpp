#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

double X,Y;
int XX,YY;
bool DX,DY;

void output(int x1,int y1,int x2,int y2) {
	x1/=1000;
	x2/=1000;
	y1/=1000;
	y2/=1000;
	if(DX) x1=-x1, x2=-x2;
	if(DY) y1=-y1, y2=-y2;
	_P("%d %d %d %d\n",x1,y1,x2,y2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	XX=X*1000+(X>0?0.5:-0.5);
	YY=Y*1000+(Y>0?0.5:-0.5);
	if(XX<0) DX=true, XX=-XX;
	if(YY<0) DY=true, YY=-YY;
	
	if(XX%1000==0 && YY%1000==0) {
		output(XX,-1000,XX,1000);
		output(-1000,YY,1000,YY);
		return;
	}
	int ty=YY/1000*1000, ry=YY-ty;
	int tx=XX/1000*1000, rx=XX-tx;
	
	if(XX%1000==0) {
		output(XX,-1000,XX,1000);
		output(XX-1000*ry,ty,XX+1000*(1000-ry),ty+1000);
		return;
	}
	if(YY%1000==0) {
		output(-1000,YY,1000,YY);
		output(tx,YY-1000*rx,tx+1000,YY+1000*(1000-rx));
		return;
	}
	output(tx,ty,tx+1000*rx,ty+1000*ry);
	output(tx,ty+1000,tx+1000*rx,ty+1000-1000*(1000-ry));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
