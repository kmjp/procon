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

const int MAT=64;
struct Mat { double v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	int x,y,z; Mat r;
	FOR(x,n) FOR(z,n) FOR(y,n) r.v[x][y] += a.v[x][z]*b.v[z][y];
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}

int H,W,T;
int SY,SX,GY,GX;
string S[10];
Mat P,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>T;
	cin>>SY>>SX>>GY>>GX;
	SY--,SX--,GY--,GX--;
	FOR(y,10) {
		if(y<H) cin>>S[y];
		S[y]=S[y]+"############";
		S[y]=S[y].substr(0,10);
	}
	for(y=1;y<=8;y++) {
		for(x=1;x<=8;x++) if(S[y][x]=='.') {
			int d[4]={1,0,-1,0};
			int cnt=0;
			FOR(i,4) {
				int ty=y+d[i];
				int tx=x+d[i^1];
				if(S[ty][tx]=='.') cnt++;
			}
			if(cnt) {
				FOR(i,4) {
					int ty=y+d[i];
					int tx=x+d[i^1];
					if(S[ty][tx]=='.') P.v[(ty-1)*8+(tx-1)][(y-1)*8+(x-1)]=1.0/cnt;
				}
			}
			else {
				P.v[(y-1)*8+(x-1)][(y-1)*8+(x-1)]=1;
			}
		}
	}
	Q=powmat(T,P);
	
	double ret=Q.v[GY*8+GX][SY*8+SX];
	_P("%.12lf\n",ret);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
