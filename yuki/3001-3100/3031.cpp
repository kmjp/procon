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

int M;
ll A[101010],B[101010],C[101010];
int D[101010];

map<ll,vector<pair<int,int>>> V;

void dfs(int p,int dir) {
	
	if(D[p]!=-1) {
		if(D[p]!=dir) {
			cout<<"NO"<<endl;
			exit(0);
		}
		return;
	}
	D[p]=dir;
	
	vector<ll> X={((A[p]<<30)+B[p]),((B[p]<<30)+C[p]),((C[p]<<30)+A[p])};
	vector<ll> Y={((A[p]<<30)+C[p]),((C[p]<<30)+B[p]),((B[p]<<30)+A[p])};
	
	FORR(a,X) {
		if(V[a].size()>2) {
			cout<<"NO"<<endl;
			exit(0);
		}
		FORR2(v,d,V[a]) if(v!=p) dfs(v,dir^1^d);
	}
	FORR(a,Y) {
		if(V[a].size()>2) {
			cout<<"NO"<<endl;
			exit(0);
		}
		FORR2(v,d,V[a]) if(v!=p) dfs(v,dir^0^d);
	}
	
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		V[(A[i]<<30)+B[i]].push_back({i,0});
		V[(B[i]<<30)+C[i]].push_back({i,0});
		V[(C[i]<<30)+A[i]].push_back({i,0});
		V[(A[i]<<30)+C[i]].push_back({i,1});
		V[(C[i]<<30)+B[i]].push_back({i,1});
		V[(B[i]<<30)+A[i]].push_back({i,1});
	}
	MINUS(D);
	FOR(i,M) if(D[i]==-1) dfs(i,0);
	cout<<"YES"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
