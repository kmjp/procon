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
vector<int> E[202020];
map<pair<int,int>,int> M;
int ng;
vector<int> Es;

int dfs(int cur,int pre) {
	vector<int> num[3];
	FORR(e,E[cur]) if(e!=pre) {
		int x=dfs(e,cur);
		if(x==0) Es.push_back(M[{cur,e}]);
		num[x].push_back(e);
	}
	
	if(num[2].size()>1) {
		ng=1;
		return 0;
	}
	if(num[2].size()==1) {
		if(num[1].size()) ng=1;
		return 0;
	}
	if(num[1].size()>2) {
		ng=1;
		return 0;
	}
	if(num[1].size()==2) {
		return 0;
	}
	if(num[1].size()==1) {
		return 2;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			M[{x-1,y-1}]=i+1;
			M[{y-1,x-1}]=i+1;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		ng=0;
		Es.clear();
		x=dfs(0,0);
		if(x!=0) ng=1;
		if(ng) {
			cout<<-1<<endl;
		}
		else {
			cout<<Es.size()<<endl;
			FORR(e,Es) cout<<e<<" ";
			cout<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
