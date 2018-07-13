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
multiset<string> M[202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>x;
		if(x==0) {
			cin>>i>>j;
			while(j--) {
				cin>>s;
				M[i].insert(s);
			}
		}
		else if(x==1) {
			cin>>s;
			FOR(i,21) {
				if(M[i].count(s)) {
					M[i].erase(M[i].find(s));
					break;
				}
			}
			if(i>20) i=-1;
			cout<<i<<endl;
		}
		else if(x==2) {
			cin>>i;
			M[i].clear();
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
