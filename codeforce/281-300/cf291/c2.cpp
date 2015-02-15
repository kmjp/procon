#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
string S[400000];
string T;
set<string> SS[340000];
vector<string> VV[340000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	
	FOR(i,N) {
		cin>>S[i];
		if(S[i].size()>300000) continue;
		SS[S[i].size()].insert(S[i]);
		VV[S[i].size()].push_back(S[i]);
	}
	while(M--) {
		cin>>T;
		bool ok=false;
		
		if(T.size()<300) {
			FOR(i,T.size()) {
				char org=T[i];
				FOR(x,3) {
					if(x+'a'==org) continue;
					T[i]=x+'a';
					ok |= SS[T.size()].count(T);
				}
				T[i]=org;
			}
			
		}
		else if(T.size()<=300000) {
			FOR(i,VV[T.size()].size()) {
				string& V=VV[T.size()][i];
				int dif=0;
				FOR(x,V.size()) {
					dif += V[x]!=T[x];
					if(dif>1) break;
				}
				ok |= dif==1;
			}
		}
		
		cout << (ok?"YES":"NO") << endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
