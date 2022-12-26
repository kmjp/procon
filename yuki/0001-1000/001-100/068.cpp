#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll L[300000];
int num[500005];
double res[500005];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	priority_queue<pair<double,int> > P;
	
	FOR(i,N) cin>>L[i], P.push(make_pair(L[i],i));
	
	for(i=1;i<=500000;i++) {
		res[i] = P.top().first;
		j=P.top().second;
		P.pop();
		num[j]++;
		P.push(make_pair(L[j]/(num[j]+1.0),j));
	}
	
	cin>>Q;
	while(Q--) cin>>x, _P("%.12lf\n",res[x]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
