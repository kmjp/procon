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

int L,Q;
string S;
int B[1<<20];
int A0[1<<20];
int A1[1<<20];
string T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>Q>>S;
	
	FOR(i,S.size()) {
		B[i]=S[i]-'0';
		A0[i]=A1[i]=B[i];
	}
	
	FOR(i,L) {
		FOR(j,1<<L) {
			if(j&(1<<i)) A0[j]+=A0[j^(1<<i)];
			else A1[j]+=A1[j^(1<<i)];
		}
	}
	
	while(Q--) {
		cin>>T;
		int C[3]={};
		
		reverse(ALL(T));
		FORR(c,T) {
			if(c=='0') C[0]++;
			if(c=='1') C[1]++;
			if(c=='?') C[2]++;
		}
		
		int ret=0;
		int fix=0,var=0;
		if(C[2]<=C[0]&&C[2]<=C[1]) {
			FOR(i,L) {
				if(T[i]=='?') var |= 1<<i;
				else if(T[i]=='1') fix |= 1<<i;
			}
			for(int sm=var; sm>=0; sm--) {
				sm&=var;
				ret+=B[fix|sm];
			}
		}
		else if(C[0]<=C[1]) {
			FOR(i,L) {
				if(T[i]=='0') var |= 1<<i;
				else if(T[i]=='1') fix |= 1<<i;
			}
			for(int sm=var; sm>=0; sm--) {
				sm&=var;
				if((__builtin_popcount(sm)&1)==0) {
					ret+=A1[fix|sm];
				}
				else {
					ret-=A1[fix|sm];
				}
			}
			
		}
		else {
			FOR(i,L) {
				if(T[i]=='1') var |= 1<<i;
				else if(T[i]=='?') fix |= 1<<i;
			}
			for(int sm=var; sm>=0; sm--) {
				sm&=var;
				if((__builtin_popcount(sm^var)&1)==0) {
					ret+=A0[fix|sm];
				}
				else {
					ret-=A0[fix|sm];
				}
			}
		}
		_P("%d\n",ret);
		//cout<<ret<<endl;
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
