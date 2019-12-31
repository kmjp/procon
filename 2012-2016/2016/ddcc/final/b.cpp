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

int R,N,M;
double L[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>N>>M;
	for(i=1;i<=N-1;i++) {
		double H=2.0*i/N;
		L[i]=2*R*sqrt(1-(H-1)*(H-1));
	}
	double ret=0;
	while(1) {
		x = max_element(L+1,L+N)-L;
		if(L[x]==0) break;
		
		if(x>N/2) {
			for(y=x-M;y>=1;y--) if(L[y]>0) {
				L[y]=0;
				break;
			}
		}
		else {
			for(y=x+M;y<N;y++) if(L[y]>0) {
				L[y]=0;
				break;
			}
		}
		ret += L[x];
		L[x] = 0;
		
	}
	
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
