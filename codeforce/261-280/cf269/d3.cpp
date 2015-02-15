#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,W;
ll A[300000],B[300000];

vector<int> Zalgo(vector<int> s) {
	int l=-1,r=-1,i;
	vector<int> v;
	v.push_back(s.size());
	for(i=1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) cin>>A[i];
	FOR(i,W) cin>>B[i];
	
	if(W==1) return _P("%d\n",N);
	vector<int> V;
	FOR(i,W-1) V.push_back(B[i+1]-B[i]);
	V.push_back(1<<30);
	FOR(i,N-1) V.push_back(A[i+1]-A[i]);
	
	V=Zalgo(V);
	int res=0;
	for(i=W;i<V.size();i++) if(V[i]>=W-1) res++;
	cout << res << endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
