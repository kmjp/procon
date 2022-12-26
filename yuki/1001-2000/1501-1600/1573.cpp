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

ll X,Y;
const ll mo=998244353;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	ll ret=0;
	for(y=1;y<=min(Y,100000LL);y++) {
		ll num=X/y;
		ret+=y*num%mo;
		ret+=(num*(num+1)/2)%mo*y%mo;
	}
	for(ll num=1;num<=200000;num++) {
		ll R=X/num;
		ll L=X/(num+1)+1;
		R=min(R,Y);
		L=max(L,100001LL);
		if(L<=R) {
			ll p=(L+R)*(R-L+1)/2%mo;
			ret+=p*num%mo;
			ret+=(num*(num+1)/2)%mo*p%mo;
			
		}
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
