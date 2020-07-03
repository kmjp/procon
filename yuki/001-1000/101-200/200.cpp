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

int N,A,C;
vector<int> BB,DD,B,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	FOR(i,A) cin>>x, BB.push_back(x);
	cin>>C;
	FOR(i,C) cin>>x, DD.push_back(x);
	
	int ret=0;
	while(N--) {
		if(B.empty()) B=BB;
		if(D.empty()) D=DD;
		sort(B.begin(),B.end());
		sort(D.begin(),D.end());
		int win=0;
		FOR(x,B.size()) {
			for(y=D.size()-1;y>=0;y--) if(B[x]>D[y]) {
				ret++;
				win=1;
				B.erase(B.begin()+x);
				D.erase(D.begin()+y);
				break;
			}
			if(win) break;
		}
		if(!win) {
			B.erase(B.begin());
			D.erase(D.begin()+D.size()-1);
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
