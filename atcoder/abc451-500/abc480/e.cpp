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

ll N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=0;
	for(ll a=1;a*a*a<=N;a++) {
		ll can=0;
		for(i=29;i>=0;i--) {
			if((__int128)a*(a+(can+(1<<i)))*(a+2*(can+(1<<i)))<=N) can+=(1<<i);
		}
		ret+=can;
	}
	
	for(ll a=1;(__int128)a*(a+1)*(a+2)*(a+3)<=N;a++) {
		ll can=0;
		for(i=25;i>=0;i--) {
			if((__int128)a*(a+(can+(1<<i)))*(a+2*(can+(1<<i)))*(a+3*(can+(1<<i)))<=N) can+=(1<<i);
		}
		ret+=can;
	}
	for(ll a=1;(__int128)a*(a+1)*(a+2)*(a+3)*(a+4)<=N;a++) {
		for(ll b=1;b<=N;b++) {
			__int128 cur=1;
			FOR(i,100) {
				cur*=(a+b*i);
				if(cur>N) break;
			}
			if(i<=4) break;
			ret+=i-4;
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
