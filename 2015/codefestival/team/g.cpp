#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,L;
int A[101010],B[101010];
int C[101010],D[101010];
int ma[101010],ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>L;
	FOR(i,N) cin>>A[i]>>B[i];
	FOR(i,M) {
		cin>>C[i]>>D[i];
		for(j=10000;j>=C[i];j--) ma[j]=max(ma[j],ma[j-C[i]]+D[i]);
	}
	
	FOR(j,10000) ma[j+1]=max(ma[j+1],ma[j]);
	FOR(i,N) if(A[i]<=L) ret=max(ret,ma[L-A[i]]+B[i]);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
