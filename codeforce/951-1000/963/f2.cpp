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
ll N,H,W;
ll K;
string S;

int Y[1010101],X[1010101];

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


ll hoge(ll a,ll b,ll v) {
	// a+bx % v==0Ç∆Ç»ÇÈç≈è¨ÇÃxÇ∆ä‘äu
	a=(v-a)%v;
	ll g=__gcd(b,v);
	if(a%g) return 1LL<<60;
	a/=g;
	b/=g;
	v/=g;
	// bx=aÇ»ÇÃÇ≈bÇÃãtêî
	ll rb=rev(b,v);
	return __int128(a)*rb%v;
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K>>W>>H;
		K--;
		cin>>S;
		FOR(i,N) {
			Y[i+1]=Y[i];
			X[i+1]=X[i];
			if(S[i]=='L') X[i+1]--;
			if(S[i]=='R') X[i+1]++;
			if(S[i]=='U') Y[i+1]++;
			if(S[i]=='D') Y[i+1]--;
			X[i+1]=(X[i+1]+2*W)%(2*W);
			Y[i+1]=(Y[i+1]+2*H)%(2*H);
		}
		
		ll DY=Y[N];
		ll DX=X[N];
		ll gx=__gcd(2*W,DX);
		ll w=2*W/gx;
		ll gy=__gcd(2*H,DY);
		ll h=2*H/gy;
		
		ll ret=0;
		FOR(i,N) {
			ll ax=X[i+1];
			ll ay=Y[i+1];
			
			ll cx=hoge(ax,DX,2*W);
			ll cy=hoge(ay,DY,2*H);
			if(cx>K) continue;
			if(cy>K) continue;
			
			ll r=hoge((-(cy-cx)%h+h)%h,w%h,h);
			if(r>K/w+1) continue;
			ll v=cx+r*w;
			if(v<=K) ret+=(K-v)/(w*h/__gcd(w,h))+1;
			
			
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
