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
ll mo=1000000007;
ll pat[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	ll sum=0;
	for(int i=1;i<=100000;i++) {
		pat[i]=1;
		FOR(j,10) pat[i]=pat[i]*i%mo;
		(pat[i]+=mo-sum)%=mo;
		(sum=sum+pat[i])%=mo;
	}
	
	ll ret=0;
	for(int p=1;p<=100000;p++) {
		for(int q=1;p*q<=N;q++) {
			(ret+=pat[p]*pat[q])%=mo;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
