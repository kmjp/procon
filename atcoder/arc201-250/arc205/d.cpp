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
vector<int> E[505050];

pair<int,int> dfs(int cur) {
	
	if(E[cur].size()==0) {
		return {1,0};
	}

	vector<pair<int,int>> V;
	FORR(e,E[cur]) {
		V.push_back(dfs(e));
	}
	sort(ALL(V));
	reverse(ALL(V));
	
	int cand=0;
	int pa=0;
	int i;
	for(i=1;i<V.size();i++) {
		cand+=V[i].first;
		pa+=V[i].second;
	}
	V[0].second+=pa;
	if(cand>=V[0].first) {
		V[0].second+=(cand+V[0].first)/2;
		V[0].first=(cand+V[0].first)%2;
	}
	else {
		V[0].first-=cand;
		V[0].second+=cand;
		int x=min(V[0].first/2,pa);
		V[0].second+=x;
		V[0].first-=x*2;
	}
	V[0].first++;
	return V[0];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		for(i=1;i<N;i++) {
			cin>>x;
			E[x-1].push_back(i);
		}
		auto p=dfs(0);
		cout<<p.second<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
