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


int N,L,R;
ll X[101010];
vector<int> add[101010];
vector<int> del[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	FOR(i,N) cin>>X[i+1];
	add[0].push_back(0);
	del[1].push_back(0);
	multiset<int> cur;
	FOR(i,N+1) {
		FORR(a,add[i]) cur.insert(a);
		FORR(a,del[i]) cur.erase(cur.find(a));
		if(cur.size()) {
			j=*cur.begin();
			x=lower_bound(X,X+N+1,X[i]+L)-X;
			add[x].push_back(j+1);
			x=lower_bound(X,X+N+1,X[i]+R+1)-X;
			del[x].push_back(j+1);
		}
	}
	cout<<*cur.begin()<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
