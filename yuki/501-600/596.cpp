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

int N,M;
int L[7070707], R[7070707];

int add[7]={0,1,1,2,3,3,0};
int lef[7]={0,0,1,1,1,1,0};
int rig[7]={0,1,0,1,1,1,0};
// before, ->, <- , <-> , ->/<-/->, <-/->/<-, done
// 1-non 2-start 3-end
int mat[7][7]={
	{1,2,3,1,2,3,1},
	{0,1,0,3,1,0,3},
	{0,0,1,2,0,1,2},
	{0,2,3,1,0,0,1},
	{0,1,0,0,1,0,3},
	{0,0,1,0,0,1,2},
	{0,0,0,0,0,0,1},
};
int from[7][2][2];
int to[7][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int miX=N,maX=0;
	
	FOR(i,M) {
		int X,miy,may;
		cin>>X>>x;
		miy=may=X;
		while(x--) {
			cin>>y;
			miy=min(miy,y);
			may=max(may,y);
		}
		L[miy]++;
		L[X]--;
		R[X]++;
		R[may]--;
		miX=min(miX,miy);
		maX=max(maX,may);
	}
	
	FOR(i,7) FOR(x,2) FOR(y,2) from[i][x][y]=1<<30;
	from[0][0][0]=0;
	FOR(i,N) {
		FOR(j,7) FOR(x,2) FOR(y,2) to[j][x][y]=1<<30;
		
		FOR(y,7) {
			if(L[i]&&lef[y]==0) continue;
			if(R[i]&&rig[y]==0) continue;
			FOR(x,7) if(mat[x][y]) {
				FOR(j,2) FOR(k,2) {
					int j2=j+(mat[x][y]==2);
					int k2=k+(mat[x][y]==3);
					if(j2<2 && k2<2) to[y][j2][k2]=min(to[y][j2][k2],from[x][j][k]+add[y]);
				}
			}
		}
		
		if(i>=miX) to[0][0][0]=1<<30;
		if(i+1<=maX) to[6][0][0]=to[6][1][1]=1<<30;
		
		L[i+1]+=L[i];
		R[i+1]+=R[i];
		swap(from,to);
	}
	
	cout<<min(from[6][0][0],from[6][1][1])<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
