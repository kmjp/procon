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

int T,N,P[202020];
vector<int> E[202020];
int C[202020];
int ret;

pair<int,int> dfs(int cur) {
	int num=0;
	int iso=0,pa=0;
	
	FORR(e,E[cur]) {
		auto p=dfs(e);
		int niso=abs(iso-p.first);
		int npa=pa+p.second+min(iso,p.first);
		if(iso>p.first) {
			int add=min((iso-p.first)/2,p.second);
			niso-=add*2;
			npa+=add;
		}
		else if(p.first>iso) {
			int add=min((p.first-iso)/2,pa);
			niso-=add*2;
			npa+=add;
		}
		iso=niso;
		pa=npa;
	}
	return {iso+1,pa};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		for(i=1;i<N;i++) {
			cin>>P[i];
			P[i]--;
			E[P[i]].push_back(i);
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
