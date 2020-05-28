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
string A;

int num2[1010101];
int S2[1010101];

int hoge(string A) {
	int i;
	for(i=1;i<=N;i++) {
		int x=i;
		while(x%2==0) x/=2, num2[i]++;
		S2[i]=S2[i-1]+num2[i];
	}
	
	int sum=0;
	int N=A.size();
	FOR(i,N) {
		int a=S2[N-1]-S2[i]-S2[N-1-i];
		if(a==0) sum+=A[i];
	}
	return sum%2;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	int C[3]={};
	FORR(c,A) {
		c-='1';
		C[c]++;
	}
	
	if(C[0]==0) {
		string B;
		C[0]=C[1]=C[2]=0;
		FOR(i,N-1) B.push_back(abs(A[i]-A[i+1]));
		N--;
		A=B;
		FORR(c,A) C[c]++;
	}
	
	if(C[1]==0) {
		FORR(c,A) c/=2;
		cout<<hoge(A)*2<<endl;
		return;
	}
	cout<<hoge(A)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
