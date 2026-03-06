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
ll N,M;
unordered_map<ll,ll> mp;

ll hoge(ll L,ll R) {
	if(L==R) return 0;
	if(mp.count((L<<32)+R)) return mp[(L<<32)+R];
	ll OL=L,OR=R;
	int i,j;
	ll ret=0;
	
	for(i=31;i>=0;i--) {
		if((R&(1LL<<i))==(L&(1LL<<i))) {
			if(R&(1LL<<i)) {
				R-=1LL<<i;
				L-=1LL<<i;
			}
		}
		else {
			ll M=(1LL<<i);
			ret=hoge(L,M-1)+hoge(0,R-M)+M;
			
			R-=M;
			for(j=i-1;j>=0;j--) {
				if(R>=L) break;
				if((R&(1LL<<j))!=(L&(1LL<<j))) ret+=1LL<<j;
				if(R&(1LL<<j)) R^=(1LL<<j);
				if(L&(1LL<<j)) L^=(1LL<<j);
				
			}
			
			
			break;
		}
	}
	return mp[(OL<<32)+OR]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		cout<<hoge(M,M+N-1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
