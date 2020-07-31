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
int X[101010];
int M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	double S=0;
	cin>>N;
	FOR(i,N) {
		cin>>X[i];
		S+=X[i];
	}
	S/=N;
	double A=0;
	FOR(i,N) {
		A+=(S-X[i])*(S-X[i]);
	}
	A/=N;
	A=pow(A,0.5);
	
	cin>>M;
	M--;
	
	if(A==0) {
		cout<<50<<endl;
		return;
	}
	
	
	
	double B=abs(S-X[M])*10.0/A;
	double C;
	if(X[M]>S) {
		C=50+B;
	}
	else {
		if(B>50) B=floor(B);
		C=50-B;
	}
	cout<<floor(C)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
