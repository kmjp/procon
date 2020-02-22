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
int did[26];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	
	if(S.size()<26) {
		FORR(c,S) did[c-'a']=1;
		FOR(i,26) if(did[i]==0) {
			S+=(char)('a'+i);
			break;
		}
	}
	else {
		for(j=25;j>=0;j--) {
			char c='z'+1;
			x=-1;
			for(i=j+1;i<26;i++) {
				if(S[i]>S[j]&&S[i]<c) {
					x=i;
					c=S[i];
				}
			}
			if(x>j) {
				swap(S[j],S[x]);
				S.resize(j+1);
				break;
			}
		}
		if(j<0) return _P("-1\n");
	}
	cout<<S<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
