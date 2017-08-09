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

int N,H,W;
int X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>H;
	FOR(i,N) {
		cin>>x>>y>>r;
		X[max(0,x-r)]++;
		X[min(101000,x+r)]--;
		Y[max(0,y-r)]++;
		Y[min(101000,y+r)]--;
	}
	
	FOR(x,W) {
		if(x) X[x]+=X[x-1];
		if(X[x]==0) break;
	}
	if(x==W) return _P("Yes\n");
	FOR(y,H) {
		if(y) Y[y]+=Y[y-1];
		if(Y[y]==0) break;
	}
	if(y==H) return _P("Yes\n");
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
