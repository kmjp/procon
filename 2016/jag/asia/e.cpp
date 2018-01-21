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


int N;
vector<int> E[101010];
ll V[101010][2];
map<pair<ll,ll>,ll> hashes;
ll mo[2]={1000000007,1000000009};

void dfs(int cur,int pre) {
	V[cur][0]=V[cur][1]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		(V[cur][0]+=V[e][0]*1000001)%=mo[0];
		(V[cur][1]+=V[e][1]*1000003)%=mo[1];
	}
	hashes[{V[cur][0],V[cur][1]}]++;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1);
	
	ll ret=0;
	FORR(r,hashes) ret += r.second*(r.second-1)/2;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
