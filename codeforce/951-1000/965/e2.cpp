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

int T,N,X;
int A[202020];
ll S[202020];
int L[202020],R[202020];
int ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X;
		FOR(i,N) {
			cin>>A[i];
			S[i+1]=S[i]+A[i];
		}
		FOR(i,N+2) ret[i]=0;
		
		x=-1;
		FOR(i,N) {
			L[i]=i;
			R[i]=i+1;
			while(L[i]) {
				//âEÇ…êLÇŒÇ∑
				while(S[R[i]]-S[L[i]]<A[L[i]-1]) {
					if(R[i]==N||S[R[i]]-S[L[i]]<A[R[i]]) goto out;
					R[i]++;
				}
				//ç∂Ç…êLÇŒÇ∑
				L[i]--;
				R[i]=max(R[i],R[L[i]]);
				L[i]=L[L[i]];
			}
			out:
			
			if(L[i]==0) {
				for(x=max(x,R[i]);x<N;x++) if(S[x]<A[x]) break;
				ret[R[i]-1]++;
				ret[x]--;
			}
		}
		FOR(i,N) if(i) ret[i]+=ret[i-1];
		for(i=X-1;i<N;i++) {
			cout<<ret[i]<<" ";
		}
		cout<<endl;
	}
		
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
