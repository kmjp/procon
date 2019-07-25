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
int M[202020];
vector<int> A[202020];
ll S[202020];
int L[202020][11];
ll mo=1000000007;

ll ret=0;
ll p10[2020202];
ll dp[202020];
ll SM[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	SM[0]=1;
	FOR(i,N) {
		cin>>M[i];
		FOR(j,M[i]) {
			cin>>x;
			A[i].push_back(x);
			S[i]+=x;
			y=0;
			while(x) y++, x/=10;
			L[i][y]++;
		}
		SM[i+1]=SM[i]*M[i]%mo;
		S[i]%=mo;
	}
	p10[0]=1;
	FOR(i,2020100) p10[i+1]=p10[i]*10%mo;
	
	dp[0]=1;
	int ma=0;
	FOR(i,N) {
		j=N-1-i;
		(ret+=dp[i]*S[j]%mo*SM[j])%=mo;
		for(x=1;x<=10;x++) if(L[j][x]) {
			(dp[i+1]+=dp[i]*p10[x]%mo*L[j][x])%=mo;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
