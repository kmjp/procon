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

int T,N;
ll A[303030];
vector<int> E[303030];

pair<ll,int> dp1[303030];
pair<ll,int> dp2[303030];

void dfs(int cur,int pre) {
	
	map<int,ll> C;
	int i;
	for(i=1;i<=E[cur].size()+2;i++) C[i]=0;
	ll sum=0;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		sum+=dp1[e].first;
		C[dp1[e].second]+=dp2[e].first-dp1[e].first;
	}
	dp1[cur]={1LL<<60,0};
	dp2[cur]={1LL<<60,0};
	FORR2(a,b,C) {
		pair<ll,int> p={sum+b+1LL*a*A[cur],a};
		if(p<dp1[cur]) {
			dp2[cur]=dp1[cur];
			dp1[cur]=p;
		}
		else if(p<dp2[cur]) {
			dp2[cur]=p;
		}
	}
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		dfs(0,0);
		cout<<dp1[0].first<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
