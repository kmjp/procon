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

int N;
int D[5050];

string S[10100];
int ID[10100];
int numfr, nums,numg;
ll mo=1000000007;
ll dp[2][5011];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>S[i]>>ID[i];
		if(ID[i]!=0) {
			if(S[i]=="S") D[ID[i]] |= 1;
			if(S[i]=="G") D[ID[i]] |= 2;
		}
	}
	
	dp[0][0]=1;
	FOR(i,N) if(D[i+1]==0) dp[0][0]=dp[0][0]*(++numfr)%mo;
	
	FOR(i,2*N) {
		int cur=i%2,tar=cur^1;
		if(D[ID[i]]==3) {
			memmove(dp[tar],dp[cur],sizeof(dp[cur]));
			continue;
		}
		ZERO(dp[tar]);
		if(S[i]=="S") {
			FOR(x,5001) dp[tar][x+(ID[i]==0)]+=dp[cur][x];
			nums++;
		}
		else {
			if(ID[i]==0) {
				FOR(x,5001) if(dp[cur][x]) {
					// take free
					if(x) (dp[tar][x-1] += dp[cur][x])%=mo;
					// take fix
					int fix = nums - numg - x;
					if(fix>0) (dp[tar][x] += fix * dp[cur][x])%=mo;
				}
			}
			else {
				FOR(x,5001) if(x) dp[tar][x-1]+=dp[cur][x];
			}
			numg++;
		}
	}
	
	cout<<dp[0][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
