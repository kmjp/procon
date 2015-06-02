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

int N,L;
double X[1010],V[1010],R[1010];
int ok[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) cin>>X[i]>>V[i];
	double ret=0;
	
	if(N==1) {
		ret=L*1.0/V[0];
	}
	else {
		int cur=0;
		while(1) {
			int ne=(cur+1)%N;
			
			if(X[ne]<=X[cur]) X[cur] -= L;
			double run=X[ne]-X[cur];
			if(count(ok,ok+N,1)==N-1 && ok[cur]==0 && R[cur]+run>=L) {
				run = L-R[cur];
				ret+=run*1.0/V[0];
				break;
			}
			
			ret+=run*1.0/V[cur];
			R[cur]+=run;
			if(R[cur]>=L) ok[cur]=1;
			X[cur]=X[ne];
			cur=ne;
		}
	}
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
