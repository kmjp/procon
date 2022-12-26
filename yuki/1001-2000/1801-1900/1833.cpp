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

pair<int,int> hoge(int cur,int pre,int v) {
	pair<int,int> p={1<<30,-1};
	FORR2(e,c,E[cur]) if(e!=pre) {
		auto q=hoge(e,cur,v);
		if(q.second>v||c>v) {
			q.first=min(q.first,c);
			q.second=max(q.second,c);
		}
		
		
		if(p.second>v&&q.second>v) {
			return {-1,1<<30};
		}
		else if(q.second>=v) {
			p=q;
		}
	}
	return p;
	
}


int can(int v) {
	int i;
	FOR(i,N) {
		FORR2(e,c,E[i]) if(c>v) {
			pair<int,int> A=hoge(e,i,v);
			pair<int,int> B=hoge(i,e,v);
			
			return (max({c,A.second,B.second})-min({c,A.first,B.first}))<=v;
		}
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
		E[y-1].push_back({x-1,r});
	}
	
	int ret=(1<<30)-1;
	for(i=29;i>=0;i--) if(can(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
