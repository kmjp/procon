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
int A[1010][1010];
int B[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x], B[y][x]=A[y][x];
	
	int ma=-1;
	FOR(y,H) FOR(x,W) if(A[y][x]==1) {
		int L=x,R=x,U=y,D=y,num=0;
		queue<int> Q;
		Q.push(y*1000+x);
		A[y][x]=0;
		
		while(Q.size()) {
			int k=Q.front();
			Q.pop();
			int cy=k/1000,cx=k%1000;
			num++;
			L=min(L,cx);
			R=max(R,cx);
			U=min(U,cy);
			D=max(D,cy);
			
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=cy+dd[i];
				int tx=cx+dd[i^1];
				if(tx<0 || ty<0 || tx>=W || ty>=H) continue;
				if(A[ty][tx]) {
					A[ty][tx]=0;
					Q.push(ty*1000+tx);
				}
			}
		}
		if(L>0 && R<W-1 && U>0 && D<H-1 && (R-L+1)*(D-U+1)==num && B[U-1][L-1]+B[U-1][R+1]+B[D+1][L-1]+B[D+1][R+1]==0) ma=max(ma,num);
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
