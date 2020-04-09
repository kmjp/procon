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
int A[1505050][2];

int L[1010100][2],R[1010100][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) cin>>A[i+1][0];
	FOR(i,2*N) cin>>A[i+1][1];
	
	for(i=1;i<=2*N;i++) {
		FOR(j,2) L[i][j]=2*N+10,R[i][j]=-1;
		FOR(x,2) FOR(y,2) if(A[i-1][x]<=A[i][y]) L[i][y]=min(L[i][y],L[i-1][x]+y),R[i][y]=max(R[i][y],R[i-1][x]+y);
	}
	x=-1;
	if(L[2*N][0]<=N&&N<=R[2*N][0]) x=0;
	if(L[2*N][1]<=N&&N<=R[2*N][1]) x=1;
	
	if(x>=0) {
		string S;
		int cur=N;
		for(i=2*N;i>=1;i--) {
			if(x==0) {
				S+="A";
			}
			else {
				cur--;
				S+="B";
			}
			if(A[i-1][0]<=A[i][x] && L[i-1][0]<=cur&&cur<=R[i-1][0]) x=0;
			else x=1;
			
		}
		reverse(ALL(S));
		cout<<S<<endl;
	}
	else {
		cout<<-1<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
