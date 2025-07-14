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

ll A,B,C,N;
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	for(ll B=2;B<=1000000;B++) {
		ll K=N/B;
		if(K>=1) (ret+=(K-1)%mo*(B-1)+N%B)%=mo;
	}
	for(ll K=1;K<=1000000;K++) {
		ll L=1000001;
		ll R=N/K;
		ll R2=N/(K+1);
		if(L<=R2) {
			(ret+=(R2+L-2)%mo*((R2-L+1)%mo)%mo*((mo+1)/2))%=mo;
			if(R2<R) {
				//for(ll a=R2+1;a<=R;a++) (ret+=N-K*a)%=mo;
				(ret+=N%mo*((R-R2)%mo)%mo-K*(R-R2)%mo*((R+R2+1)%mo)%mo*(mo+1)/2)%=mo;
			}
		}
		else if(L<=R) {
			(ret+=N%mo*((R-L+1)%mo)%mo-K*(R-L+1)%mo*((R+L)%mo)%mo*(mo+1)/2)%=mo;
		}
	}
	ret=(ret%mo+mo)%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
