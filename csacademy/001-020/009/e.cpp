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
ll mo=1000000007;

ll from[10101];
ll fromS[10101];

void add(ll& a,ll b) {
	a+=b;
	if(a>=mo) a-=mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	N-=K;
	from[0]=1;
	fromS[0]=0;
	
	for(i=1;i<=K;i++) {
		for(j=0;j+i<=N;j++) if(j+i<=N) {
			add(from[j+i],from[j]);
			add(fromS[j+i],(fromS[j]+from[j]*(2*j+i))%mo);
		}
	}
	cout<<(fromS[N]+from[N]*(2*N+K))%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
