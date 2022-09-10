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

int N;
ll S[202020];

ll A[202020];
ll B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		
		y=(x-i+N)%N;
		if(N%2==0) {
			x=(y+(N/2))%N;
			if(y<x) {
				A[0]--;
				B[0]+=y;
				
				A[y]+=2;
				B[y]-=2*y;
				
				A[x]-=2;
				B[x]+=y;
				B[x]+=2*x-y;
			}
			else {
				A[0]++;
				B[0]+=y-2*x;
				
				A[x]-=2;
				B[x]-=y-2*x;
				B[x]+=y;
				
				A[y]+=2;
				B[y]-=y;
				B[y]-=y;
			}
		}
		else {
			if(y<=N/2) {
				x=y+(N/2);
				A[0]--;
				B[0]+=y;
				
				A[y]+=2;
				B[y]-=2*y;
				
				A[x+1]-=2;
				B[x+1]+=y;
				B[x+1]+=2*x-y+1;
			}
			else {
				x=y-(N/2);
				A[0]++;
				B[0]+=y-2*x+1;
				
				A[x]-=2;
				B[x]-=y-2*x+1;
				B[x]+=y;
				
				A[y]+=2;
				B[y]-=y;
				B[y]-=y;
			}
		}
		
	}
	
	ll mi=1LL<<60;
	FOR(i,N) {
		if(i) A[i]+=A[i-1],B[i]+=B[i-1];
		ll a=A[i]*i+B[i];
		mi=min(mi,a);
	}
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
