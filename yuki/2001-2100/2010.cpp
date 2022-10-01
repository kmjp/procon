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

int T,N;
ll H[101],A[101];
double X;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		X/=2;
		FOR(i,N) cin>>H[i+1];
		FOR(i,N) cin>>A[i];
		
		
		double ret=A[0]*X;
		ll mi=A[0];
		for(i=1;i<N;i++) {
			if(A[i]>=mi) continue;
			mi=min(mi,A[i]);
			double SX=0,tim=0;
			FOR(j,i) {
				double c=A[i]*1.0/A[j];
				double s=sqrt(1-c*c);
				if(c==0) {
					tim+=(H[j+1]-H[j])*A[j];
				}
				else {
					double t=s/c;
					SX+=(H[j+1]-H[j])/t;
					tim+=(H[j+1]-H[j])/s*A[j];
				}
			}
			if(SX<=X) {
				tim+=(X-SX)*A[i];
				ret=min(ret,tim);
			}
		}
		
		_P("%.12lf\n",ret*2);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
