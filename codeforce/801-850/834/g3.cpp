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
int N;
int B[202020];
int A[202020];
int P[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> S,cand;
		FOR(i,N+1) P[i]=-1;
		
		FOR(i,N/2) {
			cin>>B[i];
			P[B[i]]=i;
			S.insert(B[i]);
		}
		int ng=0;
		for(i=N;i>=1;i--) {
			if(P[i]==-1) {
				if(cand.empty()) {
					ng=1;
					break;
				}
				else {
					A[*cand.rbegin()]=i;
					cand.erase(*cand.rbegin());
				}
			}
			else {
				cand.insert(P[i]);
			}
		}
		if(ng) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,N/2) {
				cout<<min(A[i],B[i])<<" ";
				cout<<max(A[i],B[i])<<" ";
			}
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
