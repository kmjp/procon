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

int N,L;
int S[100];
int sum;
double fact[100];

ll dp[22005][53];
ll dp2[22005][53];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=fact[1]=1;
	for(i=2;i<=80;i++) fact[i]=fact[i-1]*i;
	
	scanf("%d%d",&N,&L);
	L*=60;
	FOR(i,N) {
		scanf("%d:%d",&x,&y);
		S[i]=x*60+y;
		sum+=S[i];
	}
	if(L>=sum) return _P("%d\n",N);
	
	dp[0][0]=1;
	FOR(i,N) {
		for(x=i;x>=0;x--) {
			FOR(y,22001) dp[min(22000,y+S[i])][x+1] += dp[y][x];
		}
	}
	
	double ret=0;
	FOR(i,N) {
		for(x=0;x<=N;x++) {
			for(y=0;y<=L+S[i]-1;y++) {
				dp2[y][x]=dp[y][x];
				if(y>=S[i] && x>0) dp2[y][x]-=dp2[y-S[i]][x-1];
				if(x<N && y<L) ret += dp2[y][x] * (fact[x] * fact[N-(x+1)]);
			}
		}
	}
	
	ret /= fact[N];
	_P("%.12lf\n",ret);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
