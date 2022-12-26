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
map<int,vector<int>> G;
map<int,int> ma;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	priority_queue<pair<int,int>> P;
	FOR(i,M) {
		cin>>x>>y;
		G[y].push_back(x);
		ma[y]=y;
		ma[x]=x;
		P.push({y,y});
	}
	while(P.size()) {
		int v=P.top().first;
		int cur=P.top().second;
		P.pop();
		if(ma[cur]!=v) continue;
		
		FORR(e,G[cur]) if(ma[e]<v) {
			ma[e]=v;
			P.push({v,e});
		}
		
	}
	
	
	
	
	ll ret=1LL*N*(N+1)/2;
	FORR(m,ma) ret+=m.second-m.first;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
