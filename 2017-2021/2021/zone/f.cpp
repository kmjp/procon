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


int N,M,L;
int A[1<<18];
int C[1<<18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	while(1<<(L+1)<=N) L++;
	FOR(i,M) {
		cin>>x;
		B[x]=1;
	}
	vector<int> V;
	C[0]=1;
	FOR(i,N) {
		if(B[i]||C[i]) continue;
		FOR(j,N) if(C[j]) C[i^j]=1;
		V.push_back(i);
	}
	
	if(V.size()!=L) {
		cout<<-1<<endl;
		return;
	}
	
	vector<pair<int,int>> R;
	vector<int> hoge;
	hoge.push_back(0);
	FORR(v,V) {
		vector<int> hoge2;
		FORR(a,hoge) {
			R.push_back({a,a^v});
			hoge2.push_back(a);
			hoge2.push_back(a^v);
		}
		
		swap(hoge,hoge2);
	}
	
	FORR2(a,b,R) cout<<a<<" "<<b<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
