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


ll A,B,C,D,E;
ll KA,KB,KC,KD,KE;

ll F(ll OE) {
	ll OA=max(0LL,KA-OE);
	ll OB=max(0LL,KB-OA);
	ll OC=max(0LL,KC-OB);
	ll OD=max({0LL,KD-OC,KE-OE});
	return OA+OB+OC+OD+OE;
}


int ok(ll K) {
	
	KA=max(0LL,K-A);
	KB=max(0LL,K-B);
	KC=max(0LL,K-C);
	KD=max(0LL,K-D);
	KE=max(0LL,K-E);
	
	ll L=0,R=K;
	while(R-L>=3) {
		ll M1=(L*2+R)/3;
		ll M2=(R*2+L)/3;
		ll V1=F(M1);
		ll V2=F(M2);
		
		if(V1==V2) {
			L=M1;
			R=M2;
		}
		else if(V1<V2) R=M2;
		else L=M1;
	}
	
	for(ll a=L;a<=R;a++) if(F(a)<=K) return 1;
	return 0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D>>E;
	ll ret=0;
	for(i=52;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
