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
ll memo[103][103];
ll mo=1000000007;

ll hoge(int A,int B) {
	ll& ret=memo[A][B];
	if(ret>=0) return ret;
	if(A<=1 || B<=1) return 1;
	
	ret=0;
	for(int x=1;x<=B;x++) ret+=hoge(x,A-1);
	ret %= mo;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int A,B,C;
	
	MINUS(memo);
	cin>>N;
	while(N) {
		N--;
		cin>>A>>B>>C;
		ll ret=0;
		for(i=1;i<=A;i++) for(j=1;j<=B;j++) for(x=1;x<=C;x++) (ret+=hoge(i,j)*hoge(B+1-j,x)%mo*hoge(A+1-i,C+1-x))%=mo;
		for(i=1;i<=A;i++) (ret+=hoge(i,B+1)*hoge(A+1-i,C)%mo)%=mo;
		for(i=1;i<=B;i++) (ret+=hoge(i,A+1)*hoge(B+1-i,C)%mo)%=mo;
		for(i=1;i<=C;i++) (ret+=hoge(i,A+1)*hoge(C+1-i,B)%mo)%=mo;
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
