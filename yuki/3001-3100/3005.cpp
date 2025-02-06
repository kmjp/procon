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

ll X[4],Y[4];

pair<pair<ll,ll>,pair<ll,ll>> circumcenter(ll ax,ll ay,ll bx,ll by,ll cx,ll cy) {
	//äOêSÇóLóùêîÇ≈
	ll A2=(cx-bx)*(cx-bx)+(cy-by)*(cy-by);
	ll B2=(cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
	ll C2=(bx-ax)*(bx-ax)+(by-ay)*(by-ay);
	
	ll px=A2*(B2+C2-A2)*ax+B2*(A2+C2-B2)*bx+C2*(A2+B2-C2)*cx;
	ll py=A2*(B2+C2-A2)*ay+B2*(A2+C2-B2)*by+C2*(A2+B2-C2)*cy;
	ll qx=A2*(B2+C2-A2)+B2*(A2+C2-B2)+C2*(A2+B2-C2);
	ll qy=A2*(B2+C2-A2)+B2*(A2+C2-B2)+C2*(A2+B2-C2);
	
	if(qx==0) {
		return {{-1LL<<60,-1LL<<60},{-1LL<<60,-1LL<<60}};
	}
	ll gx=__gcd(abs(px),abs(qx));
	px/=gx;
	qx/=gx;
	ll gy=__gcd(abs(py),abs(qy));
	py/=gy;
	qy/=gy;
	return {{px,qx},{py,qy}};
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>X[i]>>Y[i];
	auto p=circumcenter(X[0],Y[0],X[1],Y[1],X[2],Y[2]);
	auto q=circumcenter(X[0],Y[0],X[1],Y[1],X[3],Y[3]);
	
	if(p.first.first!=-1LL<<60&&p==q) {
		cout<<"YES"<<endl;
	}
	else {
		cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
