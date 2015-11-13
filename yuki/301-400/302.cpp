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

ll N,L,R;

double from[50606],to[50606];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	L=min(6*N,max(N,L));
	R=min(6*N,R);
	
	if(N<=8000) {
		double di=1/6.0;
		ZERO(from);
		from[0]=1;
		FOR(i,N) {
			ZERO(to);
			for(j=i;j<=6*i;j++) for(x=1;x<=6;x++) to[j+x] += from[j]*di;
			swap(from,to);
		}
		_P("%.12lf\n",accumulate(from+L,from+R+1,0.0));
	}
	else {
		double ave=N*3.5;
		double var=N*35.0/12;
		
		_P("%.12lf\n",(erf((R+0.5-ave)/(sqrt(2*var)))-erf((L-0.5-ave)/(sqrt(2*var))))/2);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
