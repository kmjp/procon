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

ll N;
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	
	for(i=2;i<=min(N,1000000LL);i++) {
		ll x=N;
		while(x) ret+=x%i, x/=i;
		ret%=mo;
	}
	for(int a=1;a<=1000000;a++) {
		ll L=N/(a+1)+1;
		ll R=N/a;
		L=max(L,1000001LL);
		if(L<=R) {
			ll dif=N-(a*L);
			ll dif2=N-(a*R);
			ll num=R-L+1;
			
			(ret+=a*num%mo+dif2*num%mo+a*num%mo*((num-1)%mo)%mo*((mo+1)/2))%=mo;
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
