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

int N,M,K;
ll mo=1000000007;

ll sp[4098][4098];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	sp[0][0]=sp[1][1]=1;
	for(x=1;x<=4096;x++) {
		for(y=1;y<=4096;y++) if(sp[x][y]) {
			if(y+x<=4096) {
				sp[x][y+x]+=sp[x][y];
				if(sp[x][y+x]>=mo) sp[x][y+x]-=mo;
			}
			if(y+1<=4096) {
				sp[x+1][y+1]+=sp[x][y];
				if(sp[x+1][y+1]>=mo) sp[x+1][y+1]-=mo;
			}
		}
	}
	
	cin>>N>>K>>M;
	
	ll ret=0;
	for(i=1;i<=N;i++) {
		ll v=1;
		FOR(j,M) v=v*i%mo;
		for(j=1;j<=K && i*j<=N;j++) {
			ll pat = sp[K-j][N-i*j];
			if(j+1<=K && i*(j+1)<=N) pat += mo- sp[K-(j+1)][N-i*(j+1)];
			(ret += v*j%mo*pat)%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
