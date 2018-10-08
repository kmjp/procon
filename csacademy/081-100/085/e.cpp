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

int te,N;
string S,T;
int C[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>te;
	while(te--) {
		cin>>S;
		T=S;
		N=S.size();
		C[N]=0;
		for(i=N-1;i>=0;i--) {
			C[i]=C[i+1]+(S[i]==')');
		}
		
		int cur=0;
		FOR(i,N) T[i]='B';
		FOR(i,N) {
			if(S[i]=='(') {
				if(C[i]>=cur+1) cur++;
			}
			else {
				if(cur>0) cur--, T[i]='R';
			}
		}
		cur=0;
		FOR(i,N) C[i]=(i?C[i-1]:0)+(S[i]=='(');
		for(i=N-1;i>=0;i--) {
			if(S[i]==')') {
				if(C[i]>=cur+1) cur++;
			}
			else {
				if(cur>0) cur--, T[i]='R';
			}
		}
		
		
		int ng=0;
		vector<int> cand;
		for(i=N-1;i>=0;i--) {
			if(T[i]=='R' && S[i]==')') {
				cand.push_back(i);
			}
			if(T[i]=='B' && S[i]=='(') {
				if(cand.size()) {
					T[cand.back()]='G';
					cand.pop_back();
				}
				else {
					ng=1;
				}
			}
		}
		cand.clear();
		FOR(i,N) {
			if(T[i]=='R' && S[i]=='(') {
				cand.push_back(i);
			}
			if(T[i]=='B' && S[i]==')') {
				if(cand.size()) {
					T[cand.back()]='G';
					cand.pop_back();
				}
				else {
					ng=1;
				}
			}
		}
		
		
		if(ng) T="impossible";
		cout<<T<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
