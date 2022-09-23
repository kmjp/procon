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

ll H,W;
int Q;
const ll mo=998244353;

ll hoge(ll L,ll R,ll U,ll D) {
	ll ret=0;
	if(L>R||U>D) return 0;
	ll w=(R-L+2)/2;
	ll h=(D-U+2)/2;
	ret+=h*w%mo*((U*W)%mo+L+1)%mo;
	
	ret+=w*(w-1)/2%mo*2%mo*h%mo;
	ret+=h*(h-1)/2%mo*(2*W)%mo*w%mo;
	
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	cin>>Q;
	while(Q--) {
		ll U,D,L,R;
		cin>>U>>D>>L>>R;
		U--,D--,L--,R--;
		ll ret=0;
		if((U+L)%2==0) {
			ret=hoge(L,R,U,D)+hoge(L+1,R,U+1,D);
		}
		else {
			ret=hoge(L+1,R,U,D)+hoge(L,R,U+1,D);
		}
		cout<<ret%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
