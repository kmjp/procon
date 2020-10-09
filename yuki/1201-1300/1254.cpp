#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
set<pair<int,int>> E[303030];
int need[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		E[x-1].insert({y-1,i});
		E[y-1].insert({x-1,i});
	}
	queue<int> Q;
	FOR(i,N) if(E[i].size()==1) Q.push(i);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		y=E[x].begin()->first;
		i=E[x].begin()->second;
		need[i]=1;
		E[x].clear();
		E[y].erase({x,i});
		if(E[y].size()==1) Q.push(y);
	}
	
	cout<<count(need,need+N,0)<<endl;
	FOR(i,N) if(need[i]==0) cout<<(i+1)<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
