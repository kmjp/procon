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
vector<int> E[202020];

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
	//’¼Œa‚ðŽæ‚éê‡
	R.second.resize(v2.first+1);
	for(int i=N-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first) R.second[D[0][i]]=i;
	return R;
}

int id[202020];
int ma[2][202020];
int mac[2][202020];

int dfs(int cur,int pre,int id) {
	vector<int> cand={0,0};
	FORR(e,E[cur]) if(e!=pre) {
		cand.push_back(dfs(e,cur,id)+1);
		ma[id][cur]=max(ma[id][cur],ma[id][e]);
	}
	sort(ALL(cand));
	reverse(ALL(cand));
	ma[id][cur]=max(ma[id][cur],cand[0]+cand[1]);
	mac[id][cur]=cand[0];
	return cand[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	auto d=diameter();
	MINUS(id);
	FOR(i,d.second.size()) id[d.second[i]]=i;
	dfs(d.second[0],d.second[0],0);
	dfs(d.second.back(),d.second.back(),1);
	
	int mi=d.first;
	FOR(i,d.second.size()-1) {
		x=ma[1][d.second[i]];
		y=ma[0][d.second[i+1]];
		k=max({1+(x+1)/2+(y+1)/2,x,y});
		mi=min(mi,k);
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
