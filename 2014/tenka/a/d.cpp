#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;
 
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
 
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------
 
int N;
int X1[2003],Y1[2003],X2[2003],Y2[2003],X3[2003],Y3[2003];
double D1[2003],D2[2003];
double PI2=atan(1)*8;
double EPS=1e-9;
 
void solve() {
	int f,i,j,k,l,x,y;
	cin>>N;
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
		
		X3[i]=(X1[i]+X2[i]);
		Y3[i]=(Y1[i]+Y2[i]);
		x=__gcd(abs(X1[i]),abs(Y1[i]));
		y=__gcd(abs(X2[i]),abs(Y2[i]));
		D1[i]=atan2(Y1[i]/x,X1[i]/x);
		D2[i]=atan2(Y2[i]/y,X2[i]/y);
		
		if(X1[i]*Y3[i]-Y1[i]*X3[i]<0) swap(D1[i],D2[i]);
		D1[i]-=EPS;
		D2[i]+=EPS;
 
		if(D1[i]<0) D1[i]+=PI2;
		while(D2[i]<D1[i]) D2[i]+=PI2;
	}
	int ret=N;
	FOR(i,N) {
		double xx=D2[i]-EPS;
		vector<pair<double,double> > P;
		FOR(j,N) {
			if(D1[j]<=xx && xx<=D2[j]) continue;
			if(D1[j]<=xx+PI2 && xx+PI2<=D2[j]) continue;
			if(xx<D1[j]) P.push_back(make_pair(D2[j],D1[j]));
			if(D2[j]<xx) P.push_back(make_pair(D2[j]+PI2,D1[j]+PI2));
		}
		if(P.empty()) return _P("1\n");
		sort(P.begin(),P.end());
		
		int num=1;
		x=y=0;
		while(x<P.size()) {
			while(y<P.size() && P[y].second<=P[x].first) y++;
			num++;
			x=y;
		}
		ret=min(num,ret);
	}
	cout<<ret<<endl;
}
 
 
int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}
