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
int ret[202020];
int vis[202020];
vector<int> C;

int dfs(int cur) {
	/*
	cout<<cur<<" ";
	FORR(c,C) cout<<c;
	cout<<" ";
	cout<<E[0].size()<<E[1].size()<<E[2].size()<<endl;
	*/
	if(ret[cur]>=0) return ret[cur];
	if(E[cur].empty()) return ret[cur]=cur;
	if(vis[cur]) {
		while(C.back()!=cur) {
			E[C.back()].pop_back();
			vis[C.back()]=0;
			C.pop_back();
		}
		E[cur].pop_back();
		vis[cur]=0;
		C.pop_back();
		return dfs(cur);
	}
	vis[cur]=1;
	C.push_back(cur);
	return dfs(E[cur].back());
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		E[i].resize(x);
		FORR(e,E[i]) {
			cin>>e;
			e--;
		}
	}
	MINUS(ret);
	FOR(i,N) {
		C.clear();
		int tar=dfs(i);
		FORR(c,C) ret[c]=tar;
		cout<<ret[i]+1<<" ";
	}
	cout<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
