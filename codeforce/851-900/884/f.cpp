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
int N,C;
int A[202000],B[202020];
int L[202000],R[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>C;
		FOR(i,N) {
			cin>>A[i];
		}
		sort(A,A+N);
		if(C>=0||N<=1) {
			FOR(i,N) B[i]=A[i];
		}
		else {
			reverse(A,A+N);
			FOR(i,N) L[i]=(i+N-1)%N,R[i]=(i+1)%N;
			
			B[0]=A[0];
			set<pair<int,int>> S;
			for(i=2;i<=N-2;i++) {
				if(A[i-1]-A[i+1]<=-C) S.insert({A[i],i});
			}
			
			FOR(i,N-1) {
				auto it=S.lower_bound({B[i]+C,0});
				if(it==S.end()) {
					x=R[0];
					S.erase({A[x],x});
				}
				else {
					x=it->second;
					S.erase(it);
				}
				B[i+1]=A[x];
				int l=L[x];
				int r=R[x];
				R[l]=r;
				L[r]=l;
				S.erase({A[l],l});
				S.erase({A[r],r});
				if(l&&L[l]&&R[l]&&(A[L[l]]-A[R[l]]<=-C)) S.insert({A[l],l});
				if(r&&L[r]&&R[r]&&(A[L[r]]-A[R[r]]<=-C)) S.insert({A[r],r});
				
			}
		}
		
		
		
		FOR(i,N) cout<<B[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
