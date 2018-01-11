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

int p2[1010100],p5[1010100],p10[1010100];
int R=0;

int ask(int n) {
	int ret;
	cout<<"Q "<<n<<endl;
	if(R) {
		if(n<=R) return 1;
		else return 0;
	}
	
	cin>>ret;
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[1]=0;
	p5[1]=0;
	for(i=2;i<=1000000;i++) {
		p2[i]=p2[i-1];
		p5[i]=p5[i-1];
		x=i;
		while(x%2==0) x/=2, p2[i]++;
		while(x%5==0) x/=5, p5[i]++;
		p10[i]=min(p2[i],p5[i]);
	}
	
	int L=0;
	for(i=20;i>=0;i--) {
		if(L+(1<<i)>1000000) continue;
		if(ask(L+(1<<i))==1) L+=1<<i;
	}
	for(i=5;i<=100000;i++) {
		if(p10[i]>=L) {
			cout<<"A "<<i<<endl;
			return;
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
