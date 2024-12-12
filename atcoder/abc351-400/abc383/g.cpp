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


int N,K;
int A[202020];
ll B[202020];
ll S[202020];

vector<ll> X[200010][5][5],Y[5][5],Z[5][5];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int num=N/K;
	FOR(i,N) cin>>A[i];
	N-=K-1;
	FOR(i,N) FOR(j,K) B[i]+=A[i+j];
	
	for(i=0;i<N;i+=K) {
		FOR(x,K) FOR(y,K) {
			X[i/K][x][y]={0};
			ll ma=-1LL<<50;
			for(j=x;j+y<K&&i+j<N;j++) ma=max(ma,B[i+j]);
			if(ma!=-1LL<<50) X[i/K][x][y].push_back(ma);
		}
	}
	N=(N+K-1)/K;
	while(N>1) {
		for(i=0;i<N;i+=2) {
			if(i+1==N) {
				FOR(x,K) FOR(y,K) X[i/2][x][y]=X[i][x][y];
				continue;
			}
			FOR(x,K) FOR(y,K) {
				Y[x][y]=X[i][x][y];
				Z[x][y]=X[i+1][x][y];
				X[i/2][x][y].clear();
			}
			FOR(x,K) FOR(y,K) {
				FOR(j,K) {
					k=K-1-j;
					vector<ll> V;
					int a=0,b=0;
					while(a<Y[x][j].size()&&b<Z[k][y].size()) {
						V.push_back(Y[x][j][a]+Z[k][y][b]);
						if(a+1==Y[x][j].size()) b++;
						else if(b+1==Z[k][y].size()) a++;
						else if(Y[x][j][a+1]-Y[x][j][a]>=Z[k][y][b+1]-Z[k][y][b]) a++;
						else b++;
					}
					FOR(r,V.size()) {
						if(r==X[i/2][x][y].size()) X[i/2][x][y].push_back(V[r]);
						chmax(X[i/2][x][y][r],V[r]);
					}
				}
			}
			
		}
		N=(N+1)/2;
	}
	
	FOR(i,num) {
		ll ret=-1LL<<60;
		FOR(x,K) FOR(y,K) if(X[0][x][y].size()>i+1) ret=max(ret,X[0][x][y][i+1]);
		cout<<ret<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
