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
int X[10],Y[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,N) {
		V.push_back(i);
		cin>>X[i]>>Y[i];
	}
	double ret=0;
	int pat=0;
	do {
		FOR(i,N-1) {
			ret+=hypot(X[V[i]]-X[V[i+1]],Y[V[i]]-Y[V[i+1]]);
		}
		pat++;
		
	} while(next_permutation(ALL(V)));
	ret/=pat;
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
