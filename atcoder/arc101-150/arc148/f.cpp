#include <bits/stdc++.h>
using namespace std;


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

typedef unsigned long long ll;

const ll N=1000000007;
const ll R=998244353;
ll NR,S;
ll A,B,N2;
vector<string> V;

__int128 modpow(__int128 a, __int128 n, __int128 mo) {
	__int128 r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll add(ll a, ll b) {
	__int128 c=a;
	c+=b;
	return (ll)c;
}
ll mul(ll a, ll b) {
	__int128 c=a;
	c*=b;
	return (ll)c;
}
ll rem(ll a) {
	return a%R;
}

ll reduce(ll v) {
	ll a=(v+v%R*NR%R*N)/R;
	return a;
}
void reduce_s(string s) {
	V.push_back("add D "+s+" 0");
	V.push_back("rem "+s+" "+s+"");
	V.push_back("mul "+s+" "+s+" "+to_string(NR));
	V.push_back("rem "+s+" "+s+"");
	V.push_back("mul "+s+" "+s+" "+to_string(N));
	V.push_back("add D D "+s+"");
	V.push_back("mul "+s+" D "+to_string(S));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	__int128 a=1,b=1;
	a<<=63;
	b<<=64;
	a-=1;
	S=modpow(R,a,b);
	NR=R-modpow(N,R-2,R);
	
	
	cin>>A>>B;
	//cout<<(A*B)%N<<endl;
	
	ll R2=R*R%N;
	//A*=R2;
	//B*=R2;
	A=mul(A,R2);
	V.push_back("mul A A "+to_string(R2));
	B=mul(B,R2);
	V.push_back("mul B B "+to_string(R2));
	
	A=reduce(A);
	reduce_s("A");
	B=reduce(B);
	reduce_s("B");
	
	ll C=A*B;
	V.push_back("mul C A B");
	C=reduce(C);
	C=reduce(C);
	reduce_s("C");
	reduce_s("C");
	C=C*R2;
	V.push_back("mul C C "+to_string(R2));
	C=reduce(C);
	reduce_s("C");
	C=reduce(C);
	reduce_s("C");
	
	
	
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
