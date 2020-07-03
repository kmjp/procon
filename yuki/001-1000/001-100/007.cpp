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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];

int N,win[100010];

void cprime() {
	int i,j;
	for(i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(j=i;j<prime_max;j+=i) divp[j]=i;
	}
}

int winwin(int cur) {
	int i;
	if(win[cur]>=0) return win[cur];
	win[cur] = 0;
	FOR(i,NP) {
		if(cur-prime[i]<0) break;
		if(winwin(cur-prime[i])==0) return win[cur]=1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cprime();
	cin>>N;
	MINUS(win);
	win[0]=win[1]=1;
	if(winwin(N)) _P("Win\n");
	else _P("Lose\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
