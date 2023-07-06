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

int N,M;
vector<int> E[404040][2];
int vis[404040][2];
ll A[303030];

int id[603030];
set<int> C[603030];
ll D[603030];
ll G;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1][0].push_back(y-1);
		E[y-1][1].push_back(x-1);
	}
	FOR(i,N) cin>>A[i];
	
	vis[0][0]=1;
	FOR(i,N) FORR(e,E[i][0]) vis[e][0]|=vis[i][0];
	vis[N-1][1]=1;
	for(i=N-1;i>=0;i--) FORR(e,E[i][1]) vis[e][1]|=vis[i][1];
	
	FOR(i,N) {
		
		if(A[i]==-1) {
			id[i*2]=i*2;
			id[i*2+1]=i*2+1;
			C[i*2]={i*2};
			C[i*2+1]={i*2+1};
		}
		else {
			id[i*2]=id[i*2+1]=i*2;
			C[i*2]={i*2,i*2+1};
			D[i*2+1]=A[i];
		}
	}
	FOR(i,N) if(vis[i][0]&&vis[i][1]) {
		FORR(e,E[i][0]) if(vis[e][0]&&vis[e][1]) {
			if(id[i*2+1]!=id[2*e]) {
				x=id[i*2+1];
				y=id[2*e];
				ll dif=D[i*2+1]-D[2*e];
				if(C[x].size()<C[y].size()) swap(x,y), dif=-dif;
				FORR(v,C[y]) {
					C[x].insert(v);
					id[v]=x;
					D[v]+=dif;
				}
				
			}
			else {
				G=__gcd(G,abs(D[2*e]-D[i*2+1]));
			}
			
		}
	}
	
	if(id[0]==id[2*N-1]) {
		G=__gcd(G,abs(D[0]-D[2*N-1]));
	}
	
	if(G==0) G=-1;
	cout<<G<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
