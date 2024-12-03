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

int T,N,B,X;
int C[202020];
ll D[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>B>>X;
		int ma=0;
		FOR(i,N) {
			cin>>C[i];
			ma=max(ma,C[i]);
		}
		FOR(i,ma+1) D[i]=0;
		FOR(i,N) {
			ll pre=0;
			for(x=1;x<=C[i];x++) {
				ll pat=1LL*C[i]*(C[i]-1)/2;
				ll a=C[i]/x;
				pat-=x*a*(a-1)/2;
				pat-=a*(C[i]%x);
				
				D[x]+=pat-pre;
				pre=pat;
			}
		}
		ll ret=0;
		for(i=1;i<=ma;i++) {
			D[i]+=D[i-1];
			ret=max(ret,D[i]*B-1LL*(i-1)*X);
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
