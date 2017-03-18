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

string S;
char N[505050];
char M[505050];

int ok(int k) {
	int i;
	if(k<=0) return 0;
	memmove(M,N,sizeof(N));
	int tot=0;
	int carry = 9*k;
	FOR(i,505000) {
		int v = M[i] + carry;
		carry = v/10;
		M[i] = v%10;
		tot += M[i];
	}
	return 9*k >= tot;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	reverse(ALL(S));
	FOR(i,S.size()) N[i]=S[i]-'0';
	FOR(i,505000) N[i]*=9;
	FOR(i,505000) {
		N[i+1] += N[i]/10;
		N[i] %= 10;
	}
	
	int ret=(1<<20);
	for(i=20;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
