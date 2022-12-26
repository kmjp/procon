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
ll p2[101010];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=p2[1]=1;
	for(i=1;i<=101000;i++) p2[i+1]=p2[i]*2%mo;
	ll sum=0;
	ll ret=0;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		sum = (sum+p2[i])*x%mo;
		(ret += sum*p2[N-1-i])%=mo;
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
