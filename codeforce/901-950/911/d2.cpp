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

int T,N,A[808080];
ll C[101010],S[101010];
ll pat[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ZERO(C);
		ZERO(pat);
		
		FOR(i,N) {
			cin>>A[i];
			C[A[i]]++;
		}
		for(i=1;i<=100000;i++) S[i]=S[i-1]+C[i];
		
		for(i=1;i<=100000;i++) {
			ll sum=0;
			for(x=i;x<=100000;x+=i) if(C[x]) {
				ll mor=S[100000]-S[x];
				//a<b<c
				pat[i]+=sum*C[x]*mor;
				//a=b<c
				pat[i]+=C[x]*(C[x]-1)/2*mor;
				//a<b=c
				pat[i]+=sum*C[x]*(C[x]-1)/2;
				//a=b=c
				pat[i]+=C[x]*(C[x]-1)*(C[x]-2)/6;
				sum+=C[x];
			}
		}
		ll ret=0;
		for(i=100000;i>=1;i--) {
			for(x=i*2;x<=100000;x+=i) pat[i]-=pat[x];
			ret+=i*pat[i];
		}
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
