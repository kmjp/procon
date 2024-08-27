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
ll mo;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>mo;
	ll ret=0;
	for(i=1;i<=4000000;i++) {
		if(X>=i*2) (ret+=(X-i*2)*(Y))%=mo;
		if(Y>=i*2) (ret+=(Y-i*2)*(X))%=mo;
	}
	for(int m=1;m*m<=8000000;m++) {
		for(int n=1;n<m;n++) {
			if(m%2!=n%2&&__gcd(m,n)==1) {
				ll a=m*m-n*n;
				ll b=2*m*n;
				for(i=1;2*a*i<=X&&2*b*i<=Y;i++) (ret+=2LL*(X-2*a*i)*(Y-2*b*i))%=mo;
				for(i=1;2*a*i<=Y&&2*b*i<=X;i++) (ret+=2LL*(Y-2*a*i)*(X-2*b*i))%=mo;
			}
		}
	}
	ret=ret*2%mo;
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
