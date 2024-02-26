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

int T,N,A[202020];
vector<int> C[202020];
int P[202020];
int Q[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) C[i].clear();
		FOR(i,N) {
			cin>>A[i];
			C[A[i]-1].push_back(i);
		}
		vector<int> cand;
		FOR(i,N) {
			if(C[i].size()>2) break;
			if(C[i].size()==2) {
				if(cand.empty()) break;
				P[C[i][0]]=i;
				Q[C[i][1]]=i;
				P[C[i][1]]=cand.back();
				Q[C[i][0]]=cand.back();
				cand.pop_back();
			}
			if(C[i].size()==1) {
				P[C[i][0]]=Q[C[i][0]]=i;
			}
			if(C[i].size()==0) {
				cand.push_back(i);
			}
			
			
		}
		if(i<N) {
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		FOR(i,N) cout<<P[i]+1<<" ";
		cout<<endl;
		FOR(i,N) cout<<Q[i]+1<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
