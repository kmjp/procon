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

string S;

ll memo[20][2][2][7];


ll dp(int d,int less,int first,int mo) {
	if(d<0) return first==0&&mo==0;
	
	if(memo[d][less][first][mo]>=0) return memo[d][less][first][mo];
	ll ret=0;
	int i;
	if(less==0) {
		for(i=1-first;i<=S[d]-'0';i++) {
			if(i==S[d]-'0') ret+=dp(d-1,0,first&&i==0,(mo*10+i)%7);
			else ret+=dp(d-1,1,first&&i==0,(mo*10+i)%7);
		}
	}
	else {
		for(i=1-first;i<=7;i++) {
			ret+=dp(d-1,1,first&&i==0,(mo*10+i)%7);
		}
	}
	return memo[d][less][first][mo]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	MINUS(memo);
	reverse(ALL(S));
	S+="0000000000000000000";
	cout<<dp(18,0,1,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
