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

int P[101];
int N;
int sp[101];
int left;

int test(int v,int num) {
	if(1+num>N) return 0;
	int i;
	FOR(i,N) {
		if(sp[i]==0 || num==0) {
			cout<<P[0]<<endl;
		}
		else {
			num--;
			cout<<v<<endl;
		}
	}
	
	cin>>i;
	return i==2;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==1) {
		cout<<1<<endl;
		return;
	}
	if(N==2) {
		cout<<1<<endl;
		cout<<2<<endl;
		cin>>x;
		if(x!=2) {
			cout<<2<<endl;
			cout<<1<<endl;
		}
		return;
	}
	
	x=0;
	for(i=1;i<=N;i++) {
		cout<<i<<endl;
		FOR(j,N-1) cout<<(i%N+1)<<endl;
		cin>>y;
		if(y==2) {
			P[0]=i;
			break;
		}
	}
	
	for(i=1;i<N;i++) sp[i]=1;
	int lef=N-1;
	
	for(i=1;i<=N;i++) if(i!=P[0]) {
		int num=lef;
		for(x=6;x>=0;x--) {
			if(num-(1<<x)<=0) continue;
			if(test(i,num-(1<<x))) num-=1<<x;
		}
		FOR(x,N) if(sp[x]==1) {
			num--;
			if(num==0) {
				P[x]=i;
				sp[x]=0;
				lef--;
			}
		}
	}
	
	FOR(i,N) cout<<P[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
