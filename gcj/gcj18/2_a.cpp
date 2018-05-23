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
int C[1010];
int tar[1010];
string S[102];

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int sum=0;
	FOR(i,N) {
		cin>>C[i];
		sum+=C[i];
	}
	if(C[0]==0 || C[N-1]==0 || sum!=N) {
		_P("Case #%d: IMPOSSIBLE\n",TC);
		return;
	}
	x=0;
	FOR(i,N) {
		FOR(y,C[i]) tar[x++]=i;
	}
	
	int ma=0;
	FOR(i,101) S[i]=string(N,'.');
	FOR(i,N) {
		if(tar[i]<i) {
			FOR(x,i-tar[i]) S[x][i-x]='/';
		}
		if(tar[i]>i) {
			FOR(x,tar[i]-i) S[x][i+x]='\\';
		}
		ma=max(ma,abs(tar[i]-i)+1);
	}
	
	_P("Case #%d: %d\n",TC, ma);
	FOR(i,ma) _P("%s\n",S[i].c_str());
	
	
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
