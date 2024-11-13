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
ll D,X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>D>>X>>Y;
		
		if(X==0) {
			cout<<Y*D<<endl;
		}
		else if(Y==0) {
			cout<<X*D<<endl;
		}
		else {
			ll dy=X;
			ll dx=Y;
			ll g=__gcd(X,Y);
			dx/=g;
			dy/=g;
			ll ret=0;
			ll can1=min((D-Y)/dy,X/dx);
			ll can2=min(Y/dy,(D-X)/dx);
			ll TY1=Y+can1*dy;
			ll TX1=X-can1*dx;
			ll TY2=Y-can2*dy;
			ll TX2=X+can2*dx;
			ret=max(abs(X*TY1-Y*TX1),abs(X*TY2-Y*TX2));
			
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
