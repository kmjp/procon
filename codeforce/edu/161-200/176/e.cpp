#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
ll N,M,A,B;
const ll mo=998244353;

ll memo[31][2][2][2]; //less1, less2, split

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dfs(int d,int lea,int leb,int sp) {
	if(d==-1) return sp;
	if(memo[d][lea][leb][sp]>=0) return memo[d][lea][leb][sp];
	ll ret=0;
	
	int ad=(A>>d)%2;
	int bd=(B>>d)%2;
	
	int a0,a1,b0,b1;
	FOR(a0,2) FOR(a1,2) FOR(b0,2) FOR(b1,2) if((a0^a1)==(b0^b1)) {
		if(sp==0) {
			if((a0||a1)&&lea==0&&ad==0) continue;
			if((b0||b1)&&leb==0&&bd==0) continue;
			if(a0==a1) {
				// splitÇµÇ»Ç¢
				ret+=dfs(d-1,lea|(a0<ad),leb|(b0<bd),0);
			}
			else {
				// splitÇ∑ÇÈ
				if(a0>a1) continue;
				if(b0>b1) continue;
				if(lea==0&&ad==0) continue;
				if(leb==0&&bd==0) continue;
				ret+=dfs(d-1,lea,leb,1);
			}
		}
		else {
			if(a0&&lea==0&&ad==0) continue;
			if(b0&&leb==0&&bd==0) continue;
			ret+=dfs(d-1,lea|(a0<ad),leb|(b0<bd),1);
		}
	}
	
	return memo[d][lea][leb][sp]=ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>A>>B;
		
		ll n2=(modpow(2,N)+mo-2)%mo;
		ll m2=(modpow(2,M)+mo-2)%mo;
		
		// 1éÌóﬁÅ~1éÌóﬁ
		MINUS(memo);
		ll ret=(A+1)*(B+1)%mo;
		// 1éÌóﬁÅ~2éÌóﬁ
		ret+=((A+1)*A/2)%mo*n2%mo*(B+1)%mo;
		ret+=((B+1)*B/2)%mo*m2%mo*(A+1)%mo;
		// 2éÌóﬁÅ~2éÌóﬁ
		MINUS(memo);
		ret+=n2*m2%mo*dfs(30,0,0,0);
		cout<<ret%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
