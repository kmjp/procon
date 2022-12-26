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


int leap(int Y) {
	return (Y%400==0) || ((Y%100) && (Y%4==0));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<int> V;
	
	for(int i=2019;i<=9999;i++) {
		int A[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		if(leap(i)) A[2]++;
		for(x=1;x<=12;x++) {
			V.push_back(i*10000+x*100+1);
			V.push_back(i*10000+x*100+A[x]);
		}
	}
	
	int ma=0;
	int v=0;
	FOR(i,V.size()/2-1) {
		if(__gcd(V[i*2+1],V[i*2+2])>ma) {
			ma=__gcd(V[i*2+1],V[i*2+2]);
			v=V[i*2+1];
		}
	}
	cout<<v<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
