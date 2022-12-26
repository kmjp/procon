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
ll X[505050],Y[505050];

map<ll,ll> L,R;
vector<ll> A,B;
ll lef[505050],ri[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>Y[i];
	FOR(i,N) {
		if(L.count(Y[i])) L[Y[i]]=min(L[Y[i]],X[i]);
		else L[Y[i]]=X[i];
		if(R.count(Y[i])) R[Y[i]]=max(R[Y[i]],X[i]);
		else R[Y[i]]=X[i];
	}
	FORR(m,L) A.push_back(m.second);
	FORR(m,R) B.push_back(m.second);
	lef[0]=A[0];
	for(i=1;i<A.size();i++) lef[i]=min(lef[i-1],A[i]);
	ri[A.size()-1]=A[A.size()-1];
	for(i=(int)A.size()-2;i>=0;i--) ri[i]=min(ri[i+1],A[i]);
	FOR(i,A.size()) A[i]=max(lef[i],ri[i]);

	lef[0]=B[0];
	for(i=1;i<B.size();i++) lef[i]=max(lef[i-1],B[i]);
	ri[B.size()-1]=B[B.size()-1];
	for(i=(int)B.size()-2;i>=0;i--) ri[i]=max(ri[i+1],B[i]);
	
	ll ret=-N;
	FOR(i,B.size()) {
		B[i]=min(lef[i],ri[i]);
		ret+=B[i]-A[i]+1;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
