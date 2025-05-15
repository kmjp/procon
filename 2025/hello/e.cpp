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

int T,N,M;
int Q;
int A[400*400+5],B[400*400+5],W[400*400+5];
int D[404][404];
int ret[404][404][404];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>Q;
		FOR(x,N) FOR(y,N) D[x][y]=(x==y)?0:1000;
		FOR(x,N) FOR(y,N) FOR(k,N+2) ret[x][y][k]=1<<30;
		vector<pair<int,int>> Es;
		FOR(i,M) {
			cin>>A[i]>>B[i]>>W[i];
			A[i]--;
			B[i]--;
			Es.push_back({W[i],i});
			D[A[i]][B[i]]=D[B[i]][A[i]]=1;
		}
		FOR(k,N) FOR(x,N) FOR(y,N) D[x][y]=min(D[x][y],D[x][k]+D[k][y]);
		
		sort(ALL(Es));
		FORR2(a,e,Es) {
			x=A[e],y=B[e];
			if(D[x][y]==0) continue;
			D[x][y]=D[y][x]=0;
			FOR(i,N) FOR(j,N) D[i][j]=min({D[i][j],D[i][x]+D[y][j],D[i][y]+D[x][j]});
			FOR(i,N) FOR(j,N) chmin(ret[i][j][D[i][j]+1],a);
		}
		FOR(x,N) FOR(y,N) FOR(k,N) ret[x][y][k+1]=min(ret[x][y][k+1],ret[x][y][k]);
		while(Q--) {
			cin>>x>>y>>k;
			x--,y--;
			cout<<ret[x][y][k]<<" ";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
