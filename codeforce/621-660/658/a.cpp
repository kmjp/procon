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

int H;
int N;
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H;
	while(H--) {
		cin>>N>>S>>T;
		int L=0,R=N-1,F=0;
		vector<int> V;
		for(i=N-1;i>=0;i--) {
			if((S[R]^F)!=T[i]) {
				if((S[L]^F)==T[i]) V.push_back(1);
				V.push_back(abs(R-L)+1);
				swap(L,R);
				F^=1;
			}
			if(L<=R) R--;
			else R++;
		}
		cout<<V.size();
		FORR(v,V) cout<<" "<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
