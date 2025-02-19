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
string A,B;
int S[202020];
int Q,L,R;

int check(int i,int L,int R) {
	if(A[i]=='1') return 1;
	int lef=0,ri=0;
	if(i-1>=L&&B[i-1]=='1') lef=1;
	if(i-2>=L&&A[i-2]=='0') lef=1;
	if(i+1<=R&&B[i+1]=='1') ri=1;
	if(i+2<=R&&A[i+2]=='0') ri=1;
	return lef&ri;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>B;
		FOR(i,N) S[i+1]=S[i]+check(i,0,N-1);
		cin>>Q;
		while(Q--) {
			cin>>L>>R;
			L--;
			R--;
			int ret=0;
			if(R-L>=5) {
				ret+=S[R-2+1]-S[L+1+1];
				ret+=check(L,L,R);
				ret+=check(L+1,L,R);
				ret+=check(R-1,L,R);
				ret+=check(R,L,R);
			}
			else {
				for(i=L;i<=R;i++) ret+=check(i,L,R);
			}
			cout<<ret<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
