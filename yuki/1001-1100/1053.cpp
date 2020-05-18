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
	int i,j,k,l,r,x,y;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	if(count(A,A+N,A[0])==N) return _P("0\n");
	int ret=0;
	int s=0;
	while(A[s]==A[N-1]) s++, ret=1;
	
	map<int,int> P;
	for(i=s;i<N;i++) {
		if(P.count(A[i]) && P[A[i]]!=i-1) return _P("-1\n");
		P[A[i]]=i;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
