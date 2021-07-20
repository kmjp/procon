#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
int A[202020];
int tar[202020];

int num[202020][31];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	
	FOR(i,30) FOR(x,N+1) num[x][i]=1<<30;
	
	sort(A,A+N);
	reverse(A,A+N);
	
	num[0][0]=0;
	
	FOR(i,N) {
		if(i) tar[i]=tar[i-1];
		while(tar[i]<N&&A[i]<2*A[tar[i]]) tar[i]++;
		
		FOR(j,30) {
			// skip
			num[i+1][j]=min(num[i+1][j],num[i][j]+1);
			num[tar[i]][j+1]=min(num[tar[i]][j+1],num[i][j]);
		}
	}
	
	FOR(i,31) if(num[N][i]<=K) {
		cout<<i<<" "<<num[N][i]<<endl;
		break;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
