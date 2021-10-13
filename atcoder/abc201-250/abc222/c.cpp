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

int N,M;
int A[100][100];
pair<int,int> P[101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,2*N) {
		cin>>s;
		FOR(j,M) {
			if(s[j]=='G') A[i][j]=0;
			if(s[j]=='C') A[i][j]=1;
			if(s[j]=='P') A[i][j]=2;
		}
		P[i]={0,i};
	}
	
	FOR(i,M) {
		FOR(j,N) {
			x=A[P[j*2].second][i];
			y=A[P[j*2+1].second][i];
			if((x+1)%3==y) P[j*2].first--;
			if((y+1)%3==x) P[j*2+1].first--;
		}
		sort(P,P+2*N);
	}
	
	FOR(i,2*N) cout<<P[i].second+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
