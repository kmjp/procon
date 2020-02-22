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

int N,C;
int L[10];
int D[10];

double dp[303][32];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) cin>>L[i], D[i]=i;
	sort(L,L+N);
	
	double ret=0;
	do {
		ZERO(dp);
		dp[N*L[N-1]][0]=1;
		FOR(i,N*C) if(i%N) {
			x=D[(i-1)%N];
			for(int mask=0;mask<1<<(N-1);mask++) if((mask&(1<<x))==0) {
				for(y=i;y<=N*C;y++) {
					dp[min(N*C,max(y,i+L[x]*N))][mask ^ (1<<x)] += dp[y][mask];
				}
			}
		}
		
		ret += dp[N*C][(1<<(N-1))-1] ;
	} while(next_permutation(D,D+(N-1)));
	
	FOR(i,N-1) ret/=i+1;
	_P("%.12lf\n",ret/pow(C,N-1));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
