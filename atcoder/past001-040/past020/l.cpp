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
vector<vector<int>> E;

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter() { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

pair<int,ll> dfs(int cur,int pre,int d) {
	int ma=d;
	int cnt=1;
	FORR(e,E[cur]) if(e!=pre) {
		auto p=dfs(e,cur,d+1);
		if(p.first>ma) {
			ma=p.first;
			cnt=p.second;
		}
		else if(p.first==ma) cnt+=p.second;
	}
	return {ma,cnt};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	ll ret=0;
	auto R=diameter();
	if(R.second.size()==1) {
		ll num=0;
		FORR(e,E[R.second[0]]) {
			auto p=dfs(e,R.second[0],1);
			if(p.first==R.first/2) {
				ret+=num*p.second;
				num+=p.second;
			}
		}
	}
	else {
		auto p=dfs(R.second[0],R.second[1],0);
		auto q=dfs(R.second[1],R.second[0],0);
		ret=p.second*q.second;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
