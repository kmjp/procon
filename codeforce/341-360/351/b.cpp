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

int N,K;
int A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>A>>B>>C>>D;
	vector<int> V;
	for(i=1;i<=N;i++) {
		if(i==A) continue;
		if(i==B) continue;
		if(i==C) continue;
		if(i==D) continue;
		V.push_back(i);
	}
	if(N==4) return _P("-1\n");
	vector<pair<int,int>> R;
	R.push_back({A,D});
	R.push_back({B,C});
	FOR(i,V.size()-1) R.push_back({V[i],V[i+1]});
	R.push_back({A,V.back()});
	R.push_back({D,V.back()});
	R.push_back({B,V[0]});
	R.push_back({C,V[0]});
	if(R.size()>K) return _P("-1\n");
	_P("%d ",A);
	_P("%d ",D);
	FOR(i,V.size()) _P("%d ",V[V.size()-1-i]);
	_P("%d %d\n",C,B);
	_P("%d ",C);
	_P("%d ",B);
	FOR(i,V.size()) _P("%d ",V[i]);
	_P("%d %d\n",A,D);
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
