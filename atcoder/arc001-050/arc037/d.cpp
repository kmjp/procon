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

ll L;
ll mo=1000000007;
ll D[101000][3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L;
	D[0][0]=D[0][1]=D[0][2]=1;
	
	for(i=1;i<=L;i++) {
		ll p0=D[i-1][0],p1=D[i-1][1],p2=D[i-1][2];
		ll t=p1+p2;
		
		D[i][0] += 3*p0;
		D[i][0] += t*t%mo*t;
		D[i][0] %= mo;
		
		D[i][1] += p1*p2%mo*p1;
		D[i][1] += p1*p2%mo*p1;
		D[i][1] += p2*p2%mo*p1;
		D[i][1] %= mo;
		
		D[i][2] += t*t;
		D[i][2] += p1*p2%mo*p2;
		D[i][2] += p1*p2%mo*p2;
		D[i][2] += p2*p2%mo*p2;
		D[i][2] %= mo;
	}
	cout<<D[L][0]%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
