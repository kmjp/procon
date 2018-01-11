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

int ask(vector<int> V) {
	cout<<"Q "<<V.size();
	FORR(v,V) cout<<" "<<(v+1);
	cout<<endl;
	
	int a;
	cin>>a;
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	vector<int> X,Y;
	FOR(i,15) {
		vector<int> A[2];
		FOR(x,N) A[(x>>i)&1].push_back(x);
		int a[2]={ask(A[0]),ask(A[1])};
		
		if(a[0]==A[0].size() && a[1]==0) {
			X=A[0];
			Y=A[1];
			break;
		}
		if(a[0]==0 && a[1]==A[1].size()) {
			X=A[1];
			Y=A[0];
			break;
		}
	}
	assert(X.size()+Y.size()==N);
	
	int RA=X.size()-1,RB=Y.size()-1;
	for(i=15;i>=0;i--) {
		if(RA-(1<<i)>=0) {
			vector<int> Z=Y;
			FOR(j,RA-(1<<i)+1) Z.push_back(X[j]);
			if(ask(Z)) RA-=1<<i;
		}
		if(RB-(1<<i)>=0) {
			vector<int> Z=X;
			FOR(j,RB-(1<<i)+1) Z.push_back(Y[j]);
			if(ask(Z)!=Z.size()) RB-=1<<i;
		}
	}
	
	cout<<"A "<<(X[RA]+1)<<" "<<(Y[RB]+1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
