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

ll N;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	while(N) {
		V.push_back(N%2);
		N>>=1;
	}
	V.pop_back();
	reverse(V.begin(),V.end());
	int last=(V.size()-1)%2;
	bool ret;
	
	if(V.size()%2==0) {
		ret=false;
		FOR(i,V.size()) {
			if(i%2==0 && V[i]==0) {
				ret=true;
				break;
			}
			if(i%2==1 && V[i]==1) {
				ret=false;
				break;
			}
		}
	}
	else {
		ret=true;
		FOR(i,V.size()) {
			if(i%2==0 && V[i]==1) {
				ret=true;
				break;
			}
			if(i%2==1 && V[i]==0) {
				ret=false;
				break;
			}
		}
	}
	
	if(ret) _P("Takahashi\n");
	else _P("Aoki\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
