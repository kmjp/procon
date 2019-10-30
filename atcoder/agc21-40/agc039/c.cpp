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
string S;
ll mo=998244353;

ll dp[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) c-='0';
	
	/*
	set<int> T;
	FOR(i,1<<N) if(T.count(i)==0) {
		int mask=i;
		int cur=0;
		T.insert(i);
		for(x=0;x==0 || mask!=i;x++) {
			mask=(mask>>1) | (((mask&1)^1)<<N-1);
			T.insert(mask);
		}
		cout<<i<<" "<<x<<" ";
		FOR(x,N) cout<<(i>>x)%2;
		cout<<endl;
	}
	*/
	for(i=1;i<=N;i+=2) if(N%i==0) {
		int len=N/i;
		string T=S.substr(0,len);
		int le=0;
		x=0,y=0;
		FOR(j,N) {
			if(S[j]==0 && ((T[x]^y)==1)) {
				le=1;
				break;
			}
			if(S[j]==1 && ((T[x]^y)==0)) {
				break;
			}
			x++;
			if(x>=len) x=0,y^=1;
		}
		if(le) {
			for(y=len-1;y>=0;y--) {
				if(T[y]) {
					T[y]=0;
					le=0;
					for(y=y+1;y<len;y++) T[y]=1;
					break;
				}
			}
		}
		if(le) continue;
		ll tot=0;
		FOR(y,len) {
			tot=(tot*2+T[y])%mo;
		}
		tot++;
		dp[len]=tot;
		
	}
	ll ret=0;
	for(i=1;i<=N;i++) if(dp[i] && N%i==0) {
		for(j=i*2;j<=N;j+=i) (dp[j]+=mo-dp[i])%=mo;
		//cout<<i<<" "<<dp[i]<<"*"<<(2*i)<<endl;
		(ret+=dp[i]*(2*i))%=mo;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
