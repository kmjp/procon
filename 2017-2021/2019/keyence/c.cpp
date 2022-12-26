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
int A[101010];
int B[101010];

vector<int> V[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		S-=B[i];
	}
	if(S<0) return _P("-1\n");
	
	FOR(i,N) {
		if(A[i]>B[i]) V[0].push_back(A[i]-B[i]);
		if(A[i]<B[i]) V[1].push_back(B[i]-A[i]);
	}
	
	
	sort(ALL(V[0]));
	V[2]=V[0];
	sort(ALL(V[1]));
	int num=V[0].size()+V[1].size();
	
	while(V[1].size()) {
		x=min(V[0].back(),V[1].back());
		V[0].back()-=x;
		V[1].back()-=x;
		if(V[0].back()==0) V[0].pop_back();
		if(V[1].back()==0) V[1].pop_back();
	}
	
	FOR(i,V[0].size()) if(V[0][i]==V[2][i]) num--;
	cout<<num<<endl;
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
