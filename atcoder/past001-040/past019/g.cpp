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
int A[303][303];
int ok[303];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ty,tx;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		A[y][x]--;
		if(A[y][x]==-1) {
			ty=y;
			tx=x;
		}
	}
	
	vector<int> cand;
	FOR(i,N) FOR(j,N) FOR(k,N) {
		if(A[i][j]==-1) {
			cand.push_back(i*1000000+j*1000+k);
		}
		else if(A[j][k]==-1) {
			cand.push_back(i*1000000+j*1000+k);
		}
		else if(A[A[i][j]][k]==-1) {
			cand.push_back(i*1000000+j*1000+k);
		}
		else if(A[i][A[j][k]]==-1) {
			cand.push_back(i*1000000+j*1000+k);
		}
		else {
			if(A[A[i][j]][k]!=A[i][A[j][k]]) {
				cout<<0<<endl;
				return;
			}
			
		}
	}
	int ret=0;
	FOR(i,N) {
		A[ty][tx]=i;
		int ok=1;
		FORR(a,cand) {
			int i=a/1000000;
			int j=a/1000%1000;
			int k=a%1000;
			if(A[A[i][j]][k]!=A[i][A[j][k]]) ok=0;
		}
		ret+=ok;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
