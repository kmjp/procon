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
int T,N,M;
string A[505];
int B[505][505];
int C[505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			cin>>A[i];
			C[i]=1;
		}
		FOR(y,M) {
			FOR(x,N) {
				cin>>s;
				B[y][x]=s==A[x];
			}
		}
		
		int ok=0;
		FOR(x,N) {
			FOR(y,M) if(B[y][x]) {
				ok++;
				break;
			}
		}
		
		if(ok!=N) {
			cout<<-1<<endl;
		}
		else {
			int ma=0;
			FOR(y,M) {
				k=0;
				FOR(x,N) k+=B[y][x];
				ma=max(ma,k);
			}
			
			cout<<N+(N-ma)*2<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
