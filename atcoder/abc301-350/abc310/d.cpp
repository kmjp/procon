#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,T,M;
int A[101],B[101],C[101];
int ok[1024];

ll dp[1<<10][11];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]=1<<(A[i]-1);
		B[i]=1<<(B[i]-1);
		C[i]=A[i]|B[i];
	}
	int mask,mask2;
	FOR(mask,1<<N) {
		ok[mask]=1;
		FOR(i,M) {
			if((mask&C[i])==C[i]) ok[mask]=0;
		}
	}
	dp[0][0]=1;
	FOR(i,T) {
		FOR(mask,1<<N) if(dp[mask][i]) {
			for(j=N-1;j>=0;j--) if((mask&(1<<j))==0) break;
			if(j<0) continue;
			
			for(int mask2=(1<<j);mask2<(2<<j);mask2++) if((mask&mask2)==0&&ok[mask2]) {
				dp[mask|mask2][i+1]+=dp[mask][i];
			}
			
		}
	}
	cout<<dp[(1<<N)-1][T]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
