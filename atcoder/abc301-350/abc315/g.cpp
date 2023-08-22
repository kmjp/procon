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

ll N,A,B,C,X;


template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

template<class V> pair<V,V> crt(V a1,V mo1,V a2,V mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	V g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<V,V>(-1,0); // N/A
	V lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<V,V>(-2,0); // overflow
	
	V v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C>>X;
	X-=A+B+C;
	ll ret=0;
	FOR(i,N) {
		__int128 V=X-1LL*i*A;
		if(V<0) continue;
		ll g=__gcd(B,C);
		if(V%g) continue;
		__int128 B2=B/g;
		__int128 C2=C/g;
		V/=g;
		auto p=crt((__int128)0,C2,V%B2,B2);
		__int128 mic=p.first/C2%B2;
		assert(p.first%C2==0);
		assert((V-p.first)%B2==0);
		__int128 b=(V-p.first)/B2;
		if(b<0) continue;
		assert((V-b*B2)%C2==0);
		
		ll pat=0;
		__int128 mac=min((__int128)N-1,mic+(V-mic*C2)/(B2*C2)*B2);
		if(b>=N) {
			b-=(b-(N-1)+C2-1)/C2*C2;
			mic=(V-b*B2)/C2;
		}
		//cout<<i<<" "<<(ll)mic<<" "<<(ll)mac<<endl;
		if(mic<=mac) ret+=(mac-mic)/B2+1;
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
