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

int N,H;
int mo=1000000007;
ll memo[505][505];
ll memo2[505][505];

ll dpdp2(int n,int h);

ll dpdp(int n,int h) {
	if(h==1) return n==1;
	if(h<=0) return 0;
	if(n<h) return 0;
	if(memo[n][h]>=0) return memo[n][h];
	ll ret=0;
	
	int i;
	for(i=h-1;i<=n-1;i++) ret+=2*dpdp(i,h-1)*dpdp2(n-1-i,h-2)%mo;
	for(i=h-1;n-1-i>=h-1;i++) ret+=dpdp(i,h-1)*dpdp(n-1-i,h-1)%mo;
	return memo[n][h]=ret%mo;
}

ll dpdp2(int n,int h) {
	if(n==0) return 1;
	if(n<0 || h<0) return 0;
	if(memo2[n][h]>=0) return memo2[n][h];
	memo2[n][h]=(dpdp(n,h)+dpdp2(n,h-1))%mo;
	return memo2[n][h];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	MINUS(memo);
	MINUS(memo2);
	cout<<dpdp(N,H)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
