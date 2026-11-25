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
int A[5050];
int R[5050];
ll from[5050];
ll to[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) R[i+1]=-1;
		int F[2]={};
		FOR(i,N) {
			cin>>A[i];
			if(A[i]!=0) {
				R[A[i]]=i;
			}
			F[i%2]++;
		}
		FOR(i,N+1) from[i]=-1LL<<60;
		from[0]=0;
		for(i=1;i<=N;i++) {
			FOR(j,N+1) to[j]=-1LL<<60;
			FOR(j,F[0]+1) FOR(x,2) {
				k=i-1-j;
				if(R[i]!=-1&&R[i]%2!=x) continue;
				if(x==0) {
					//Šï”‚Æ‚Ímin
					//‹ô”‚Æ‚Ímax,
					chmax(to[j+1],from[j]+(j+1)*i+(F[1]-k)*i);
				}
				else {
					//‹ô”‚Æ‚Ímin
					//Šï”‚Æ‚Ímax,
					chmax(to[j],from[j]+(F[0]-j)*i+(k+1)*i);
				}
			}
			swap(from,to);
		}
		cout<<from[F[0]]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
