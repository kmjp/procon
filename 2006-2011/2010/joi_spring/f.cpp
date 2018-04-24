#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int>> E[303030];
int num=0;

int dfs(int cur,int pre,int m) {
	vector<int> V;
	V.push_back(0);
	FORR(e,E[cur]) if(e.first!=pre) {
		V.push_back(e.second + dfs(e.first,cur,m));
	}
	sort(ALL(V));
	while(V.size()>=2 && V[V.size()-1]+V[V.size()-2]>m) {
		num++;
		V.pop_back();
	}
	return V.back();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y>>k;
		E[x-1].push_back({y-1,k});
		E[y-1].push_back({x-1,k});
	}
	
	int L=0,R=1<<30;
	while(L+1<R) {
		int m=(L+R)/2;
		num=0;
		dfs(0,-1,m);
		if(num<M) R=m;
		else L=m;
	}
	
	
	
	cout<<R<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
