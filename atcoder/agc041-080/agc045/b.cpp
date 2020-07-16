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
int N;

int Rcur[1010101];
int Rma[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int cur=0,Z=0;
	FORR(c,S) {
		if(c=='1') cur++;
		else cur--;
		Z=max(cur,Z);
	}
	
	for(i=N-1;i>=0;i--) {
		if(S[i]=='1') {
			Rcur[i]=Rcur[i+1]-1;
		}
		else {
			Rcur[i]=Rcur[i+1]+1;
		}
		Rma[i]=max(Rcur[i],Rma[i+1]);
	}
	
	int mi=0;
	cur=0;
	FOR(i,N) {
		//cout<<i<<" "<<cur<<" "<<Rma[i+1]<<" "<<Z<<" "<<(cur+1+Rma[i+1]>Z)<<" "<<S[i]<<endl;
		if(S[i]=='1') cur++;
		else if(S[i]=='0') cur--;
		else {
			if(cur+1+(Rma[i+1]-Rcur[i+1])>Z) {
				cur--;
			}
			else {
				cur++;
			}
		}
		mi=min(mi,cur);
	}
	
	int ret=Z-mi;
	cur=mi=0;
	FOR(i,N) {
		//cout<<i<<" "<<cur<<" "<<Rma[i+1]<<" "<<Z<<" "<<(cur+1+Rma[i+1]>Z)<<" "<<S[i]<<endl;
		if(S[i]=='1') cur++;
		else if(S[i]=='0') cur--;
		else {
			if(cur+1+(Rma[i+1]-Rcur[i+1])>Z+1) {
				cur--;
			}
			else {
				cur++;
			}
		}
		mi=min(mi,cur);
	}
	ret=min(ret,Z+1-mi);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
