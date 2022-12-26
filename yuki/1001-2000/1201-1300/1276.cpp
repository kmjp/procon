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
const ll mo=1000000007;

ll slow(int v) {
	ll ret=0;
	int i;
	for(i=2;i<=v;i++) {
		ll p=v/i;
		if(p<1) break;
		ret+=p-1;
	}
	return ret%mo;
}

ll hoge(int v) {
	if(v<=100) return slow(v);
	ll ret=0;
	int sq=sqrt(v)+2;
	map<int,int> M; // M[x]= |N/i|‚ªx‚É‚È‚é”
	int i;
	for(i=2;i<=sq;i++) ret+=v/i-1;
	ret%=mo;
	for(i=1;i<=sq;i++) {
		int L=v/i;
		int R=max(sq+1,v/(i+1)+1);
		if(L>=R) (ret+=1LL*(i-1)*(L-R+1))%=mo;
		else break;
	}
	return ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//for(i=1;i<=20;i++) cout<<hoge(i)<<endl;
	
	cin>>N;
	ll ret=0;
	map<int,int> M; // M[x]= |N/i|‚ªx‚É‚È‚é”
	for(i=1;i<=min(200000,N);i++) M[N/i]++;
	for(i=1;i<=20000;i++) {
		int L=N/i;
		int R=max(200001,N/(i+1)+1);
		if(L>=R) M[i]+=L-R+1;
	}
	
	
	// ? x aX
	FORR(m,M) {
		//cout<<m.first<<" "<<m.second<<endl;
		ll b=m.first-1;
		// ? x bx (b>1)
		(ret+=(N-2)*b%mo*m.second)%=mo;
		// ax x bx (a>=1, b>1, a!=b)‚ğˆø‚­
		ll a=(m.first-2);
		(ret-=a*b%mo*m.second)%=mo;
	}
	// X aX abX (1<a<b)
	FORR(m,M) {
		ll pat=hoge(m.first);
		(ret-=pat*m.second)%=mo;
	}
	ret=(ret%mo+mo)%mo;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
