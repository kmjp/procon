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
int A[202][202];
ll ma[402][202][202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	ma[0][0][0]=A[0][0];
	
	FOR(i,H+W-2) {
		int y1,y2,x1,x2;
		FOR(y1,H) FOR(y2,H) {
			x1=i-y1;
			x2=i-y2;
			if(x1<0 || x1>=W || x2<0 || x2>=W) continue;
			ll v=ma[i][y1][y2];
			if(x1<W-1 && x2<W-1) { //RR
				if(y1==y2) ma[i+1][y1][y2] = max(ma[i+1][y1][y2],v+A[y1][x1+1]);
				else ma[i+1][y1][y2] = max(ma[i+1][y1][y2],v+A[y1][x1+1]+A[y2][x2+1]);
			}
			if(x1<W-1 && y2<H-1) { // RD
				if(x1+1==x2) ma[i+1][y1][y2+1] = max(ma[i+1][y1][y2+1],v+A[y1][x1+1]);
				else ma[i+1][y1][y2+1] = max(ma[i+1][y1][y2+1],v+A[y1][x1+1]+A[y2+1][x2]);
			}
			if(y1<H-1 && x2<W-1) { // DR
				if(y1+1==y2) ma[i+1][y1+1][y2] = max(ma[i+1][y1+1][y2],v+A[y1+1][x1]);
				else ma[i+1][y1+1][y2] = max(ma[i+1][y1+1][y2],v+A[y1+1][x1]+A[y2][x2+1]);
			}
			if(y1<H-1 && y2<H-1) { //DD
				if(y1==y2) ma[i+1][y1+1][y2+1] = max(ma[i+1][y1+1][y2+1],v+A[y1+1][x1]);
				else ma[i+1][y1+1][y2+1] = max(ma[i+1][y1+1][y2+1],v+A[y1+1][x1]+A[y2+1][x2]);
			}
			
		}
	}
	cout<<ma[H+W-2][H-1][H-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
