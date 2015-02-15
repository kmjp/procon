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

ll memo[1000051][10];
ll mo=1000000009;
int T;
ll M;

ll dpdp(int V,int D) {
	int i;
	if(V<0) return 0;
	if(V==0) return 1;
	if(D==0) return 1;
	if(memo[V][D]>=0) return memo[V][D];
	
	memo[V][D]=0;
	for(i=1;i<=D;i++) memo[V][D]+=dpdp(V-i,i);
	memo[V][D]+=dpdp(V-1,0);
	return memo[V][D]%=mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>T;
	while(T--) {
		cin>>M;
		cout << dpdp(M/111111,9) << endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
