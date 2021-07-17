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


const ll mo=1000000007;
ll L,R;
ll p10[19];

ll hoge(ll v) {
	int i;
	ll ret=0;
	for(i=18;i>=0;i--) {
		if(v>=p10[i]) {
			ll s=p10[i];
			ll t=v;
			ll num=(t-s+1)%mo;
			(ret+=(s+t)%mo*num%mo*((mo+1)/2)%mo*(i+1))%=mo;
			v=p10[i]-1;
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	for(i=1;i<=18;i++) p10[i]=p10[i-1]*10;
	
	
	cin>>L>>R;
	ll ret=hoge(R)-hoge(L-1)+mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
