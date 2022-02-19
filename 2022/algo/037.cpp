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

int ins(int a,int b,int c) {
	if(X[a]==X[c]&&Y[a]==Y[c]) return 1;
	if(X[b]==X[c]&&Y[b]==Y[c]) return 1;
	ll ax=X[a]-X[c];
	ll ay=Y[a]-Y[c];
	ll bx=X[b]-X[c];
	ll by=Y[b]-Y[c];
	
	if(ax*by-bx*ay) return 0;
	if(ax*bx+ay*by<0) return 1;
	return 0;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) {
		cin>>X[i]>>Y[i];
	}
	
	int mask=0;
	{
		ll dx=X[1]-X[0];
		ll dy=Y[1]-Y[0];
		ll dx1=X[2]-X[0];
		ll dy1=Y[2]-Y[0];
		ll dx2=X[3]-X[0];
		ll dy2=Y[3]-Y[0];
		
		if(dx1*dy-dy1*dx<0&&dx2*dy-dy2*dx<0) return _P("No\n");
		if(dx1*dy-dy1*dx>0&&dx2*dy-dy2*dx>0) return _P("No\n");
		if(dx1*dy-dy1*dx==0||dx2*dy-dy2*dx==0) mask=1;
		
	}
	{
		ll dx=X[3]-X[2];
		ll dy=Y[3]-Y[2];
		ll dx1=X[1]-X[2];
		ll dy1=Y[1]-Y[2];
		ll dx2=X[0]-X[2];
		ll dy2=Y[0]-Y[2];
		
		if(dx1*dy-dy1*dx<0&&dx2*dy-dy2*dx<0) return _P("No\n");
		if(dx1*dy-dy1*dx>0&&dx2*dy-dy2*dx>0) return _P("No\n");
		if(dx1*dy-dy1*dx==0||dx2*dy-dy2*dx==0) mask=1;
	}
	
	if(ins(0,1,2)) return _P("Yes\n");
	if(ins(0,1,3)) return _P("Yes\n");
	if(ins(2,3,0)) return _P("Yes\n");
	if(ins(2,3,1)) return _P("Yes\n");
	if(mask) {
		cout<<"No"<<endl;
	}
	else {
		cout<<"Yes"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
