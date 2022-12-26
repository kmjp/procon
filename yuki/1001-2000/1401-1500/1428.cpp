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

int N;
int P[101010];
int num[101010];
const ll mo=1000000007;
int vis[101010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll fact=1;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		fact=fact*(i+1)%mo;
	}
	ll ret=1;
	FOR(i,N) if(vis[i]==0) {
		x=i;
		y=0;
		while(vis[x]==0) {
			y++;
			vis[x]=1;
			x=P[x];
		}
		ret=ret*y%mo;
		num[y]++;
		ret=ret*num[y]%mo;
	}
	
	int ok=0;
	FOR(i,N) {
		if(num[i]>0&&i%2==0) ok=1;
		if(num[i]>1) ok=1;
	}
	if(num[N]) ok=1;
	if(ok==0) ret*=2;
	cout<<fact*modpow(ret)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
