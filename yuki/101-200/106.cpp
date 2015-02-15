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

int K,N;
const int prime_max = 2200000;
int divp[prime_max];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int ret=0;
	for(int i=2;i<=N;i++) {
		if(divp[i]==0) {
			for(int j=i;j<prime_max;j+=i) divp[j]++;
		}
		if(divp[i]>=K) ret++;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
