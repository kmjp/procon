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
ll T,X,Y,D[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T>>X>>Y;
	FOR(i,N) cin>>D[i];
	sort(D,D+N);
	vector<int> add={1};
	for(i=1;i<N;i++) {
		if(D[i]-D[i-1]>T) {
			add.push_back(1);
		}
		else {
			add.back()++;
		}
	}
	sort(ALL(add));
	ll ret=0;
	FOR(i,N) {
		if(add.back()==0) {
			ret+=min(X,Y);
			add.pop_back();
		}
		add.back()--;
		cout<<ret<<" ";
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
