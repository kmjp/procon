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

int K,N;
string V[101];
string W[101],R[10];
int f3[101];
int len[10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,N) {
		cin>>V[i]>>W[i];
		FORR(r,V[i]) r-='1';
	}
	f3[0]=1;
	FOR(i,10) f3[i+1]=f3[i]*3;
	
	for(int mask=0;mask<f3[K];mask++) {
		FOR(i,9) len[i]=1+(mask/f3[i]%3), R[i]="";
		
		int ok=1;
		FOR(i,N) {
			if(ok==0) break;
			int tl=0;
			FORR(r,V[i]) tl+=len[r];
			if(tl!=W[i].size()) {
				ok=0;
				break;
			}
			
			x=0;
			FORR(r,V[i]) {
				s=W[i].substr(x,len[r]);
				if(R[r]=="") R[r]=s;
				else if(R[r]!=s) {
					ok=0;
					break;
				}
				x+=len[r];
			}
		}
		if(ok) {
			FOR(i,K) cout<<R[i]<<endl;
			return;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
