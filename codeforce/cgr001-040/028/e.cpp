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
int A[2020][2010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		if(2*N<=M) {
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		if(M<=N) {
			FOR(i,2*N) {
				FOR(j,M) {
					cout<<j+1<<" ";
				}
				cout<<endl;
			}
			continue;
		}
		FOR(i,N) {
			FOR(j,N) {
				A[(i+j)%N][j*2]=i;
				A[(i+j)%N][j*2+1]=i;
			}
			FOR(j,N) {
				A[N+(i+j)%N][2*N-2-j*2]=i;
				if(2*N-2-(j*2+1)>=0) A[N+(i+j)%N][2*N-2-(j*2+1)]=i;
			}
		}
		
		FOR(y,2*N) {
			FOR(x,M) cout<<A[y][x]+1<<" ";
			cout<<endl;
		}
		
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
