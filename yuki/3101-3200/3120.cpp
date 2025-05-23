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
int A[10101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int nim=0;
	FOR(i,N) {
		cin>>A[i];
		nim^=A[i];
	}
	int K=1<<20;
	if(nim) {
		cout<<"First"<<endl;
		while(1) {
			
			nim=0;
			FOR(i,N) nim^=A[i];
			x=1;
			FOR(j,100) if(nim&(1<<j)) {
				x=1<<j;
				break;
			}
				
			y=0;
			FOR(i,N) if(A[i]>=A[y]) y=i;
			cout<<y+1<<" "<<x<<endl;
			A[y]-=x;
			
			
			cin>>x;
			if(x) return;
			
			cin>>x>>y;
			A[x-1]-=y;
			cin>>x;
			if(x) return;
		}
	}
	else {
		cout<<"Second"<<endl;
		while(1) {
			cin>>x>>y;
			A[x-1]-=y;
			cin>>x;
			if(x) return;
			
			nim=0;
			FOR(i,N) nim^=A[i];
			x=1;
			FOR(j,100) if(nim&(1<<j)) {
				x=1<<j;
				break;
			}
				
			y=0;
			FOR(i,N) if(A[i]>=A[y]) y=i;
			cout<<y+1<<" "<<x<<endl;
			A[y]-=x;
			cin>>x;
			if(x) return;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
