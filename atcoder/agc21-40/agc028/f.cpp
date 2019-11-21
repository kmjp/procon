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
string S[2020];
short L[1504][1504],R[1504][1504];
int dp[1504][1504];


void solve() {
	int i,j,k,l,r,x,y,x2,y2; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FORR(c,S[y]) {
			if(c!='#') c-='0';
			else c=0;
		}
	}
	ll ret=0;
	for(y=N-1;y>=0;y--) {
		L[y][N]=N;
		R[y][N]=-1;
		for(x=N-1;x>=0;x--) {
			int down=(y<N-1) && (S[y+1][x]>0);
			int right=(x<N-1) && (S[y][x+1]>0);
			
			if(S[y][x]==0) {
				for(y2=y;y2<N;y2++) {
					L[y][x]=N;
					R[y][x]=-1;
				}
			}
			else {
				dp[y][x]=dp[y+1][x]+dp[y][x+1];
				L[y][x]=x;
				if(down&&right) {
					R[y][x]=R[y][x+1];
					
					int r=0;
					for(y2=y+1;y2<N;y2++) {
						if(L[y2][x+1]<=R[y2][x] && r<L[y2][x+1]) {
							dp[y][x]-=dp[y2][L[y2][x+1]];
						}
						r=R[y2][x];
						R[y2][x]=max(R[y2][x],R[y2][x+1]);
						L[y2][x]=min(L[y2][x],L[y2][x+1]);
					}
				}
				else if(down) {
					R[y][x]=x;
				}
				else if(right) {
					R[y][x]=R[y][x+1];
					for(y2=y+1;y2<N;y2++) {
						L[y2][x]=L[y2][x+1];
						R[y2][x]=R[y2][x+1];
					}
				}
				else {
					R[y][x]=x;
					for(y2=y+1;y2<N;y2++) {
						L[y2][x]=N;
						R[y2][x]=0;
					}
				}
				ret+=S[y][x]*dp[y][x];
				dp[y][x]+=S[y][x];
			}
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
