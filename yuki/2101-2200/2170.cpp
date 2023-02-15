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
ll A[202020];
const ll mo=998244353;

int NG[202020];
ll S[202020];
ll MS[202020];
ll p2[202020],r2[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=r2[0]=1;
	FOR(i,201010) {
		p2[i+1]=p2[i]*2%mo;
		r2[i+1]=r2[i]*(mo+1)/2%mo;
	}
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		if(i&&A[i]>A[i-1]) {
			NG[i]=NG[i-1];
		}
		else {
			NG[i]=i;
		}
		S[i+1]=(S[i]+A[i])%mo;
		MS[i+1]=(MS[i]+p2[i]*A[i])%mo;
	}
	while(Q--) {
		int L,R;
		cin>>L>>R;
		L--,R--;
		L=max(NG[R],L);
		ll ret=(MS[R+1]-MS[L+1]+mo)*r2[L+1]+A[L];
		cout<<ret%mo<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
