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

long double a,b,c;
ll X,Y,R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>a>>b>>c;
	X=round(a*10000);
	Y=round(b*10000);
	X+=2000000000LL;
	Y+=2000000000LL;
	X%=10000;
	X+=1100000000LL;
	Y%=10000;
	Y+=1100000000LL;
	R=round(c*10000);
	ll ret=0;
	ll H=1LL<<60,L=1LL<<60;
	
	for(ll x=0;x<=220000;x++) {
		
		ll d=abs(x*10000-X);
		if(d>R) continue;
		if(H==1LL<<60) H=L=Y/10000*10000;
		
		while((H+10000-Y)*(H+10000-Y)+d*d <= R*R) H+=10000;
		while((H-Y)*(H-Y)+d*d > R*R && H>=Y) H-=10000;
		while((L-Y)*(L-Y)+d*d <= R*R) L-=10000;
		while((L+10000-Y)*(L+10000-Y)+d*d > R*R && L+10000<=Y) L+=10000;
		ret+=H/10000-L/10000;
		
		
	}
	
	
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
