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
vector<pair<int,int>> E[1010];
ll from[1010];
ll to[1010];
ll res[5030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x-1].push_back({y-1,r});
	}
	FOR(i,N) from[i]=-1LL<<60;
	from[0]=0;
	memmove(to,from,sizeof(from));
	FOR(i,5020) {
		FOR(x,N) FORR(r,E[x]) to[r.first]=max(to[r.first],to[x]+r.second);
		res[i]=to[N-1];
		memmove(from,to,sizeof(to));
	}
	
	if(res[4000]<res[5000]) cout<<"inf"<<endl;
	else cout<<res[5000]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
