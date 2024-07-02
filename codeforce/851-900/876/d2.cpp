#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,C[505];
int from[505][505][2];
int to[505][505][2];

int ret[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>C[i];
		FOR(i,N+2) FOR(j,N+2) from[i][j][0]=from[i][j][1]=1<<30;
		from[0][0][0]=0;
		
		FOR(i,N) {
			FOR(x,N+2) FOR(y,N+2) to[x][y][0]=to[x][y][1]=1<<30;
			// x=Šm’è‚µ‚½’l y=seg”
			FOR(x,N+2) FOR(y,N+2) {
				if(x<C[i]) {
					chmin(to[C[i]][y][0],from[x][y][0]);
					chmin(to[C[i]][y][0],from[x][y][1]);
				}
				chmin(to[x][y+1][1],from[x][y][0]+1);
				chmin(to[x][y][1],from[x][y][1]+1);
				
			}
			swap(from,to);
		}
		FOR(i,N) ret[i+1]=1<<20;
		FOR(x,N+1) FOR(y,N+1) {
			k=min(from[x][y][0],from[x][y][1]);
			for(i=y;i<=N;i++) ret[i]=min(ret[i],k);
		}
		
		FOR(i,N) cout<<ret[i+1]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
