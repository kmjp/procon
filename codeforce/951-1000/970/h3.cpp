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

int T,N,Q;
int A[101010];
int S[201010];
int ret[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			cin>>A[i];
		}
		FOR(i,2*N+2) S[i]=0;
		FOR(i,N) S[A[i]]++;
		FOR(i,2*N) S[i+1]+=S[i];
		
		int med=(N+2)/2;
		for(i=1;i<=min(N,1000);i++) {
			int C[1000]={};
			FOR(x,N) C[A[x]%i]++;
			int sum=0;
			FOR(x,i) {
				sum+=C[x];
				if(sum>=med) {
					ret[i]=x;
					break;
				}
			}
		}
		for(i=1001;i<=N;i++) {
			ret[i]=0;
			for(j=20;j>=0;j--) if(ret[i]+(1<<j)<i) {
				int sum=0;
				for(x=0;x<=N;x+=i) sum+=S[x+i-1]-S[x+(ret[i]+(1<<j)-1)];
				if(sum>=N-med+1) ret[i]+=1<<j;
			}
		}
		while(Q--) {
			cin>>x;
			cout<<ret[x]<<" ";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
