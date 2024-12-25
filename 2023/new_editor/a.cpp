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
ll N,A,B,C;

template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

__int128 floor_sum(ll N,ll M,ll A,ll B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	if(A<0) return floor_sum(N,M,-A,B+(N-1)*A); //A‚ª•‰‚Ìê‡ŒX‚«‚ð‹t‚É‚·‚é
	
	__int128 ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=(__int128)N*(N-1)/2*(A/M), A%=M;
	
	__int128 Y=((__int128)A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)‚É’B‚·‚éX
	__int128 X=Y*M-B;
	//X‚Ì‰E‘¤‚ÍYŒÂ‚¸‚Â
	ret+=(N-(X+A-1)/A)*Y;
	// 90“x‰ñ“]AY=N‚Ìƒ‰ƒCƒ“‚Í–³Ž‹‚·‚é
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B>>C;
		ll y0,z0;
		ll g=ext_gcd(B,C,y0,z0);
		if(y0<0) {
			y0+=C;
			z0-=B;
		}
		C/=g;
		B/=g;
		
		ll m=g/__gcd(g,A);
		ll ret=floor_sum(N/m+1,C,A/__gcd(g,A)*y0,N)-floor_sum(N/m+1,C,A/__gcd(g,A)*y0,C-1)+N/m+1;
		cout<<ret<<endl;
		
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
