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

int N,M;
ll mo;
ll dp[303][303];
ll dps[303][303];

ll dpdp(int num,int d);
ll dpdps(int num,int d) {
	if(d<0) return 0;
	if(dps[num][d]>=0) return dps[num][d];
	return dps[num][d] = (dpdps(num,d-1) + dpdp(num,d))%mo;
}

ll dpdp(int num,int d) {
	if(num<d) return 0;
	if(dp[num][d]>=0) return dp[num][d];
	if(d==0) {
		return num==1;
	}
	
	ll ret=dpdp(num-1,d-1);
	int k,j;
	for(k=1;k<=num-2;k++) {
		ret += dpdp(k,d-1) * dpdps(num-k,min(d,M-d)) % mo;
		ret += dpdps(k,min(d-2,M-d-1)) * dpdp(num-k,d) % mo;
	}
	return dp[num][d]=ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>mo;
	MINUS(dp);
	MINUS(dps);
	
	ll ret=0;
	for(i=0;i<=M;i++) ret+=dpdp(N,i);
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
