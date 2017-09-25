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
string S;
vector<int> V[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int ma=0;
	FOR(i,N) V[S[i]].push_back(i);
	
	FOR(i,256) V[i].push_back(N), ma=max(ma,(int)V[i].size());
	string ret;
	FOR(i,256) if(V[i].size()==ma) {
		int len;
		for(len=2;;len++) {
			FOR(j,V[i].size()-1) {
				if(V[i][j]+len>V[i][j+1]) break;
				if(S[V[i][j]+len-1]!=S[V[i][0]+len-1]) break;
			}
			if(j!=V[i].size()-1) {
				len--;
				break;
			}
		}
		string cand=S.substr(V[i][0],len);
		if(cand.size()>ret.size()) ret=cand;
		
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
