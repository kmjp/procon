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

int T;
ll N;
ll V[3];
ll ask(ll L,ll R,int num) {
	L=max(L,1LL);
	R=min(R,N);
	if(L>R) return 0;
	cout<<"xor "<<L<<" "<<R<<endl;
	ll ret;
	cin>>ret;
	if(num>=2&&L<=V[0]&&V[0]<=R) ret^=V[0];
	if(num>=3&&L<=V[1]&&V[1]<=R) ret^=V[1];
	
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		V[0]=V[1]=0;
		for(ll A=(1LL<<62);A>=1;A/=2) {
			ll v=ask(V[0]|A,V[0]|(A+A-1),1);
			if(v) V[0]|=A;
		}
		for(ll A=(1LL<<62);A>=1;A/=2) {
			ll v=ask(V[1]|A,V[1]|(A+A-1),2);
			if(v) V[1]|=A;
		}
		V[2]=ask(1,N,3);
		cout<<"ans "<<V[0]<<" "<<V[1]<<" "<<V[2]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
