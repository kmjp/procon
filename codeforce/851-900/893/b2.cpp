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

int T,N,M,D;
int S[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>D;
		int add=0;
		S[0]=1;
		FOR(i,M) {
			cin>>S[i+1];
		}
		S[M+1]=N+1;
		ll sum=M;
		if(S[1]!=1) sum++;
		FOR(i,M+1) {
			if(S[i+1]>S[i]) sum+=(S[i+1]-S[i]-1)/D;
		}
		ll mi=sum+1;
		int id=0;
		FOR(i,M) {
			ll v=sum-max(0,(S[i+1]-S[i]-1))/D-(S[i+2]-S[i+1]-1)/D-1;
			v+=(S[i+2]-S[i]-1)/D;
			if(S[i+1]==1) v=sum;
			if(v<mi) mi=v, id=0;
			if(v==mi) id++;
		}
		cout<<mi<<" "<<id<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
