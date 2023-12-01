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
int A[202020],B[202020];
int M;
int X[202020];
int num[606060];
vector<int> cand[606060],need[606060];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		vector<int> Xs;
		scanf("%d",&N);
		FOR(i,N) {
			scanf("%d",&A[i]);
			Xs.push_back(A[i]);
		}
		FOR(i,N) {
			scanf("%d",&B[i]);
			Xs.push_back(B[i]);
		}
		scanf("%d",&M);
		FOR(i,M) {
			scanf("%d",&X[i]);
			Xs.push_back(X[i]);
		}
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(i,Xs.size()) {
			num[i]=0;
			cand[i].clear();
			need[i].clear();
		}
		FOR(i,N) {
			if(A[i]<B[i]) break;
			A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
			B[i]=lower_bound(ALL(Xs),B[i])-Xs.begin();
			if(A[i]>B[i]) need[B[i]].push_back(i);
			cand[B[i]].push_back(i);
		}
		if(i<N) {
			cout<<"NO"<<endl;
			continue;
		}
		FOR(i,M) {
			X[i]=lower_bound(ALL(Xs),X[i])-Xs.begin();
			num[X[i]]++;
		}
		set<int> did;
		did.insert(-1);
		did.insert(N);
		for(i=Xs.size()-1;i>=0;i--) {
			if(need[i].size()) {
				int ret=0;
				for(int L=0,R=0;L<need[i].size();L=R) {
					ret++;
					int tar=*did.lower_bound(need[i][L]);
					R=L;
					while(R<need[i].size()&&need[i][R]<tar) R++;
				}
				if(ret>num[i]) break;
			}
			FORR(e,cand[i]) did.insert(e);
		}
		
		if(i==-1) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
