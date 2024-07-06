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
vector<pair<int,int>> E[202020];

pair<ll,int> farthest(int cur,int pre,ll d,vector<ll>& D) {
	D[cur]=d;
	pair<ll,int> r={d,cur};
	FORR2(e,c,E[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+c,D));
	return r;
}

pair<ll,vector<int>> diameter() { // diameter,center
	vector<ll> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(0,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	v1=farthest(v2.second,v2.second,0,D[1]);
	pair<ll,vector<int>> R;
	R.first = v2.first;
	//—¼’[‚¾‚¯
	R.second={v1.second,v2.second};
	/*
	//’¼Œa‚ðŽæ‚éê‡
	R.second.resize(v2.first+1);
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first) R[D[0][i]]=i;
	*/

	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll sum=0;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
		sum+=2*k;
	}
	auto p=diameter();
	cout<<sum-p.first<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
