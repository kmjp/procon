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

int T,N,K;
int A[2<<20];


unordered_map<int,int> M[30];
int MM[30][1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,30) FOR(j,1<<20) MM[i][j]=-1<<20;
	
	cin>>T;
	while(T--) {
		
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		
		if(K==0) {
			cout<<1<<endl;
			continue;
		}
		FOR(i,30) M[i].clear();
		
		int mi=1<<20;
		FOR(i,N) {
			int cur=0;
			int ng=0;
			for(j=29;j>=10;j--) {
				x=(A[i]>>j)<<j;
				if(((x^cur)>>j)<<j>=K) mi=min(mi,i-MM[j][cur>>j]+1);
				if(((x^cur^(1<<j))>>j)<<j>=K) mi=min(mi,i-MM[j][(cur>>j)^1]+1);
				
				cur^=(((K^x)>>j)&1)<<j;
				MM[j][A[i]>>j]=i;
			}
			for(j=9;j>=0;j--) {
				x=(A[i]>>j)<<j;
				if(ng==0) {
					if(((x^cur)>>j)<<j>=K && M[j].count(cur>>j)) mi=min(mi,i-M[j][cur>>j]+1);
					if(((x^cur^(1<<j))>>j)<<j>=K && M[j].count((cur>>j)^1)) mi=min(mi,i-M[j][(cur>>j)^1]+1);
				}
				
				cur^=(((K^x)>>j)&1)<<j;
				M[j][A[i]>>j]=i;
			}
		}
		
		if(mi>N) mi=-1;
		cout<<mi<<endl;
		FOR(i,N) for(j=10;j<30;j++) MM[j][A[i]>>j]=-1<<20;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
