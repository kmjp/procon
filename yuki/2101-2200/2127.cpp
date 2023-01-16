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

ll N,M;
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll ret=(N*(N+1)/2)%mo*M%mo;
	
	for(j=1;j<=min(10000LL,M);j++) {
		ll nj=N/j;
		ret-=(N+1)*nj*j%mo;
		ret+=nj*(nj+1)/2%mo*j%mo*j%mo;
	}
	for(int nj=1;nj<=200000;nj++) {
		ll L=max(10000LL,N/(nj+1));
		ll R=min(M,N/nj);
		if(L<R) {
			ret-=(N+1)*nj%mo*((R*(R+1)-L*(L+1))/2%mo)%mo;
			ret+=1LL*nj*(nj+1)/2%mo*(((__int128)R*(R+1)*(2*R+1)-(__int128)L*(L+1)*(2*L+1))/6%mo)%mo;
		}
	}
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
