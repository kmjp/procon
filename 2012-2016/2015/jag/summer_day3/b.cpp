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

string S;
int N;
vector<int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	C.push_back(0);
	FOR(i,N) if(i && S[i]=='1') C.push_back(i);
	int num=(C.size()-(S[0]=='0'))*4;
	
	if(num==0) return _P("0\n");
	int mi=1<<25;
	
	mi=C.back();
	if(C.size()>=2) mi=min(mi,N-C[1]);
	FOR(i,C.size()) if(i>=1 && i<C.size()-1) {
		mi=min(mi,2*C[i]+N-C[i+1]);
		mi=min(mi,C[i]+2*(N-C[i+1]));
	}
	cout<<mi*7+num<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
