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
string T;
ll p3[13];
ll P[540000];
ll D[540000];
int F[540000];
ll W[14][540000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	p3[0]=1;
	FOR(i,N) p3[i+1]=p3[i]*3;
	
	for(i=1;i<=N;i++) {
		FOR(x,p3[i]) D[x]=x/p3[i-1];
		W[i][0]=p3[i]-1;
		ZERO(F);
		int nf=0;
		FOR(x,T.size()) {
			if(T[x]=='S') {
				nf++;
			}
			else {
				y=W[i-1][x];
				if((nf-F[y])%2) {
					FOR(j,3) {
						if(D[y+j*p3[i-1]]==1) D[y+j*p3[i-1]]=2;
						else if(D[y+j*p3[i-1]]==2) D[y+j*p3[i-1]]=1;
					}
					F[y]=nf;
				}
				FOR(j,3) {
					D[y+j*p3[i-1]]=(D[y+j*p3[i-1]]+1)%3;
				}
			}
			y=W[i-1][x+1];
			if((nf-F[y])%2) {
				FOR(j,3) {
					if(D[y+j*p3[i-1]]==1) D[y+j*p3[i-1]]=2;
					else if(D[y+j*p3[i-1]]==2) D[y+j*p3[i-1]]=1;
				}
				F[y]=nf;
			}
			FOR(j,3) if(D[y+j*p3[i-1]]==2) W[i][x+1]=y+j*p3[i-1];
		}
		
		
		FOR(y,p3[i-1]) {
			if((nf-F[y])%2) {
				FOR(j,3) {
					if(D[y+j*p3[i-1]]==1) D[y+j*p3[i-1]]=2;
					else if(D[y+j*p3[i-1]]==2) D[y+j*p3[i-1]]=1;
				}
			}
		}
		FOR(x,p3[N]) P[x]+=D[x%p3[i]]*p3[i-1];
	}
	
	FOR(i,p3[N]) {
		cout<<P[i]<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
