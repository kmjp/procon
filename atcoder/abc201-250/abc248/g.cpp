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
int U[101010],V[101010];
vector<int> E[101010];
vector<int> D[101010];
vector<int> cand[101010];

const ll mo=998244353;
ll num[101010];
int vis[202020];

int dfs(int cur,int id) {
	if(vis[cur]==id) return 0;
	vis[cur]=id;
	int v=1;
	FORR(e,E[cur]) v+=dfs(e,id);
	return v;
}

int dfs2(int cur,int pre,int n) {
	int v=0;
	FORR(e,E[cur]) if(e!=pre) {
		int a=dfs2(e,cur,n);
		v+=a;
		(num[vis[cur]]+=1LL*a*(n-v))%=mo;
	}
	v++;
	(num[vis[cur]]+=1LL*(n-v))%=mo;
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) {
		for(j=i;j<=100000;j+=i) D[j].push_back(i);
	}
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		U[i]=x;
		V[i]=y;
		int g=__gcd(A[x],A[y]);
		FORR(v,D[g]) cand[v].push_back(i);
	}
	
	for(i=1;i<=100000;i++) {
		vector<int> C;
		FORR(e,cand[i]) {
			E[U[e]].push_back(V[e]);
			E[V[e]].push_back(U[e]);
			C.push_back(U[e]);
			C.push_back(V[e]);
		}
		FORR(c,C) if(vis[c]!=i) {
			x=dfs(c,i);
			dfs2(c,c,x);
		}
		FORR(e,cand[i]) {
			E[U[e]].clear();
			E[V[e]].clear();
		}
	}
	ll ret=0;
	for(i=100000;i>=1;i--) {
		for(j=2*i;j<=100000;j+=i) num[i]-=num[j];
		num[i]=(num[i]%mo+mo)%mo;
		ret+=num[i]*i%mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
