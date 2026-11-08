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

int T,N,A[10101],B[10101];
int C[10101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll sum=0;
		FOR(i,N) {
			cin>>A[i];
			sum+=A[i];
		}
		FOR(i,N) {
			cin>>B[i];
			sum-=B[i];
		}
		sort(A,A+N);
		sort(B,B+N);
		if(sum<0) {
			cout<<-1<<endl;
			continue;
		}
		else if(sum==0) {
			FOR(i,N) if(A[i]!=B[i]) break;
			if(i==N) {
				cout<<100000000<<endl;
			}
			else {
				cout<<-1<<endl;
			}
		}
		else {
			vector<ll> cand;
			for(ll a=1;a*a<=sum;a++) if(sum%a==0) {
				cand.push_back(a);
				cand.push_back(sum/a);
			}
			ll ret=-1;
			FORR(a,cand) if(a<=A[N-1]) {
				FOR(i,N) C[i]=A[i]%a;
				sort(C,C+N);
				FOR(i,N) if(B[i]!=C[i]) break;
				if(i==N) ret=a;
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
