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

int T;
int N;
vector<int> E[5050];
const int DI=72;
int D[50505];
vector<int> cand;

int ask(int v) {
	cout<<"? "<<v<<endl;
	cin>>v;
	return v;
}

int dfs1(int cur,int pre) {
	D[cur]=0;
	FORR(e,E[cur]) if(e!=pre) D[cur]=max(D[cur],dfs1(e,cur)+1);
	return D[cur];
}
void dfs2(int cur,int pre) {
	cand.push_back(cur);
	int tar=-1;
	FORR(e,E[cur]) if(e!=pre && D[e]>=DI) tar=e;
	FORR(e,E[cur]) if(e!=pre && D[e]>=DI && (e==tar||ask(e))) dfs2(e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		int leaf;
		for(i=2;i<=N;i++) if(E[i].size()==1) leaf=i;
		x=0;
		FOR(i,DI) x|=ask(leaf);
		if(x) {
			cout<<"! "<<leaf<<endl;
			continue;
		}
		dfs1(1,1);
		cand.clear();
		dfs2(1,1);
		int L=0,R=cand.size()-1;
		while(L<R) {
			int M=(L+R+1)/2;
			if(ask(cand[M])) {
				L=M;
			}
			else {
				L=max(L-1,0);
				R=max(M-2,0);
			}
		}
		cout<<"! "<<cand[L]<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
