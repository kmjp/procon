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

int N;
int co[10001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,10001) co[i]=10000000;
	queue<int> Q;
	co[1]=1;
	Q.push(1);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		y=__builtin_popcount(x);
		if(x-y>=1 && co[x-y]>co[x]+1) {
			co[x-y]=co[x]+1;
			Q.push(x-y);
		}
		if(x+y<=N && co[x+y]>co[x]+1) {
			co[x+y]=co[x]+1;
			Q.push(x+y);
		}
	}
	if(co[N]==10000000) _P("-1\n");
	else _P("%d\n",co[N]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
