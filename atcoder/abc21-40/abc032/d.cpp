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

int N,MW;
ll V[2020],W[2020];
ll dp[2000002];

void go1() {
	int i,j,k,x,y,mask;
	vector<pair<ll,ll>> V1,V2;
	
	int a=min(N,15);
	FOR(mask,1<<a) {
		ll tv=0,tw=0;
		FOR(i,a) if(mask&(1<<i)) tv+=V[i], tw+=W[i];
		if(tw<=MW) V1.push_back({tw,tv});
	}
	a=max(0,N-15);
	FOR(mask,1<<a) {
		ll tv=0,tw=0;
		FOR(i,a) if(mask&(1<<i)) tv+=V[i+15], tw+=W[i+15];
		if(tw<=MW) V2.push_back({tw,tv});
	}
	sort(ALL(V1));
	sort(ALL(V2));
	
	FOR(i,V1.size()-1) V1[i+1].second=max(V1[i].second,V1[i+1].second);
	FOR(i,V2.size()-1) V2[i+1].second=max(V2[i].second,V2[i+1].second);
	ll ma=0;
	y=V2.size()-1;
	FOR(x,V1.size()) {
		while(y>=0 && V1[x].first+V2[y].first>MW) y--;
		ma=max(ma,V1[x].second+V2[y].second);
	}
	cout<<ma<<endl;
}
void go2() {
	int i,x;
	FOR(i,N) {
		for(x=200001-W[i];x>=0;x--) {
			dp[x+W[i]]=max(dp[x+W[i]],dp[x]+V[i]);
		}
	}
	cout<<*max_element(dp,dp+MW+1)<<endl;
}

void go3() {
	int i,x;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	FOR(i,N) {
		for(x=200001-V[i];x>=0;x--) if(dp[x]<=MW) {
			dp[x+V[i]]=min(dp[x+V[i]],dp[x]+W[i]);
		}
	}
	
	for(i=200000;i>=0;i--) if(dp[i]<=MW) return _P("%lld\n",i);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll mv=0,mw=0;
	
	cin>>N>>MW;
	FOR(i,N) cin>>V[i]>>W[i], mw=max(mw,W[i]),mv=max(mv,V[i]);
	
	if(N<=30) go1();
	else if(mw<=1000) go2();
	else if(mv<=1000) go3();
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
