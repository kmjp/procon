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

int T,N,A[202020],B[202020];
int ok[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+2) ok[i]=0;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) {
			if(A[i]<=B[i]) {
				ok[1]++;
				ok[N+1]--;
			}
			else {
				for(j=1;j<=min(N,455);j++) {
					if((A[i]+j-1)/j==(B[i]+j-1)/j) {
						ok[j]++;
						ok[j+1]--;
					}
				}
				for(j=0;j<=455;j++) {
					int R=(j==0?1<<20:(B[i]-1)/j);
					int L=(A[i]+j)/(j+1);
					L=max({L,456});
					R=min({R,N});
					if(L<=R) {
						ok[L]++;
						ok[R+1]--;
					}
				}
			}
		}
		vector<int> V;
		for(i=1;i<=N;i++) {
			ok[i]+=ok[i-1];
			if(ok[i]==N) V.push_back(i);
		}
		cout<<V.size()<<endl;
		FORR(v,V) cout<<v<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
