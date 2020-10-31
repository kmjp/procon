#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
ll A[101];

ll L[101][101];
ll R[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			L[i][i]=R[i][i]=1;
		}
		for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) {
				y=x+len-1;
				if(R[x+1][y]>A[y]) {
					L[x][y]=1;
				}
				else {
					L[x][y]=L[x][y-1]+A[y]-R[x+1][y]+1;
				}
				if(L[x][y-1]>A[x]) {
					R[x][y]=1;
				}
				else {
					R[x][y]=R[x+1][y]+A[x]-L[x][y-1]+1;
				}
			}
		}
		
		if(L[0][N-1]<=A[0]) cout<<"First"<<endl;
		else cout<<"Second"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
