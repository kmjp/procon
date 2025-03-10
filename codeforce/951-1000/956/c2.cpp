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
ll A[3][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(j,3) {
			FOR(i,N) {
				cin>>x;
				A[j][i+1]=A[j][i]+x;
			}
		}
		vector<int> V={0,1,2};
		ll S=(A[0][N]+2)/3;
		int L[3],R[3];
		L[0]=-1;
		do {
			x=lower_bound(A[V[0]],A[V[0]]+N,S)-A[V[0]];
			y=lower_bound(A[V[1]]+x,A[V[1]]+N,A[V[1]][x]+S)-A[V[1]];
			
			if(A[V[0]][x]>=S && A[V[1]][y]-A[V[1]][x]>=S && A[V[2]][N]-A[V[2]][y]>=S) {
				L[V[0]]=1;
				R[V[0]]=x;
				L[V[1]]=x+1;
				R[V[1]]=y;
				L[V[2]]=y+1;
				R[V[2]]=N;
				
			}
		} while(next_permutation(ALL(V)));
		
		if(L[0]>=0) {
			cout<<L[0]<<" "<<R[0]<<" "<<L[1]<<" "<<R[1]<<" "<<L[2]<<" "<<R[2]<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
