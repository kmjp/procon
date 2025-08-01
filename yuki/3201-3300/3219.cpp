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
int A[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	int ret=0;
	string S=string(N,'W');
	int W,B;
	FOR(W,1<<12) {
		B=(1<<12)-1-W;
		string C;
		int w=0,b=0;
		FOR(i,N) {
			if((A[i]&W)==A[i]) {
				w|=A[i];
				C+="W";
			}
			else if((A[i]&B)==A[i]) {
				b|=A[i];
				C+="B";
			}
			else {
				break;
			}
		}
		if(i<N) continue;
		if(w*b>ret) ret=w*b,S=C;
	}
	cout<<ret<<endl;
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
