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
int A[101010];
int D[101010];
int C[101010];
vector<int> E[101010];
const ll mo=998244353;

ll dp1[101010][2];
ll dp2[101010][2];


ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void dfs(int cur,int pre,int sc) {
	ll a[2]={},b[2]={};
	a[C[cur]>sc]=b[C[cur]>sc]=1;
	int i,j;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,sc);
		ll na[2]={},nb[2]={};
		// not connect
		FOR(i,2) {
			na[i]+=a[i]*(dp1[e][0]+dp1[e][1]);
			nb[i]+=b[i]*(dp1[e][0]+dp1[e][1]);
		}
		// connect
		FOR(i,2) FOR(j,2) {
			na[max(i,j)]+=a[i]*dp1[e][j];
			nb[max(i,j)]+=b[i]*dp1[e][j]+a[i]*dp2[e][j];
		}
		
		FOR(i,2) {
			a[i]=na[i]%mo;
			b[i]=nb[i]%mo;
		}
	}
	FOR(i,2) {
		dp1[cur][i]=a[i];
		dp2[cur][i]=b[i];
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> V;
	FOR(i,N) {
		cin>>A[i];
		V.push_back({A[i],i});
	}
	sort(ALL(V));
	FOR(i,V.size()) C[V[i].second]=i;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	ll ret=0;
	FOR(i,N) {
		dfs(i,i,C[i]);
		ret+=A[i]*dp2[i][0]%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
