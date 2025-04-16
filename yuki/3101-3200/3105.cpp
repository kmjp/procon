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

const ll mo=998244353;
ll modpow(ll a, ll n,ll mo) {
	ll r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


ll mat[101][101];
ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		if(mat[x][x]==0) {
			for(y=x+1;y<N;y++) if(mat[y][x]) break;
			if(y==N) return 0;
			FOR(z,N) swap(mat[x][z],mat[y][z]);
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x],mo-2,mo);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}

ll matrix_tree(int N,vector<pair<int,int>> E) {
	int x,y;
	FOR(x,N-1) FOR(y,N-1) mat[y][x]=0;
	FORR2(a,b,E) {
		assert(a>=0&&a<N&&b>=0&&b<N);
		mat[a][a]++;
		mat[b][b]++;
		(mat[a][b]+=mo-1)%=mo;
		(mat[b][a]+=mo-1)%=mo;
	}
	return det_mo(N-1);
}

int K;
int N,M;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	ll from[2]={1,0};
	ll to[2];
	FOR(i,K) {
		cin>>N>>M;
		vector<pair<int,int>> E,E2;
		FOR(j,M) {
			cin>>x>>y;
			x=N-x;
			y=N-y;
			E.push_back({x,y});
			if(y==N-1) y=N-2;
			if(x==N-1) x=N-2;
			if(x!=y) E2.push_back({x,y});
			
		}
		ll a=matrix_tree(N,E);
		ll b=matrix_tree(N-1,E2);
		swap(from,to);
		from[0]=to[0]*(2*a+b)%mo;
		from[1]=(to[0]*a+to[1]*(2*a+b))%mo;
	}
	cout<<from[1]<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
