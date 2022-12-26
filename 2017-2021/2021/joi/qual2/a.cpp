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

int N,A;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>S;
	set<int> C;
	C.insert(0);
	C.insert(N+1);
	FOR(i,N) if(S[i]=='#') C.insert(i+1);
	
	ll sum=0;
	int dir=0;
	int cur=A;
	while(C.size()>2) {
		if(dir==0) {
			auto it=C.lower_bound(cur+1);
			
			sum+=*it-cur;
			cur=*it;
			if(*it!=N+1) C.erase(it);
			dir=1;
		}
		else {
			auto it=prev(C.lower_bound(cur));
			
			sum+=cur-*it;
			cur=*it;
			if(*it!=0) C.erase(it);
			dir=0;
		}
	}
	cout<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
