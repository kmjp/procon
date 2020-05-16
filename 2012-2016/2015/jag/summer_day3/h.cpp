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

int N,X;
int A[101010];
int P[101010];

int ok(int v) {
	if(v>=N) return 0;
	int MC=A[0]+P[v],num=0;
	int i,x=N-1;
	for(i=1;i<N;i++) {
		while(x>=0) {
			if(x==v) {
				x--;
				continue;
			}
			if(A[i]+P[x]>MC) {
				x--;
				num++;
				break;
			}
			x--;
		}
	}
	return num<X;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	sort(A+1,A+N);
	reverse(A+1,A+N);
	FOR(i,N) cin>>P[i];
	
	int ret=-1;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	
	if(ret>=0) ret++;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
