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
int P[202020];
ll fact[202020];
ll inv[202020];
ll mo=1000000007;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

ll lef[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	for(i=1;i<=200000;i++) {
		fact[i]=fact[i-1]*i%mo;
		inv[i]=fact[i]*i%mo*(i-1)%mo*((mo+1)/2)%mo*((mo+1)/2)%mo;
		
	}
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
	}
	
	lef[N]=1;
	for(i=N-1;i>=0;i--) {
		x=bt(P[i]-1);
		lef[i]=(x*fact[N-1-i]+lef[i+1])%mo;
		bt.add(P[i],1);
	}
	
	ll ret=0;
	FOR(i,N) {
		x=bt(P[i]-1);
		if(x) {
			(ret+=x*lef[i+1])%=mo;
			(ret+=x*inv[N-1-i])%=mo;
			(ret+=1LL*(x-1)*(x)/2%mo*fact[N-1-i])%=mo;
		}
		
		bt.add(P[i],-1);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
