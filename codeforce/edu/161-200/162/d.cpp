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

int T,N;
ll A[303030],S[303030];
int L[303030],R[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			if(i&&A[i]==A[i-1]) L[i]=L[i-1];
			else L[i]=i;
			S[i+1]=S[i]+A[i];
		}
		for(i=N-1;i>=0;i--) {
			if(i+1<N&&A[i]==A[i+1]) R[i]=R[i+1];
			else R[i]=i;
		}
		FOR(i,N) {
			int ret=1<<20;
			if(S[N]-S[i+1]>A[i]) {
				x=lower_bound(S,S+N+1,S[i+1]+A[i]+1)-S;
				x--;
				if(x<=R[i+1]&&A[i+1]<=A[i]) x=R[i+1]+1;
				//cout<<"R"<<i<<" "<<x<<endl;
				if(x<=N-1) ret=min(ret,x-i);
			}
			if(S[i]>A[i]) {
				x=lower_bound(S,S+N+1,S[i]-(A[i]+1))-S;
				while(x&&S[i]-S[x]<=A[i]) x--;
				if(x>=L[i-1]&&A[i-1]<=A[i]) x=L[i-1]-1;
				//cout<<"L"<<i<<" "<<x<<endl;
				if(x>=0) ret=min(ret,i-x);
			}
			if(ret==1<<20) ret=-1;
			cout<<ret<<" ";
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
