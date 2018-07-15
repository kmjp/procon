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

int N,M,K;
string S,T;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>S>>T;
	reverse(ALL(S));
	reverse(ALL(T));
	while(S.size()<2010000) S+='0';
	while(T.size()<2010000) T+='0';
	FORR(c,S) c-='0';
	FORR(c,T) c-='0';
	
	for(i=1000000;i>=0;i--) if(S[i]&&T[i]) {
		S[i]=T[i]=0;
		int Z=K-1,X=3;
		for(j=i+1;;j++) {
			assert(S[j]+T[j]<2);
			if(S[j]==0 && T[j]==0) {
				if(X==2) {
					S[j]=1;
					break;
				}
				else if(X==1) {
					T[j]=1;
					break;
				}
				else {
					if(--Z<0) {
						S[j]=T[j]=1;
						break;
					}
				}
				
			}
			else if(S[j]==1 && T[j]==0) {
				if(X&2) {
					S[j]=0;
					T[j]=X&1;
					X=2;
				}
				else {
					if(--Z<0) {
						S[j]=T[j]=1;
						break;
					}
					S[j]=0;
					X=3;
				}
			}
			else {
				if(X&1) {
					S[j]=(X>>1)&1;
					T[j]=0;
					X=1;
				}
				else {
					Z--;
					if(Z<0) {
						S[j]=T[j]=1;
						break;
					}
					T[j]=0;
					X=3;
				}
			}
			
		}
	}
	
	int out=0;
	reverse(ALL(S));
	FORR(c,S) {
		if(c==1) out=1;
		if(out) cout<<(int)c;
	}
	cout<<endl;
	out=0;
	reverse(ALL(T));
	FORR(c,T) {
		if(c==1) out=1;
		if(out) cout<<(int)c;
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
