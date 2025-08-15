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
int A[202020],B[202020];
int pos[402020];
int P[404040],Q[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			pos[A[i]]=i;
		}
		FOR(i,N) {
			cin>>B[i];
			B[i]--;
			pos[B[i]]=i+N;
		}
		set<int> L;
		FOR(i,2*N) L.insert(i);
		vector<int> V={0};
		int pre=0;
		int odd=0;
		FOR(i,N) {
			x=*L.begin();
			y=pos[x]%N;
			if(y!=i) {
				swap(A[i],B[y]);
				swap(B[i],A[y]);
				pos[A[i]]=i;
				pos[B[i]]=i+N;
				pos[A[y]]=y;
				pos[B[y]]=y+N;
			}
			L.erase(A[i]);
			L.erase(B[i]);
			if(L.empty()||*L.begin()==2*(i+1)) {
				if((i+1-pre)%2) odd=1;
				pre=i+1;
			}
		}
		
		int dif=0;
		FOR(i,N) if(A[i]>B[i]) dif^=1;
		
		int ng=(dif&&odd==0);
		FOR(i,N) {
			if(A[i]>B[i]) swap(A[i],B[i]);
			if(i&&(A[i]<A[i-1]||B[i]<B[i-1])) ng=1;
		}
		
		
		
		if(ng) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
