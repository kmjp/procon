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
map<string,int> M;
set<string> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		M[s]++;
		
		if(M[s]>1) {
			cout<<s<<" "<<M[s]<<endl;
		}
		else {
			for(j=1;j<=s.size();j++) {
				string t=s.substr(0,j);
				if(S.count(t)==0) {
					cout<<t<<endl;
					break;
				}
			}
			if(j>s.size()) {
				cout<<s<<endl;
			}
			for(j=1;j<=s.size();j++) {
				string t=s.substr(0,j);
				S.insert(t);
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
