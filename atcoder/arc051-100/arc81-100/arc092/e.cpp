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
ll A[1010];
ll dp[1010];
int from[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ma=-1LL<<60;
	int best=-1;
	
	for(i=1;i<=N;i++) {
		cin>>A[i];
		dp[i]=A[i];
		for(x=1;x<i;x++) if((i-x)%2==0) {
			if(dp[x]+A[i]>dp[i]) {
				from[i]=x;
				dp[i]=dp[x]+A[i];
			}
		}
		if(dp[i]>ma) {
			ma=dp[i];
			best=i;
		}
	}
	
	cout<<ma<<endl;
	vector<int> V;
	for(x=N;x>best;x--) V.push_back(x);
	while(from[x]>0) {
		y=from[x];
		while(y<x) {
			V.push_back((x+y)/2);
			x-=2;
		}
	}
	FOR(i,x-1) V.push_back(1);
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
