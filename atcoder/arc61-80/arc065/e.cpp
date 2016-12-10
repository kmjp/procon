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

int N,A,B;
ll X[101010],Y[101010],T;
map<ll,vector<pair<ll,int>>> U,D;
map<ll,set<pair<ll,int>>> US,DS;
ll ret;

void dfs(int cur) {
	ll UD=Y[cur]-X[cur];
	ll DD=Y[cur]+X[cur];
	
	US[UD].erase({X[cur],cur});
	DS[DD].erase({X[cur],cur});
	
	ret += lower_bound(ALL(U[UD+T]),make_pair(X[cur],0))  -lower_bound(ALL(U[UD+T]),make_pair(X[cur]-T,0));
	ret += lower_bound(ALL(D[DD+T]),make_pair(X[cur]+T+1,0))-lower_bound(ALL(D[DD+T]),make_pair(X[cur],0));
	ret += lower_bound(ALL(U[UD-T]),make_pair(X[cur]+T,0))-lower_bound(ALL(U[UD-T]),make_pair(X[cur],0));
	ret += lower_bound(ALL(D[DD-T]),make_pair(X[cur],0))  -lower_bound(ALL(D[DD-T]),make_pair(X[cur]-T+1,0));
	
	while(1) {
		auto it=US[UD+T].lower_bound({X[cur]-T,0});
		if(it==US[UD+T].end() || it->first>X[cur]) break;
		dfs(it->second);
	}
	while(1) {
		auto it=US[UD-T].lower_bound({X[cur],0});
		if(it==US[UD-T].end() || it->first>X[cur]+T) break;
		dfs(it->second);
	}
	while(1) {
		auto it=DS[DD+T].lower_bound({X[cur],0});
		if(it==DS[DD+T].end() || it->first>X[cur]+T) break;
		dfs(it->second);
	}
	while(1) {
		auto it=DS[DD-T].lower_bound({X[cur]-T,0});
		if(it==DS[DD-T].end() || it->first>X[cur]) break;
		dfs(it->second);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	A--,B--;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		U[Y[i]-X[i]].push_back({X[i],i});
		D[X[i]+Y[i]].push_back({X[i],i});
		US[Y[i]-X[i]].insert({X[i],i});
		DS[X[i]+Y[i]].insert({X[i],i});
	}
	
	T=abs(X[A]-X[B])+abs(Y[A]-Y[B]);
	
	FORR(r,U) sort(ALL(r.second));
	FORR(r,D) sort(ALL(r.second));
	
	dfs(A);
	cout<<ret/2<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
