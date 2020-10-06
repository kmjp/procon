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

int N;
int X[101];
const ll mo=1000000007;
ll memo[205][205][205];


ll hoge(int L,int R,int H) {
	if(L==R) return 1;
	if(L+1==R) return 1;
	if(H<=0) return 0;
	if(memo[L][R][H]>=0) return memo[L][R][H];
	
	ll ret=0;
	for(int i=L+1;i<R;i++) {
		int nt=min(H,X[i]);
		(ret+=hoge(L,i,nt)*hoge(i,R,nt-1))%=mo;
	}
	
	return memo[L][R][H]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i+1];
		X[i+1]=min(200,X[i+1]);
	}
	X[0]=202;
	MINUS(memo);
	
	cout<<hoge(0,N+1,202)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
