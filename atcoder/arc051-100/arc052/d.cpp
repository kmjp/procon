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

ll K,M;
ll p10[18];
ll dp[12][2][100000];
int sum[100000];

ll dfs(int d,int lead,int m) {
	if(d==-1) return m==0;
	ll& ret=dp[d][lead][m];
	if(ret!=-1) return ret;
	ret=0;
	int i;
	int dd=M/p10[d]%10;
	if(lead) {
		FOR(i,dd) ret += dfs(d-1,0,(m+p10[d]*i-i)%K);
		ret += dfs(d-1,1,(m+p10[d]*i-i)%K);
	}
	else {
		FOR(i,10) ret += dfs(d-1,0,(m+p10[d]*i-i)%K);
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>M;
	
	p10[0]=1;
	FOR(i,17) p10[i+1]=p10[i]*10;
	FOR(i,100000) {
		x=i;
		while(x) sum[i] += x%10, x/=10;
	}
	
	ll ret=0;
	if(K>=100000) {
		for(i=0;i*K<=M;i++) {
			ll a=i*K;
			ll m=a%K;
			
			FOR(x,99) {
				a++;
				m++;
				if(m>=K) m-=K;
				if(a>M) break;
				if(a==0) continue;
				if(m == sum[a/100000]+sum[a%100000]) ret++;
			}
		}
	}
	else {
		MINUS(dp);
		ret=dfs(10,1,0)-1;
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
