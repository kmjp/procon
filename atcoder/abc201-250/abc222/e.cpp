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
int K;
int A[1010];
int U[1010],V[1010],C[1010];
vector<pair<int,int>> E[1010];

int dfs(int cur,int pre,int tar) {
	if(cur==tar) return 1;
	
	FORR2(e,i,E[cur]) if(e!=pre) {
		int ok=dfs(e,cur,tar);
		if(ok) {
			C[i]++;
			return 1;
		}
	}
	
	
	return 0;
	
}

ll from[202020];
ll to[202020];
const ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>A[i];
		A[i]--;
	}
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
	}
	FOR(i,M-1) {
		dfs(A[i],A[i],A[i+1]);
	}
	from[0]=1;
	int sum=0;
	FOR(i,N-1) {
		x=C[i];
		for(j=sum*2;j>=0;j--) {
			(from[j+2*x]+=from[j])%=mo;
		}
		sum+=x;
	}
	cout<<from[sum+K]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
