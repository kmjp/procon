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

vector<int> D[1010101];
const ll mo=998244353;
int T,M;
ll dp[1<<20];
ll tmp[1<<20];
ll dp2[1<<20];
ll ret[1<<20];

const int prime_max = 2000000;
int MU[prime_max+1];
int num[prime_max+1];

void mobius() {
	int i,j;
	for(i=1;i<=prime_max;i++) MU[i]=1, num[i]=i;
	for(int i=2;i<=prime_max;i++) if(num[i]==i) {
		for(j=i;j<=prime_max;j+=i) {
			int x=0;
			MU[j]=-MU[j];
			while(num[j]%i==0) {
				x++;
				num[j]/=i;
			}
			if(x>=2) MU[j]=0;
		}
	}
	for(i=1;i<=prime_max;i++) MU[i]=(mo+MU[i])%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) {
		for(j=i;j<=1000000;j+=i) {
			D[j].push_back(i);
		}
	}
	
	mobius();
	for(i=1;i<=1000000;i++) {
		FORR(d,D[i]) {
			tmp[d]=mo-dp2[d];
			FORR(d2,D[d]) tmp[d]+=dp[d2];
			tmp[d]=(tmp[d]*2+1)%mo;
			(dp2[d]+=tmp[d])%=mo;
		}
		FORR(d,D[i]) FORR(d2,D[d]) (dp[d]+=tmp[d/d2]*MU[d2])%=mo;
		ret[i]=(ret[i-1]+dp2[i]+mo)%mo;
	}
	
	
	cin>>T;
	while(T--) {
		cin>>x;
		cout<<ret[x]<<"\n";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
