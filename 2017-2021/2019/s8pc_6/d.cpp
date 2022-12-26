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
pair<int,double> P[101010];
double L[101010],R[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	double ma=0;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		ma=max(ma,P[i].second);
	}
	sort(P,P+N);
	
	L[0]=P[0].second;
	for(i=1;i<N;i++) {
		if(L[i-1]<P[i].first-P[i-1].first) {
			L[i]=P[i].second;
		}
		else {
			double a=L[i-1]-(P[i].first-P[i-1].first);
			L[i]=pow(a*a*a+1.0*P[i].second*P[i].second*P[i].second,1.0/3.0);
		}
		ma=max(ma,L[i]);
	}
	R[N-1]=P[N-1].second;
	for(i=N-2;i>=0;i--) {
		if(R[i+1]<P[i+1].first-P[i].first) {
			R[i]=P[i].second;
		}
		else {
			double a=R[i+1]-(P[i+1].first-P[i].first);
			R[i]=pow(a*a*a+1.0*P[i].second*P[i].second*P[i].second,1.0/3.0);
			ma=max(ma,pow(a*a*a+1.0*L[i]*L[i]*L[i],1.0/3.0));
		}
	}
	_P("%.12lf\n",ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
