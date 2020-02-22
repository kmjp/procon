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


int N,L;
double T,V;
double TV,TT;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	
	deque<pair<double,double>> D;
	
	FOR(i,N) {
		cin>>T>>V;
		
		if(i) {
			double del=V;
			
			while(del>0) {
				if(D.front().second<=del) {
					del -= D.front().second;
					TV -= D.front().second;
					TT -= D.front().first*D.front().second;
					D.pop_front();
				}
				else {
					D.front().second -= del;
					TV -= del;
					TT -= D.front().first*del;
					del = 0;
				}
			}
		}
		
		TV += V;
		TT += T*V;
		_P("%.12lf\n",1.0*TT/TV);
		
		while(D.size() && D.back().first>T) {
			double TTT = T*V + D.back().first*D.back().second;
			V = V + D.back().second;
			T = TTT/V;
			D.pop_back();
		}
		D.push_back({T,V});
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
