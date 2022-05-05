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
ll A[404040];
vector<pair<int,int>> V;
ll S;
int B[404040];
int D[404040];
void solve() {
	int i,j,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		V.push_back({-A[i],i});
		B[i]=1;
	}
	sort(ALL(V));
	FOR(i,N/2) {
		x=V[i].second;
		S+=A[x];
		B[x]=-1;
	}
	
	int mi=0,k=0;
	FOR(i,N) {
		D[i+1]=D[i]+B[i];
		if(D[i+1]<mi) {
			mi=D[i+1];
			k=i;
		}
	}
	cout<<k<<" "<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
