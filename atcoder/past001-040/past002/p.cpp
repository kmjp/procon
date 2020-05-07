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

int N,M,K;
ll A[1010101];
ll S, D[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	vector<ll> V;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		D[i]=M-2*A[i];
		if(D[i]) {
			if(V.empty()) {
				V.push_back(D[i]);
			}
			else if((V.back()<0) ^ (D[i]<0)) {
				V.push_back(D[i]);
			}
			else {
				V.back()+=D[i];
			}
		}
	}
	
	if(V.size() && V.back()<0) V.pop_back();
	if(V.size() && V[0]<0) V.erase(V.begin());
	FORR(d,V) cout<<d<<" ";
	cout<<endl;
	
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
