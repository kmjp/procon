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
int K;
int X,Y;
vector<int> E[2020];
string D;
string S[2020];

int dp[2020][2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>X>>Y;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		cin>>S[i];
		E[i].push_back(i);
	}
	
	FOR(j,K+1) FOR(i,N) dp[j][i]=-(1<<30);
	dp[0][0]=0;
	FOR(i,K) {
		cin>>x;
		D=S[x-1];
		FOR(x,N) {
			FORR(e,E[x]) {
				int sc=dp[i][x];
				if(S[e]==D) sc+=Y;
				if(S[e]=="G"&&D=="C") sc+=X;
				if(S[e]=="C"&&D=="P") sc+=X;
				if(S[e]=="P"&&D=="G") sc+=X;
				dp[i+1][e]=max(dp[i+1][e],sc);
			}
		}
	}
	cout<<*max_element(dp[K],dp[K]+N)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
