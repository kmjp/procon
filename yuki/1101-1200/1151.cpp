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

int N;
double V[11];

double win[1<<10][1<<10][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>V[i];
	
	FOR(i,1<<N) {
		int sum=0;
		FOR(j,N) {
			if(i&(1<<j)) sum+=V[j];
			else sum-=V[j];
		}
		if(sum>0) win[i][i^((1<<N)-1)][0]=win[i][i^((1<<N)-1)][1]=1;
	}
	
	for(int left=1;left<1<<N;left++) {
		int take=((1<<N)-1)^left;
		for(int A=take;A>=0;A--) {
			A&=take;
			int B=take^A;
			win[A][B][1]=1;
			
			FOR(i,N) if(left&(1<<i)) {
				double mi=1;
				FOR(j,N) if(left&(1<<j)) {
					double a=1-(1-1/V[i])*(1-1/V[j]);
					double b=1/V[i]*win[A|(1<<i)][B][1]+(1-1/V[i])*(1/V[j]*win[A][B|(1<<j)][0]);
					mi=min(mi,b/a);
				}
				win[A][B][0]=max(win[A][B][0],mi);
				double ma=0;
				FOR(j,N) if(left&(1<<j)) {
					double a=1-(1-1/V[i])*(1-1/V[j]);
					double b=1/V[i]*win[A][B|(1<<i)][0]+(1-1/V[i])*(1/V[j]*win[A|(1<<j)][B][1]);
					ma=max(ma,b/a);
				}
				win[A][B][1]=min(win[A][B][1],ma);
			}
		}
	}
	
	_P("%.12lf\n",win[0][0][0]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
