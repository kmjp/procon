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

int Q;
double L,T,P;
multiset<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>Q;
	priority_queue<pair<int,int>> PQ;
	
	FOR(i,Q) {
		cin>>x>>y;
		PQ.push({-x,y});
	}
	
	M.insert(0);
	while(L>0) {
		// next leak;
		double nl=(PQ.size()?-PQ.top().first:1e10);
		// next stop
		double ns=(P>0)?(T+(L-*M.rbegin())/P):1e10;
		
		if(nl==1e10 && ns==1e10) return _P("-1\n");
		if(nl<ns) {
			L-=(nl-T)*P;
			T=nl;
			if(PQ.top().second<L) {
				M.insert(PQ.top().second);
				P++;
			}
			PQ.pop();
		}
		else {
			L=*M.rbegin();
			T=ns;
			M.erase(M.find(*M.rbegin()));
			P--;
		}
	}
	_P("%.12lf\n",T);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
