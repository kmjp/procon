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

int N;
ll A[555][555];

map<ll,vector<int>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	
	if(N<=3) {
		vector<int> V;
		FOR(i,N*N) V.push_back(i);
		do {
			int vis[N*N]={};
			int par=0;
			FOR(i,N*N) if(vis[i]==0) {
				x=i;
				while(vis[x]==0) {
					par^=1;
					vis[x]=1;
					x=V[x];
				}
				par^=1;
			}
			FOR(i,N*N) if(V[i]==0) {
				par^=(i%N)%2;
				par^=(i/N)%2;
			}
			if(par==0) {
				ll ret=0;
				FOR(i,N*N) ret+=V[i]*A[i/N][i%N];
				if(M.count(ret)) {
					cout<<"Yes"<<endl;
					FOR(y,N) {
						FOR(x,N) cout<<V[y*N+x]<<" ";
						cout<<endl;
					}
					V=M[ret];
					FOR(y,N) {
						FOR(x,N) cout<<V[y*N+x]<<" ";
						cout<<endl;
					}
					return;
				}
				M[ret]=V;
			}
		} while(next_permutation(ALL(V)));
		cout<<"No"<<endl;
	}
	else {
		vector<int> V,P;
		FOR(i,4*4) {
			V.push_back(i);
			P.push_back(i/4*N+i%4);
		}
		do {
			int vis[4*4]={};
			int par=0;
			FOR(i,4*4) if(vis[i]==0) {
				x=i;
				while(vis[x]==0) {
					par^=1;
					vis[x]=1;
					x=V[x];
				}
				par^=1;
			}
			FOR(i,4*4) if(V[i]==0) {
				par^=(i%4)%2;
				par^=(i/4)%2;
			}
			if(par==0) {
				ll ret=0;
				FOR(i,4*4) ret+=P[i]*A[i/4][i%4];
				if(M.count(ret)) {
					FOR(y,N) FOR(x,N) A[y][x]=y*N+x;
					cout<<"Yes"<<endl;
					FOR(y,4) FOR(x,4) A[y][x]=P[y*4+x];
					FOR(y,N) {
						FOR(x,N) cout<<A[y][x]<<" ";
						cout<<endl;
					}
					FOR(y,4) FOR(x,4) A[y][x]=M[ret][y*4+x];
					FOR(y,N) {
						FOR(x,N) cout<<A[y][x]<<" ";
						cout<<endl;
					}
					return;
				}
				M[ret]=P;
			}
			next_permutation(ALL(P));
		} while(next_permutation(ALL(V)));
		cout<<"No"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
