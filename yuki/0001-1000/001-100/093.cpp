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

ll N;
ll mo=1000000007;
ll& add(ll& a,ll b) { return a=(a+b)%mo;}
ll dp[2][1005][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==1) return _P("1\n");
	if(N==2) return _P("2\n");
	
	dp[0][0][0][0]=2;
	for(i=2;i<N;i++) {
		int cur=i%2,tar=cur^1;
		ZERO(dp[tar]);
		FOR(x,i-1) {
			ll v;
			
			if(x>=2) {
				v=dp[cur][x][1][1];
				if(v) {
					add(dp[tar][x][1][1]  ,v);             // split (i-1,i-3)
					add(dp[tar][x-1][0][0],v);             // split (i,i-2)
					add(dp[tar][x-1][1][0],v*(x-2));       // split others
					add(dp[tar][x+1][1][1],v);             // near i-1
					add(dp[tar][x][1][0]  ,v*(i+1-(x+1))); // else
				}
			}
			if(x>=1) {
				v=dp[cur][x][0][1];
				if(v) {
					add(dp[tar][x-1][0][0],v);           // split (i,i-2)
					add(dp[tar][x-1][1][0],v*(x-1));     // split others
					add(dp[tar][x+1][1][1],v*2);         // near i-1
					add(dp[tar][x][1][0]  ,v*(i+1-x-2)); // else
				}
				v=dp[cur][x][1][0];
				if(v) {
					add(dp[tar][x][0][1],  v);           // split (i-1,i-3)
					add(dp[tar][x-1][0][0],v*(x-1));     // split others
					add(dp[tar][x+1][0][1],v);           // near i-1
					add(dp[tar][x][0][0],  v*(i+1-x-1)); // else
				}
			}
			
			v=dp[cur][x][0][0];
			if(v) {
				add(dp[tar][x+1][0][1]        ,2*v);         // near i-1
				if(x>0) add(dp[tar][x-1][0][0],x*v);         // split
				add(dp[tar][x][0][0]          ,(i+1-2-x)*v); // else
			}
		}
	}
	
	cout<<dp[N%2][0][0][0]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
