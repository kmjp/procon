#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

double C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>C>>D;
	
	double L=0,R=min(C/0.75,D/0.25);
	
	FOR(i,200) {
		double M1=(L*2+R)/3;
		double M2=(L+R*2)/3;
		double r1= M1*1000 + min((C-M1*0.75)/(2.0/7.0),(D-M1*0.25)/(5.0/7.0))*2000;
		double r2= M2*1000 + min((C-M2*0.75)/(2.0/7.0),(D-M2*0.25)/(5.0/7.0))*2000;
		if(r1>r2) R=M2;
		if(r1<r2) L=M1;
		if(r1==r2) L=M1,R=M2;
	}
	double ret = L*1000 + min((C-L*0.75)/(2.0/7.0),(D-L*0.25)/(5.0/7.0))*2000;
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
