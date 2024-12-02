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

int T,N,A;

int from[102][102];
int to[102][102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(x,N+1) FOR(y,N+1) from[x][y]=1<<20;
		from[0][0]=0;
		for(i=1;i<=N;i++) {
			cin>>A;
			A--;
			FOR(x,N+1) FOR(y,N+1) to[x][y]=from[x][y];

			FOR(x,N) for(y=x;y<=N;y++) {
				if(x>=i-1) chmin(to[min(N,max(y,i+A))][min(N,max(y,i+A))],from[x][y]+1);
				if(x>=i-A-1) chmin(to[min(N,max(i,y))][max(i,y)],from[x][y]+1);
				chmin(to[x][min(N,max(y,i+A))],from[x][y]+1);
			}
			
			
			FOR(x,N+1) FOR(y,N+1) from[x][y]=to[x][y];
		}
		cout<<from[N][N]<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
