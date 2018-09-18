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

ll N;
ll X[202020],Y;
__int128 S[202020];
ll dp[202020];
int ok[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Y;
	FOR(i,N) cin>>X[i+1], S[i+1]=S[i]+X[i+1];
	__int128 ret=1LL<<60;
	
	for(int i=1;i<=N;i++) {
		__int128 tot=i*Y;
		int left=N;
		int step=1;
		while(left>0) {
			if(step==1) {
				tot+=5*(S[left]-S[max(left-i,0)]);
			}
			else {
				tot+=(2*step+1)*(S[left]-S[max(left-i,0)]);
			}
			left-=i;
			step++;
		}
		ret=min(ret,tot);
	}
	
	cout<<((ll)ret+N*Y)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
