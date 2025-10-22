#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
ll N,K;
const ll mo=998244353;

ll p10[20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,19) p10[i+1]=p10[i]*10;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		ll U=N/p10[K];
		ll L=N%p10[K];
		
		// Šï”
		ll o=((U+1)/2-(U%2))%mo;
		//‹ô”
		ll e=(U/2-(U%2==0))%mo;
		// Z‚ÌãˆÊŒ…‚ªN‚Æ•sˆê’v
		ll U1=(o*(o-1)+e*(e+1))/2%mo;
		// Z‚ÌãˆÊŒ…‚ªN‚Æˆê’v
		ll U2=U/2%mo;
		
		// Z‚ÌãˆÊŒ…‚ªNˆÈã
		o=(p10[K]/2-L/2)%mo;
		e=(p10[K]/2-(L+1)/2)%mo;
		
		ll L2=(o*(o-1)+e*(e-1))/2%mo;
		// Šï”‚Æ‹ô”‚ğ2‚Â‘I‚Ô
		ll L1=((p10[K]/2)%mo*((p10[K]/2-1)%mo)%mo+mo-L2)%mo;
		
		ll ret=U1*L1+U1*L2+U2*L1;
		cout<<ret%mo<<endl;
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
