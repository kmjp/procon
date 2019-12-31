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

int N,M,C,D;
int A[30][2];
int first[30];
int mat[30][30];
char ok[1<<20];

int dist[1<<20][21][2];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M>>C>>D;
	FOR(i,N) cin>>A[i][0]>>A[i][1];
	FOR(i,M) {
		cin>>x>>y;
		mat[y-1][x-1] = 1;
	}
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y] |= mat[x][z] && mat[z][y];
	FOR(x,N) FOR(y,N) if(mat[x][y]) first[x] |= 1<<y;
	
	memset(dist,0x3f,sizeof(dist));
	FOR(x,N) if(first[x]==0) ok[(1<<x)]=1, dist[(1<<x)][0][0]=A[x][0], dist[(1<<x)][0][1]=A[x][1];
	
	int c,ret=1<<30;
	for(int mask=1;mask<(1<<N);mask++) if(ok[mask]) {
		FOR(c,2) FOR(x,20) if(dist[mask][x][c]<0x3f3f3f3f) {
			int &d=dist[mask][x][c];
			if(mask==(1<<N)-1) {
				ret=min(ret,d);
				continue;
			}
			FOR(y,N) if((mask&(1<<y))==0) {
				if((first[y] & mask)!=first[y]) continue;
				ok[mask|(1<<y)]=1;
				dist[mask|(1<<y)][x][c] = min(dist[mask|(1<<y)][x][c], d+A[y][c]);
				dist[mask|(1<<y)][x+1][c^1] = min(dist[mask|(1<<y)][x+1][c^1], d+A[y][1]+D+x*C);
			}
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
