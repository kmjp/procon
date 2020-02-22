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
string S[40];
ll memo[41][41][41];

ll hoge(int L,int M,int R) {
	if(L==R) return 1;
	if(L>R) return 0;
	if((R-L)%2==1) return 0;
	if(memo[L][M][R]>=0) return memo[L][M][R];
	
	int L2,R2,A,B;
	ll ret=0;
	for(L2=L;L2<M;L2++) for(R2=M+1;R2<=R;R2++) if(S[L2][R2]) {
		for(A=L2;A<M;A++) for(B=M+1;B<=R2;B++) ret+=hoge(L,L2,A)*hoge(A+1,M,B-1)*hoge(B,R2,R);
		
	}
	
	return memo[L][M][R]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>S[i];
		FORR(c,S[i]) c-='0';
	}
	
	MINUS(memo);
	ll ret=0;
	for(i=1;i<2*N;i++) if(S[0][i]) ret+=hoge(1,i,2*N-1);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
