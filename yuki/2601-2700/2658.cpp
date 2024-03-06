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

int N,K,A[101010];
set<int> S[50505];
vector<int> cand;
int X[50505];
int M[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		X[i+1]=X[i]^A[i];
		for(j=-K;j<=K;j++) if(A[i]+j>=1) {
			S[i].insert(A[i]^(A[i]+j));
			cand.push_back(A[i]^(A[i]+j));
		}
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	FORR(c,cand) {
		int num=0;
		FOR(i,N+1) {
			if(M[X[i]]++==0) num++;
		}
		
		for(i=N-1;i>=0;i--) {
			if(--M[X[i+1]]==0) num--;
			if(M[X[i+1]^c]++==0) num++;
			if(num==N+1&&S[i].count(c)) {
				cout<<"Yes"<<endl;
				return;
			}
		}
		M[0]--;
		FOR(i,N) M[X[i+1]^c]=0;
	}
	cout<<"No"<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
