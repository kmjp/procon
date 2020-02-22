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

ll XS,YS,XT,YT;
int N;
double X[5050],Y[5050],R[5050];
double D[5050];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>X[1]>>Y[1];
	R[0]=R[1]=0;
	cin>>N;
	FOR(i,N) {
		cin>>X[i+2]>>Y[i+2]>>R[i+2];
	}
	N+=2;
	for(i=1;i<N;i++) D[i]=1e15;
	
	priority_queue<pair<double,int>> P;
	P.push({0,0});
	
	while(P.size()) {
		double cost=-P.top().first;
		int cur=P.top().second;
		P.pop();
		if(cost!=D[cur]) continue;
		
		FOR(i,N) if(i!=cur) {
			double d=hypot(X[i]-X[cur],Y[i]-Y[cur])-R[i]-R[cur];
			if(d<0) d=0;
			if(D[i]>D[cur]+d) {
				D[i]=D[cur]+d;
				P.push({-D[i],i});
			}
		}
	}
	
	
	_P("%.12lf\n",D[1]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
