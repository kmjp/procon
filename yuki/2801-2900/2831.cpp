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
int ask(double x,double y) {
	string s;
	cout<< std::fixed << std::setprecision(6)<<1<<" "<<x<<" "<<y<<endl;
	cin>>s>>x>>y;
	if(s=="0"||s=="?") return 0;
	if(s=="-") return -1;
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	double X=0,Y=0;
	
	cin>>N;
	i=ask(0.5,0);
	j=ask(-0.5,0);
	if(i<0) {
		for(i=28;i>=0;i--) {
			j=ask(X+(1<<i),0);
			if(j<=0) X+=(1<<i);
		}
	}
	else if(j<0) {
		for(i=28;i>=0;i--) {
			j=ask(X-(1<<i),0);
			if(j<=0) X-=(1<<i);
		}
	}
	X/=2;
	
	i=ask(0,0.5);
	j=ask(0,-0.5);
	if(i<0) {
		for(i=28;i>=0;i--) {
			j=ask(0,Y+(1<<i));
			if(j<=0) Y+=(1<<i);
		}
	}
	else if(j<0) {
		for(i=28;i>=0;i--) {
			j=ask(0,Y-(1<<i));
			if(j<=0) Y-=(1<<i);
		}
	}
	Y/=2;
	
	cout<< std::fixed << std::setprecision(6)<<2<<" "<<X<<" "<<Y<<" "<<X*X+Y*Y<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
