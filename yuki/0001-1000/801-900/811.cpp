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

int N,K;

map<int,int> P[101010];
int num[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	for(i=1;i<=N;i++) {
		x=i;
		for(j=1;j*j<=i;j++) {
			while(j>1 && x%j==0) {
				P[i][j]++;
				x/=j;
			}
			if(i%j==0) {
				num[i]++;
				if(j*j!=i) num[i]++;
			}
		}
		if(x>1) P[i][x]++;
	}
	
	
	int nd=0,ret=0;
	for(i=1;i<N;i++) if(num[i]>nd) {
		int k=0;
		FORR(p,P[N]) k+=min(p.second,P[i][p.first]);
		if(k>=K&&num[i]>nd) nd=num[i], ret=i;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
