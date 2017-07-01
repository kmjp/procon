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

string A,B,C;

ll memo[51][2];
ll mo=1000000007;

ll dpdp(int d,int ca) {
	if(d>=A.size()) return ca==0;
	if(memo[d][ca]>=0) return memo[d][ca];
	ll ret=0;
	
	int a,b,c;
	FOR(a,10) FOR(b,10) FOR(c,10) {
		if(A[d]!='?' && '0'+a!=A[d]) continue;
		if(B[d]!='?' && '0'+b!=B[d]) continue;
		if(C[d]!='?' && '0'+c!=C[d]) continue;
		if(d==A.size()-1 && a*b*c==0) continue;
		
		if(a+b+ca==c) ret+=dpdp(d+1,0);
		if(a+b+ca==c+10) ret+=dpdp(d+1,1);
	}
	
	return memo[d][ca]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>A>>B>>C;
		if(A=="0") break;
		reverse(ALL(A));
		reverse(ALL(B));
		reverse(ALL(C));
		MINUS(memo);
		cout<<dpdp(0,0)<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
