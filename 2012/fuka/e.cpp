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
int X[505050];
long double prob[505050];
long double num[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	while(1) {
		cin>>N;
		if(N==0) return;
		FOR(i,N) cin>>X[i];
		FOR(i,10) X[N+i]=N-1;
		if(N==1) {
			_P("0\n");
			continue;
		}
		for(i=N-1;i>=0;i--) {
			if(X[i]>0) {
				if(i+X[i]>=N-1) X[i]=N-1;
				else X[i]=X[i+X[i]];
			}
			else if(X[i]==0) X[i]=i;
			else if(X[i]<0) X[i]=0;
		}
		FOR(i,N+10) prob[i]=num[i]=0;
		prob[0]=1;
		num[0]=0;
		FOR(i,N-1) if(prob[i]) {
			num[i] /= prob[i];
			long double pp=prob[i];
			long double pn=num[i]+1;
			for(x=1;x<=6;x++) {
				prob[X[i+x]] += pp/6.0;
				num[X[i+x]] += pp/6.0 * pn;
			}
		}
		
		long double ret = num[N-1]/prob[N-1];
		if(--prob[0]>0) {
			num[0]/=prob[0];
			ret += num[0]*prob[0]/prob[N-1];
		}
		_P("%.12lf\n",(double)ret);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
