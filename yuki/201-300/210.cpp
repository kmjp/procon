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
int P[1010],Q[1010];
double ret;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i];
	
	priority_queue<pair<double,int> > PQ;
	FOR(i,N) PQ.push(make_pair(P[i]*Q[i]/100000.0,i));
	
	FOR(i,1000000) if(PQ.size()) {
		auto r=PQ.top();
		PQ.pop();
		
		ret += (i+1)*r.first;
		PQ.push(make_pair(r.first * (1-Q[r.second]/100.0),r.second));
	}
	
	_P("%.7lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
