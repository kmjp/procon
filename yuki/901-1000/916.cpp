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

int D,L,R,K,LD,RD;
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>L>>R>>K;
	for(LD=1;LD<=D;LD++) if((1<<(LD-1))<=L && L<1<<LD) break;
	for(RD=1;RD<=D;RD++) if((1<<(RD-1))<=R && R<1<<RD) break;
	ll ret=0;
	for(x=1;x<=D;x++) if(LD+RD-2*x==K) {
		if(LD==x) {
			ret+=(1LL<<(RD-1))%mo;
		}
		else {
			ret+=(1LL<<(x-1))*2*(1LL<<(LD-x-1))%mo*(1LL<<(RD-x-1))%mo;
		}
		
	}
	
	ret%=mo;
	for(x=1;x<=D;x++) {
		int num=(1<<(x-1));
		if(LD==x) num--;
		if(RD==x) num--;
		for(j=1;j<=num;j++) ret=ret*j%mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
