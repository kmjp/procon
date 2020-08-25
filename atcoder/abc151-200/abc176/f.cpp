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
int A[6060];
int dp[2060][2020];
int ma[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3*N) {
		cin>>A[i];
		A[i]--;
	}
	
	int ret=0;
	FOR(x,N) {
		FOR(y,N) dp[x][y]=-1<<20;
		ma[x]=-1<<20;
	}
	dp[A[0]][A[1]]=0;
	ma[A[0]]=ma[A[1]]=0;
	
	for(i=2;i+2<3*N;i+=3) {
		sort(A+i,A+i+3);
		if(A[i]==A[i+2]) {
			ret++;
			continue;
		}
		vector<vector<int>> cand;
		if(A[i]==A[i+1]) {
			FOR(x,N) cand.push_back({A[i+2],x,max(dp[A[i+1]][x],dp[x][A[i+1]])+1});
		}
		if(A[i+1]==A[i+2]) {
			FOR(x,N) cand.push_back({A[i+0],x,max(dp[A[i+1]][x],dp[x][A[i+1]])+1});
		}
		for(j=i;j<i+3;j++) {
			FOR(x,N) cand.push_back({x,A[j],ma[x]});
		}
		
		
		cand.push_back({A[i+0],A[i+1],dp[A[i+2]][A[i+2]]+1});
		cand.push_back({A[i+0],A[i+2],dp[A[i+1]][A[i+1]]+1});
		cand.push_back({A[i+1],A[i+2],dp[A[i+0]][A[i+0]]+1});
		
		int tmp=-1;
		FOR(x,N) tmp=max(ma[x],tmp);
		cand.push_back({A[i+0],A[i+1],tmp});
		cand.push_back({A[i+0],A[i+2],tmp});
		cand.push_back({A[i+1],A[i+2],tmp});
		
		FORR(c,cand) {
			dp[c[0]][c[1]]=max(dp[c[0]][c[1]],c[2]);
			ma[c[0]]=max(ma[c[0]],c[2]);
			ma[c[1]]=max(ma[c[1]],c[2]);
		}
	}
	
	int ma2=0;
	FOR(x,N) ma2=max(ma2,ma[x]);
	ma2=max(ma2,dp[A[3*N-1]][A[3*N-1]]+1);
	
	cout<<ma2+ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
