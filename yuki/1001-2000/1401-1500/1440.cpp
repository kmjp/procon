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
ll N,A,W,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>A>>W>>K;
		if(K-1>A&&N-K+1>W) {
			cout<<":("<<endl;
		}
		else if(K<N) {
			if(A>=K-1) {
				cout<<(A-(K-1))/K<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else {
			if(W%N==0) {
				ll P=-(W/N)*(W/N+1)/2;
				if(A>=K-1) {
					P+=(A-(K-1))/K;
				}
				else {
					P+=min(-1LL,-(W/N+1)+A);
				}
				cout<<P<<endl;
			}
			else {
				ll P=-(W/N)*(W/N+1)/2;
				ll Q=-((W/N)+1)*(W/N+2)/2;
				int dif=W%N;
				if(abs(P-Q)*dif<=A) {
					A-=abs(P-Q)*dif;
					if(A>=K-1) {
						P+=(A-(K-1))/K;
					}
					else {
						P--;
					}
				}
				else {
					if(A>=dif-1) {
						P=Q+(A-(dif-1))/dif;
					}
					else {
						P=Q+min(-(W/N+2)+A,-1LL);
					}
					
				}
				cout<<P<<endl;
				
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
