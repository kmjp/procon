#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

double ask(double ang) {
	double ymax;
	printf("? %.12lf\n", ang);
	fflush(stdout);
	scanf("%lf", &ymax);
	return ymax;
}

void solve() {
	int i,j,k,l,r; string s;
	double deg[2000];
	
	double pi=acos(-1);
	vector<pair<int,int> > V;
	V.emplace_back(0,0);
	
	for(i=0;i<=720;i++) {
		deg[i] = ask(i*0.5);
		if(i<2) continue;
		int cy=V.back().second, cx=V.back().first;
		double dc =i*0.5*pi/180, dp=(i-1)*0.5*pi/180;
		double c1=cos(dc),s1=sin(dc);
		double c2=cos(dp),s2=sin(dp);
		
		double y1=deg[i], y2=deg[i-1];
		if(y1 < cy*c1+cx*s1+0.00001 || y2 < cy*c2+cx*s2+0.00001) continue;
		
		double x,y;
		y=(y1*s2-y2*s1)/(c1*s2-c2*s1);
		x=(y1*c2-y2*c1)/(c2*s1-c1*s2);
		V.emplace_back(floor(x+0.5),floor(y+0.5));
	}
	
	_P("! %d\n",V.size()-1);
	FOR(i,V.size()-1) _P("! %d %d\n",V[V.size()-1-i].first,V[V.size()-1-i].second);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
