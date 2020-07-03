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

const int prime_max = 5000001;
int NP,prime[500000],divp[prime_max];
int mask[500000],mm;
void cprime() {
	int i,j;
	for(i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(j=i;j<prime_max;j+=i) divp[j]=i;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	prime[NP++]=0;
	cprime();
	prime[NP++]=5000000;
	
	FOR(i,NP) {
		j=prime[i];
		while(j) mask[i] |= 1<<(j%10), j/=10;
	}
	cin>>i;
	while(i--) cin>>x, mm |= 1<<x;
	if(mm==1023) return _P("4999999\n");

	int ret=-1;
	for(i=1;i<NP;i++) {
		int ma=0;
		FOR(j,NP-i) {
			ma |= mask[i+j];
			if(ma & (~mm)) break;
			if(ma==mm) ret=max(ret,prime[i+j+1]-1-(prime[i-1]+1));
		}
	}
	cout << ret << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
