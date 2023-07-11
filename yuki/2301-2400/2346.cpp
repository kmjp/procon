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
int A[5050],B[5050];
int S[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			S[i]=-1;
		}
		FOR(i,N) {
			cin>>B[i];
			B[i]--;
		}
		
		FOR(i,N) {
			int flag=0;
			x=i;
			vector<int> L,R;
			FOR(j,N+5) {
				L.push_back(x);
				x=A[x];
				if(x==B[i]) flag|=2;
				if(x==i) {
					flag|=1;
					break;
				}
			}
			
			if((flag&2)==0) break;
			if((flag&1)==0) continue;
			
			x=i;
			FOR(j,N+5) {
				R.push_back(x);
				x=B[x];
				if(x==i) break;
			}
			if(j==N+5) continue;
			
			int la=N+1,ra=N+1;
			FORR(a,L) la=min(la,a);
			FORR(a,R) ra=min(ra,a);
			
			if(S[la]==-1) S[la]=ra;
			if(S[la]!=ra) break;
			
			x=0;
			FORR(a,L) if(x<R.size()&&R[x]==a) x++;
			if(x!=R.size()) break;
			
			
		}
		if(i!=N) {
			cout<<"No"<<endl;
		}
		else {
			cout<<"Yes"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
