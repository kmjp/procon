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

int T,N;
ll A[202020],B[202020],C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i]>>B[i]>>C[i];
			B[i]=min(B[i],A[i]+C[i]);
			A[i]=min(A[i],B[i]);
			C[i]=min(C[i],B[i]);
		}
		ll ret=0;
		for(i=60;i>=0;i--) {
			ll SA=0,SB=0,SM=0;
			FOR(j,N) {
				ll a=A[j];
				ll b=min(C[j],B[j]-a);
				ll c=min(a,C[j]-b);
				SA+=a;
				SB+=b;
				SM+=c;
			}
			ll tmp=ret+(1LL<<i);
			if(SA<tmp) continue;
			SB+=min(SM,SA-tmp);
			if(SB<tmp) continue;
			ret=tmp;
			
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
