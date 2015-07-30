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

ll N,W,H,ra,R,VX,VY;
ll X[12],Y[12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double eps=1e-10;
	while(1) {
		cin>>N;
		if(N==0) return;
		cin>>W>>H>>R>>VX>>VY;
		FOR(i,N) cin>>X[i]>>Y[i], X[i]-=R, Y[i]-=R;
		W-=2*R;
		H-=2*R;
		
		double mi=11010,dist=0;
		double cx=X[0],cy=Y[0];
		int id=-1;
		while(dist<10000) {
			double tim=(10000-dist)/sqrt(VX*VX+VY*VY);
			if(VX) tim=min(tim, (VX>0)?(W-cx)/VX:(cx)/(-VX));
			if(VY) tim=min(tim, (VY>0)?(H-cy)/VY:(cy)/(-VY));
			
			for(i=1;i<N;i++) {
				double sx=cx-X[i],sy=cy-Y[i];
				// (sx+t*vx)^2+(sy+t*vy)^2=4*R^2
				double A=VX*VX+VY*VY;
				double B=2*(VX*sx+VY*sy);
				double C=sx*sx+sy*sy-4*R*R;
				double D=B*B-4*A*C;
				if(D<0) continue;
				double x1=(-B-sqrt(D))/(2*A), y1=dist+x1*sqrt(VX*VX+VY*VY);
				double x2=(-B+sqrt(D))/(2*A), y2=dist+x2*sqrt(VX*VX+VY*VY);
				if(x1>=0 && x1<=tim && y1<mi) mi=y1, id=i+1;
				if(x2>=0 && x2<=tim && y2<mi) mi=y2, id=i+1;
			}
			if(id!=-1) break;
			dist += tim*sqrt(VX*VX+VY*VY);
			cx+=VX*tim;
			cy+=VY*tim;
			if(cx<eps || cx>W-eps) VX=-VX;
			if(cy<eps || cy>H-eps) VY=-VY;
		}
		
		cout<<id<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
