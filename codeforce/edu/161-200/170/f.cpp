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


int N,Q;
int X[303030],Y[303030];

int retxy[303030],retpm[303030];
set<pair<int,int>> E[303030];
int vis[303030];


int dfs(int cur) {
	if(vis[cur]) return -1;
	vis[cur]=1;
	int oth=-1;
	while(E[cur].size()) {
		auto p=*E[cur].begin();
		int e=p.second;
		E[cur].erase({p.first,e});
		E[p.first].erase({cur,e});
		int ret=dfs(p.first);
		if(ret==-1) {
			if(oth==-1) {
				oth=e;
			}
			else {
				retpm[max(e,oth)]=1;
				retxy[oth]=X[oth]!=cur;
				retxy[e]=X[e]!=cur;
				oth=-1;
			}
		}
		else {
			retpm[max(e,ret)]=1;
			retxy[ret]=X[ret]!=p.first;
			retxy[e]=X[e]!=p.first;
			
		}
		
	}
	return oth;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]--,Y[i]--;
		E[X[i]].insert({Y[i],i});
		E[Y[i]].insert({X[i],i});
	}
	
	FOR(i,N) dfs(i);
	
	FOR(i,Q) {
		if(retxy[i]) cout<<"y";
		else cout<<"x";
		if(retpm[i]) cout<<"-";
		else cout<<"+";
		cout<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
