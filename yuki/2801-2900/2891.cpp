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
	ll ret=0;
	for(i=1;i<=min(2000000LL,N);i++) (ret+=M%i)%=mo;;
	(ret+=(N+1-i)%mo*(M%mo))%=mo;
	
	ll pre=i;
	for(i=2000000;i>=1;i--) {
		ll L=M/(i+1)+1;
		ll R=M/i;
		R=min(R,N);
		L=max(L,pre);
		if(L<=R) {
			ret-=i*((L+R)%mo)%mo*((R-L+1)%mo)%mo*(mo+1)/2;
			ret%=mo;
			
			pre=R+1;
		}
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
