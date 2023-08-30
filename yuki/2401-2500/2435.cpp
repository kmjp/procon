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
vector<pair<int,int>> E[5];
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) {
		cin>>x;
		FOR(j,x) {
			cin>>y>>k;
			E[i].push_back({y-1,k-1});
		}
	}
	int mask;
	ll ret=0;
	FOR(mask,1<<K) if(mask) {
		ZERO(mat);
		FOR(i,K) if(mask&(1<<i)) {
			FORR2(a,b,E[i]) {
				mat[a][a]++;
				mat[b][b]++;
				(mat[a][b]+=mo-1)%=mo;
				(mat[b][a]+=mo-1)%=mo;
			}
		}
		ll a=det_mo(N-1);
		if(K%2==__builtin_popcount(mask)%2) {
			ret+=a;
		}
		else {
			ret+=mo-a;
		}
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
