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
int A[303][303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int cur=1;
	FOR(y,N/2) FOR(x,N/2) {
		A[y][x]=cur++;
		A[y+N/2][x+N/2]=cur++;
	}
	FOR(y,N/2) FOR(x,N/2) {
		A[y][N-1-x]=cur++;
		A[y+N/2][N/2-1-x]=cur++;
	}
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
