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

int N;
ll R,X[300003],Y[300003];
double dx,dy,r;

void solve() {
	int i,j,k,l,x,y; string s;
	
	cin>>N>>r;
	R=r*2000+0.1;
	
	map<pair<ll,ll>,int> M;
	int cnt=0;
	FOR(i,N) {
		cin>>dx>>dy;
		X[i]=dx*2000+2000000000.1;
		Y[i]=dy*2000+2000000000.1;
		X[i]/=R;
		Y[i]/=R;
		j=0;
		for(x=-1;x<=1;x++) for(y=-1;y<=1;y++) if(M.count(make_pair(X[i]+x,Y[i]+y))) j++;
		if(j==0) cnt++, M[make_pair(X[i],Y[i])]=i;
	}
	cout<<cnt<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
