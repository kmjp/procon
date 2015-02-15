#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll B[100020];
int wrong[100020],wrong2[100020];
int dp[100020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>B[i];
	FOR(i,N) if(B[i]%__gcd(B[(i+N-1)%N],B[(i+1)%N])) wrong2[i]=1;
	
	y=1<<30;
	FOR(i,3) {
		FOR(j,N) wrong[j]=wrong2[(j+i)%N];
		x=0;
		FOR(j,N) if(wrong[j]==1) x++, wrong[j]=wrong[j+1]=wrong[j+2]=0;
		y=min(y,x);
	}
	cout<<y<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
