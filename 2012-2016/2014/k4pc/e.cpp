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

ll X;
ll C[1005][1005],S[1005][1005];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X;
	if(X==1) return _P("1 1\n5\n");
	
	FOR(i,100) C[i][0]=S[i][0]=S[0][i]=1;
	for(i=1;i<=100;i++) {
		for(x=1;x<=100;x++) {
			C[i][x]=min(1LL<<60,C[i-1][x]+C[i-1][x-1]);
			S[i][x]=min(1LL<<60,S[i][x-1]+C[i][x]);
		}
	}
	x=0;
	vector<int> V;
	while(1LL<<(x+1)<=X) x++, V.push_back(1);
	X -= 1LL<<x;
	
	for(y=x;y>=0;y--) {
		while(X>=S[x][y]) {
			V.push_back(1000-y);
			X-=S[x][y];
		}
	}
	
	_P("%d %d\n",V.size(),1000);
	ITR(it,V) _P("%d\n",*it);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
