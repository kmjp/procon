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

ll N,P,Q,R;
ll A,B,C;

template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

template<class V> V rev(V p,V m) { // get p*rev(p)=1 mod m
	assert(__gcd(p,m)==1);
	ll a,b;
	assert(ext_gcd(p,m,a,b)==1);
	a=(a+m)%m;
	return a;
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
	
	cin>>N>>P>>Q>>R;
	cin>>A>>B>>C;
	
	auto X=crt<__int128>(A,P,B,Q);
	auto Y=crt<__int128>(X.first,X.second,C,R);
	
	__int128 a=Y.first;
	__int128 b=Y.second;
	__int128 ret=0;
	if(N>=a) {
		ret=1+(N-a)/b;
	}
	cout<<(ll)ret<<endl;
		
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
