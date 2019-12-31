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

int N,X;
int T[101010];
vector<int> B[2+(1<<17)];

int ok(int v) {
	ll V=X;
	multiset<int> M;
	for(int i=100000;i>=1;i--) {
		FORR(r,B[i]) M.insert(-r);
		if(i<=v && M.size()) {
			V+=*M.begin();
			M.erase(M.begin());
		}
	}
	return V<=0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>x, B[T[i]].push_back(x);
	
	if(!ok((1<<17))) return _P("-1\n");
	int ret=1<<17;
	for(i=16;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	_P("%d\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
