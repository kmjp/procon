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
int T[202];
double V[202];
double M[50000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int sum=0;
	FOR(i,50000) M[i]=2020;
	
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>V[i];
	FOR(i,N){ 
		T[i]*=2;
		for(x=sum;x<=sum+T[i];x++) M[x]=min(M[x],V[i]);
		sum+=T[i];
	}
	M[0]=M[sum]=0;
	FOR(j,200) {
		FOR(i,sum) M[i+1]=min(M[i+1],M[i]+0.5);
		for(i=sum-1;i>=0;i--) M[i]=min(M[i],M[i+1]+0.5);
	}
	double R=0;
	FOR(i,sum) R+=M[i]+M[i+1];
	_P("%.12lf\n",R/4.0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
