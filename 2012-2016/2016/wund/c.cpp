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
pair<ll,ll> V[101010];
map<pair<ll,ll>,int> MP;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i].first>>V[i].second,MP[V[i]]=i+1;
	sort(V,V+N);
	FOR(i,N) {
		if((V[i+2].first-V[i].first)*(V[i+1].second-V[i].second)
		 != (V[i+1].first-V[i].first)*(V[i+2].second-V[i].second))
		 	return _P("%d %d %d\n",MP[V[i]],MP[V[i+1]],MP[V[i+2]]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
