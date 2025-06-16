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

ll R,GX,GY;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>GX>>GY;
	double a=(R-hypot(GX,GY))/2;
	double b=R-3*a+2*R-3*a;
	
	if(abs(b)<1e-9) {
		cout<<"0 0"<<endl;
	}
	else {
		double r=hypot(GX,GY);
		double gx=GX/r;
		double gy=GY/r;
		_P("%.12lf %.12lf\n",b*gx,b*gy);
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
