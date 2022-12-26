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
ll T;
vector<pair<ll,ll>> A;
vector<ll> B;

ll dp[202020];

bool comp(pair<ll,ll>& L,pair<ll,ll>& R) {
	return (R.first+1)*(L.second+1)+R.second<(L.first+1)*(R.second+1)+L.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>x>>y;
		if(x>0) A.push_back({x,y});
		else B.push_back(y);
	}
	
	FOR(i,N+1) dp[i]=1LL<<60;
	dp[0]=0;
	
	sort(ALL(A),comp);
	FORR(v,A) {
		ll a=v.first;
		ll b=v.second;
		for(i=40;i>=0;i--) if(dp[i]<T) {
			ll nex=(dp[i]+1)+(dp[i]+1)*a+b;
			dp[i+1]=min(dp[i+1],nex);
		}
	}
	
	sort(ALL(B));

	vector<ll> sum;
	sum.push_back(0);
	FORR(b,B) sum.push_back(sum.back()+1+b);
	int ma=0;
	for(i=N;i>=0;i--) if(dp[i]<=T) {
		ma=max(ma,i);
		x=lower_bound(ALL(sum),T-dp[i]+1)-sum.begin()-1;
		ma=max(ma,i+x);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
