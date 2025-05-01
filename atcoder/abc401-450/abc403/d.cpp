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

int N,D;
map<int,int> A[1<<20];

int hoge(map<int,int> A) {
	int from[2]={};
	int pre=-2;
	FORR2(a,b,A) {
		int to[2]={1<<20,1<<20};
		if(pre+1==a) {
			to[0]=min(from[0],from[1])+b;
			to[1]=from[0];
		}
		else {
			to[0]=min(from[0],from[1])+b;
			to[1]=min(from[0],from[1]);
		}
		pre=a;
		swap(from,to);
	}
	return min(from[0],from[1]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D;
	FOR(i,N) {
		cin>>x;
		if(D==0) A[0][x]++;
		else A[x%D][x/D]++;
	}
	ll ret=0;
	
	if(D==0) {
		FORR2(a,b,A[0]) ret+=b-1;
	}
	else {
		FOR(i,D) ret+=hoge(A[i]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
