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

ll K;
ll SX,SY,TX,TY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>SX>>SY>>TX>>TY;
	ll ret=abs(TX-SX)+abs(TY-SY);
	
	vector<vector<ll>> S,T;
	if((SX/K+SY/K)%2==1) {
		S.push_back({SX/K,SY/K,0});
	}
	else {
		S.push_back({SX/K-1,SY/K,SX%K+1});
		S.push_back({SX/K,SY/K-1,SY%K+1});
		S.push_back({SX/K+1,SY/K,K-SX%K});
		S.push_back({SX/K,SY/K+1,K-SY%K});
	}
	if((TX/K+TY/K)%2==1) {
		T.push_back({TX/K,TY/K,0});
	}
	else {
		T.push_back({TX/K-1,TY/K,TX%K+1});
		T.push_back({TX/K,TY/K-1,TY%K+1});
		T.push_back({TX/K+1,TY/K,K-TX%K});
		T.push_back({TX/K,TY/K+1,K-TY%K});
	}
	FORR(s,S) FORR(t,T) {
		ll a=abs(s[0]-t[0]);
		ll b=abs(s[1]-t[1]);
		assert(a%2==b%2);
		ll c=s[2]+t[2]+2*max(a,b);
		if(K==2) {
			c=s[2]+t[2]+2*min(a,b)+3*abs(b-a)/2;
		}
		ret=min(ret,c);
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
