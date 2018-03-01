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
ll mo;
vector<int> V;
const int CN=4001;
ll C[CN][CN];

vector<int> memo[505][10];

vector<int> hoge(int left,int order) {
	if(memo[left][order].size()) return memo[left][order];
	vector<int> V(N+1,0);
	int i;
	if(order==0) {
		if(left%2==0) {
			for(i=1;i<=N;i++) V[i]=C[i][left];
		}
	}
	else {
		for(int take=0;take<=left;take += 2<<order) {
			vector<int> V2=hoge(left-take,order-1);
			for(i=1;i<=N;i++) {
				V[i]=(V[i]+1LL*V2[i]*C[i][take>>order])%mo;
			}
		}
	}
	return memo[left][order]=V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>mo;
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	
	auto dp=hoge(N,8);
	
	for(i=1;i<=N;i++) {
		dp[i]%=mo;
		for(j=1;j<i;j++) dp[i]=(dp[i]+mo-dp[j]*C[i][j]%mo)%mo;
		cout<<dp[i]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
