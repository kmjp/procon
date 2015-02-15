#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

map<pair<ll,ll>,int > M;
int N;
ll X[1010],Y[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		M[make_pair(X[i],Y[i])]=i;
	}
	
	FOR(x,N) FOR(y,N) if(x!=y) {
		ll x2,y2,x3,y3;
		x2=X[y]+(Y[y]-Y[x]);
		y2=Y[y]-(X[y]-X[x]);
		x3=X[x]+(Y[y]-Y[x]);
		y3=Y[x]-(X[y]-X[x]);
		if(M.count(make_pair(x2,y2)) && M.count(make_pair(x3,y3))) {
			vector<int> V;
			V.push_back(x+1);
			V.push_back(y+1);
			V.push_back(M[make_pair(x2,y2)]+1);
			V.push_back(M[make_pair(x3,y3)]+1);
			sort(ALL(V));
			_P("4\n");
			FOR(i,4) _P("%d\n",V[i]);
			return;
		}
	}
	_P("0\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
