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


int N;
int E[55][55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	if((N*(N-1)/2)%3||N<6) {
		cout<<"No"<<endl;
		return;
	}
	
	int NE=N*(N-1)/2/3;
	vector<int> C[3];
	int S[3]={};
	for(i=N-1;i>=0;i--) {
		FOR(j,3) {
			if(S[j]+i<=NE) {
				S[j]+=i;
				C[j].push_back(i);
				break;
			}
		}
		assert(j<3);
	}
	
	FOR(i,3) {
		FORR(c,C[i]) {
			y=N-1-c;
			for(x=y+1;x<N;x++) E[y][x]=E[x][y]=i;
		}
	}
	
	FOR(k,N) FOR(y,k) FOR(x,y) {
		assert(E[y][x]==E[y][k]||E[y][x]==E[x][k]||E[y][k]==E[x][k]);
	}
	
	cout<<"Yes"<<endl;
	
	FOR(y,N) {
		for(x=y+1;x<N;x++) cout<<"RBW"[E[y][x]];
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
