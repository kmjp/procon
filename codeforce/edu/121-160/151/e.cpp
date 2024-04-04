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
int A[1515];
const int mo=1000000007;

int from[1515][1515];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int tn1=0;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]) tn1++;
	}
	int n1=0;
	from[0][0]=1;
	FOR(i,N) {
		if(A[i]==0) {
			for(k=K;k>=0;k--) {
				int sum=0;
				for(j=0;j<=tn1;j++) {
					if(from[j][k]) {
						sum+=from[j][k];
						if(sum>=mo) sum-=mo;
						from[j][k]=0;
					}
					if(k+abs(n1-j)<=K) from[j][k+abs(n1-j)]=sum;
				}
			}
		}
		else {
			n1++;
		}
		
	}
	ll ret=0;
	FOR(i,tn1+1) {
		for(j=K%2;j<=K;j+=2) ret+=from[i][j];
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
