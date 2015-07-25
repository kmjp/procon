#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,P;
int A[5050],B[5050];
pair<int,int> PP[5050];
int ma;

int dp[15050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) cin>>PP[i].first>>PP[i].second;
	sort(PP,PP+N);
	
	FOR(i,N) A[N-1-i]=PP[i].first,B[N-1-i]=PP[i].second;
	dp[0]=0;
	
	FOR(i,N) {
		for(x=P;x>=0;x--) {
			ma=max(ma,dp[x]+B[i]);
			dp[x+A[i]]=max(dp[x+A[i]],dp[x]+B[i]);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
