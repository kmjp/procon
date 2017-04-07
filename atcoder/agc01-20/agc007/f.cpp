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
string S,T;
deque<int> Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	
	if(S==T) return _P("0\n");
	
	int R=N-1;
	int ma=0;
	int dif=0;
	for(i=N-1;i>=0;i--) {
		if(i==0 || T[i]!=T[i-1]) {
			R=min(i,R);
			while(R>=0 && T[i]!=S[R]) R--;
			if(R<0) return _P("-1\n");
			
			if(i==R) {
				Q.clear();
			}
			else {
				if(Q.empty()) dif=0;
				else dif++;
				Q.push_back(R+dif);
			}
			
			R--;
		}
		
		ma=max(ma,(int)Q.size()+1);
		if(Q.size() && Q.front()-dif>=i) Q.pop_front();
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
