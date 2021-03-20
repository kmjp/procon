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

int N,Q;
int T[202020],A[202020];

ll L,R,LV,RV;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	L=LV=-1LL<<60;
	R=RV=1LL<<60;
	FOR(i,N) {
		cin>>A[i]>>T[i];
		if(T[i]==1) {
			LV+=A[i];
			RV+=A[i];
		}
		else if(T[i]==2) {
			if(LV<A[i]) {
				L+=A[i]-LV;
				LV=A[i];
			}
			if(RV<A[i]) {
				R+=A[i]-RV;
				RV=A[i];
			}
		}
		else if(T[i]==3) {
			if(RV>A[i]) {
				R-=RV-A[i];
				RV=A[i];
			}
			if(LV>A[i]) {
				L-=LV-A[i];
				LV=A[i];
			}
		}
	}
	
	cin>>Q;
	while(Q--) {
		ll X;
		cin>>X;
		if(X<=L) cout<<LV<<endl;
		else if(X>=R) cout<<RV<<endl;
		else cout<<LV+(X-L)<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
