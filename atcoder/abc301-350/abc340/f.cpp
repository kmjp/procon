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

ll X2,Y2;
__int128 X,Y;
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
	
	cin>>X2>>Y2;
	X=X2;
	Y=Y2;
	
	if(abs(Y2)==1) {
		cout<<"2 0"<<endl;
		return;
	}
	if(abs(Y2)==2) {
		cout<<"1 0"<<endl;
		return;
	}
	if(abs(X2)==1) {
		cout<<"0 2"<<endl;
		return;
	}
	if(abs(X2)==2) {
		cout<<"0 1"<<endl;
		return;
	}
	if(X2==0||Y2==0) {
		cout<<-1<<endl;
		return;
	}
	
	
	
	x=0;
	y=0;
	if(X<0) X=-X,x=1;
	if(Y<0) Y=-Y,y=1;
	
	if(__gcd(abs(X2),abs(Y2))>2) {
		cout<<-1<<endl;
	}
	else if(__gcd(abs(X2),abs(Y2))==1) {
		__int128 x2,y2;
		auto p=ext_gcd(Y,X,x2,y2);
		x2=2*x2;
		y2=2*y2;
		y2=-y2;
		if(y) x2=-x2;
		if(x) y2=-y2;
		assert(X2*y2-Y2*x2==2||X2*y2-Y2*x2==-2);
		cout<<(ll)x2<<" "<<(ll)y2<<endl;
	}
	else if(__gcd(abs(X2),abs(Y2))==2) {
		__int128 x2,y2;
		auto p=ext_gcd(Y/2,X/2,x2,y2);
		y2=-y2;
		if(y) x2=-x2;
		if(x) y2=-y2;
		assert(X2*y2-Y2*x2==2||X2*y2-Y2*x2==-2);
		cout<<(ll)x2<<" "<<(ll)y2<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
