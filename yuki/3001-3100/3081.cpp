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

map<ll,int> enumpr(ll n) {
	map<ll,int> V;
	for(ll i=2;i*i<=n;i++) while(n%i==0) V[i]++,n/=i;
	if(n>1) V[n]++;
	return V;
}

ll totient(ll v) {
	ll ret=v;
	for(ll i=2;i*i<=v;i++) if(v%i==0) {
		ret=ret/i*(i-1);
		while(v%i==0) v/=i;
	}
	if(v>1) ret=ret/v*(v-1);
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	auto M=enumpr(N);
	
	x=M[2];
	y=M[5];
	M.erase(2);
	M.erase(5);
	if(x==0&&y==0) {
		N=totient(N);
		cout<<1<<endl;
		cout<<"9 "<<N<<endl;
		return;
	}
	else {
		string S;
		ll a=1;
		FOR(i,x) a=a*2;
		FOR(i,y) a=a*5;
		S="0000000000000000000000000000000000000000000000000000000000000000000000"+to_string(a);
		S=S.substr(S.size()-(x+y));
		S=S+S;
		reverse(S.begin(),S.begin()+x+y);
		ll num=1;
		FORR2(a,b,M) {
			ll cur=1;
			FOR(i,2*(x+y)) cur=cur*10%a;
			if(cur==1) {
				FOR(i,b) num*=a;
			}
			else {
				num*=a-1;
				FOR(i,b-1) num*=a;
			}
		}
		cout<<1<<endl;
		cout<<S<<" "<<num<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
