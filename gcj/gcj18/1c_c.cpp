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

int T,testcase;

int N;
ll W[1010101];
ll S[1010101];

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N+5) S[i]=1LL<<60;
	S[0]=0;
	int ma=0;
	FOR(i,N) {
		cin>>W[i];
		x=upper_bound(S,S+N+1,W[i]*6+1)-S;
		while(S[x]>W[i]*6) x--;
		for(y=x;y>=max(0,x-50);y--) {
			S[y+1]=min(S[y+1],S[y]+W[i]);
			ma=max(ma,x+1);
		}
	}
	
	_P("Case #%d: %d\n",TC,ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
