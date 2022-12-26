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

ll mo=1000000007;
int A,B;
ll memo[2020][2020];
ll C[2040][2040];
ll CS[2040][2040];


ll dfs(int A,int B) {
	if(A==0 || B==0) return 1;
	if(memo[A][B]>=0) return memo[A][B];
	// take A;
	ll ret=dfs(A-1,B);
	// take B;
	int a=A,b=B-1;
	// take until a+b==A;
	ret += CS[b][min(a,b)+1]-CS[b][0]+mo;
	return memo[A][B]=ret%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>A>>B;
	if(A==0 || B==0) {
		cout<<1<<endl;
		return;
	}
	for(i=0;i<=2020;i++) {
		C[i][0]=C[i][i]=1;
		if(i) for(j=1;j<i;j++) (C[i][j]=C[i-1][j-1]+C[i-1][j])%=mo;
		FOR(j,2020) (CS[i][j+1]=CS[i][j]+C[i][j])%=mo;
	}
	
	ll ret=0;
	B--;
	for(int a=0;a<=A;a++) {
		for(i=0;i<=a;i++) if(a-i<=B) {
			(ret += C[B][a-i]*dfs(i,a-i))%=mo;
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
