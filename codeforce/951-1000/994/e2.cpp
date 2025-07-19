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

int T;
ll N;

int ask(int L,int R) {
	cout<<"? "<<L+1<<" "<<R<<endl;
	cin>>L;
	return L;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		int A[4];
		FOR(i,3) A[i]=ask(i*N/4,(i+1)*N/4);
		A[3]=((A[0]+A[1]+A[2])%2)^1;
		int step=4;
		if(A[0]+A[1]+A[2]+A[3]==3) {
			//N/4ˆÈ‰º
			if(A[0]==0) x=N/4;
			else x=0;
			int L=2,R=N/4;
			while(L<R) {
				int M=(L+R)/2;
				if(ask(x,x+M)) {
					R=M;
				}
				else {
					L=M+1;
				}
			}
			cout<<"! "<<L<<endl;
		}
		else {
			//N/4ˆÈã
			FOR(i,4) if(A[i]) x=(i+1)*N/4;
			int L=N/4+1,R=N-1;
			while(L<R) {
				int M=(L+R)/2;
				int TR=x;
				int TL=x-M;
				if(TL<0) {
					TR-=TL;
					TL-=TL;
				}
				step++;
				if(ask(TL,TR)) {
					L=M+1;
				}
				else {
					R=M;
				}
			}
			cout<<"! "<<L<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
