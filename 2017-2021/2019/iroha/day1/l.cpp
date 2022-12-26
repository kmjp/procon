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

int N;
ll K;
ll A[101010];
int nex[202020][60];

ll num(ll v) {
	ll ret=0;
	int i,j;
	FOR(i,N) {
		int cur=i;
		int mi=N;
		for(j=59;j>=0;j--) {
			if(v&(1LL<<j)) {
				cur=max(cur,nex[i][j]);
			}
			else {
				mi=min(mi,max(nex[i][j],cur));
			}
		}
		ret+=(N-min(mi,cur));
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	
	FOR(i,60) nex[N][i]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,60) {
			nex[i][j]=nex[i+1][j];
			if(A[i]&(1LL<<j)) nex[i][j]=i;
		}
	}
	
	ll ret=(1LL<<60)-1;
	if(num(ret)>=K) {
		cout<<ret<<endl;
		return;
	}
	
	for(i=59;i>=0;i--) if(num(ret^(1LL<<i))<K) ret-=1LL<<i;
	
	cout<<ret-1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
