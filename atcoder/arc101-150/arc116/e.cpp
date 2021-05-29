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

int N,K,V;
vector<int> E[202020];

int need[202020],aff[202020];
int num;

void dfs(int cur,int pre) {
	need[cur]=0;
	aff[cur]=-1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		if(aff[e]>=0) aff[cur]=max(aff[cur],aff[e]-1);
		if(need[e]>=0) need[cur]=max(need[cur],need[e]+1);
	}
	
	if(aff[cur]>=need[cur]) {
		need[cur]=-1;
	}
	else {
		if(need[cur]>=V) {
			need[cur]=-1;
			aff[cur]=V;
			num++;
		}
		else {
			aff[cur]=-1;
		}
	}
	
	

}


int ok(int v) {
	if(v<=0) return 0;
	
	V=v;
	num=0;
	dfs(0,0);
	if(need[0]>=0) num++;
	return num<=K;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	int ret=N;
	for(j=20;j>=0;j--) if(ok(ret-(1<<j))) ret-=1<<j;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
