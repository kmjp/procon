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
int A[1010101];
int num[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int g=0;
	FOR(i,N) {
		cin>>A[i];
		g=__gcd(g,A[i]);
		num[A[i]]++;
	}
	
	for(i=2;i<=1000000;i++) {
		x=0;
		for(j=i;j<=1000000;j+=i) x+=num[j];
		if(x>=2) break;
	}
	
	if(i==1000001) {
		cout<<"pairwise coprime"<<endl;
		return;
	}
	
	if(g==1) {
		cout<<"setwise coprime"<<endl;
	}
	else {
		cout<<"not coprime"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
