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
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int v=0;
	FOR(i,N) {
		cin>>A[i];
		v=v^A[i];
	}
	
	int ret=N;
	
	if(v==0) {
		ret=0;
		FOR(i,N) if(A[i]!=0) ret=max(ret,N-(i+1));
		reverse(A,A+N);
		FOR(i,N) if(A[i]!=0) ret=max(ret,N-(i+1));
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
