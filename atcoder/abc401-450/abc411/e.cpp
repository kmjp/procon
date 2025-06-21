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
int A[101010][6];
const ll mo=998244353;
ll P[101010];
int num[101010];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> As={0};
	vector<pair<int,int>> V;
	FOR(i,N) {
		FOR(j,6) {
			cin>>A[i][j];
			V.push_back({A[i][j],i});
		}
		num[i]=6;
	}
	ll PS=1;
	sort(ALL(V));
	reverse(ALL(V));
	ll ret=0;
	FORR2(v,i,V) {
		ll PS2=PS*6%mo*modpow(num[i]);
		(ret+=PS*modpow(num[i])%mo*v)%=mo;
		PS=PS*(num[i]-1)%mo*modpow(num[i])%mo;
		num[i]--;
	}
	cout<<ret<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
