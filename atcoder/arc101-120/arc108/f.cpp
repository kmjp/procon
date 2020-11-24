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
vector<int> E[402020];
const ll mo=1000000007;
ll p2[505050];
vector<int> D[2];

ll pow2[202020];
ll pow0[202020];
ll dp[202020];

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,404040) p2[i+1]=p2[i]*2%mo;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	x=v1.second;
	y=v2.second;
	
	FOR(i,N) {
		if(i==x||i==y) continue;
		int a=D[0][i];
		int b=D[1][i];
		if(a>b) swap(a,b);
		pow2[b]++;
		pow0[a-1]++;
	}
	
	for(i=N;i>=0;i--) pow0[i]+=pow0[i+1];
	FOR(i,N+1) {
		pow2[i+1]+=pow2[i];
		if(pow0[i]==0) dp[i]=p2[pow2[i]];
	}
	ll ret=0;
	for(i=N;i>=1;i--) {
		(dp[i]+=mo-dp[i-1])%=mo;
		(ret+=i*dp[i])%=mo;
	}
	ret=ret*2%mo;
	(ret+=p2[N-1]*v1.first)%=mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
