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

int N,T;
double P[2];
int A[30],B[30];
int win,tot;

vector<int> getrandvec(double p) {
	int i,x;
	vector<int> v,r;
	FOR(i,N) v.push_back(i);
	FOR(i,N-1) {
		double d = rand()*1.0/RAND_MAX;
		if(d<p) x=0;
		else x=1+(N-1-i)*(d-p)/(1-p);
		
		r.push_back(v[x]);
		v.erase(v.begin()+x);
	}
	r.push_back(v[0]);
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P[0]>>P[1];
	FOR(i,N) cin>>A[i], T+=A[i];
	FOR(i,N) cin>>B[i], T+=B[i];
	sort(A,A+N);
	sort(B,B+N);
	
	srand(time(NULL));
	
	FOR(i,200000) {
		tot++;
		vector<int> VA,VB;
		VA=getrandvec(P[0]);
		VB=getrandvec(P[1]);
		x=0;
		FOR(y,N) if(A[VA[y]]>B[VB[y]]) x+=A[VA[y]]+B[VB[y]];
		if(x>T/2) win++;
	}
	
	_P("%.12lf\n",1.0*win/tot);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
