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

int T,N,A[101010],C[101010];
int in[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) in[i]=0;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			in[A[i]]++;
		}
		FOR(i,N) cin>>C[i];
		ll ret=0;
		queue<int> Q;
		FOR(i,N) if(in[i]==0) {
			Q.push(i);
		}
		vector<int> R;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			R.push_back(x+1);
			in[A[x]]--;
			if(in[A[x]]==0) {
				Q.push(A[x]);
			}
		}
		
		FOR(i,N) if(in[i]) {
			vector<int> X;
			int pre=i;
			int mi=i;
			while(X.empty()||X.back()!=i) {
				pre=A[pre];
				X.push_back(pre);
				in[pre]=0;
				if(C[pre]<C[mi]) mi=pre;
			}
			FOR(j,X.size()) if(mi==X[j]) {
				FOR(x,X.size()) R.push_back(X[(j+1+x)%X.size()]+1);
			}
		}
		FORR(a,R) cout<<a<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
