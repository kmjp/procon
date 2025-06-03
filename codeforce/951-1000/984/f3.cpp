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
ll L,R,I,K;

ll all(ll v) {
	ll ret=0;
	while(v&&v%4!=3) {
		ret^=v;
		v--;
	}
	return ret;
}

ll hoge(ll v) {
	if(v<K) return 0;
	
	ll ret=0;
	if(v%(1LL<<I)>=K) {
		v=((v>>I)<<I)+K;
	}
	else {
		v=(((v>>I)-1)<<I)+K;
	}
	while(v>0&&(v>>I)%4!=3) {
		ret^=v;
		v-=(1<<I);
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>L>>R>>I>>K;
		cout<<(all(R)^all(L-1)^hoge(R)^hoge(L-1))<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
