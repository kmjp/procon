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

vector<ll> LCM={1,1};
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=40;i++) {
		LCM.push_back(LCM.back()*(i/__gcd(1LL*i,LCM.back())));
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		ll ret=0;
		for(i=1;i<=40;i++) {
			ll l=LCM[i];
			ll a=N/l%mo;
			(ret+=(l/i%mo)*((N+1)%mo*a%mo+mo-a*(a+1)/2%mo*(l%mo)%mo))%=mo;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
