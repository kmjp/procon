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
int X[505050];

set<int> S;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S.insert(0);
	ll ret=0;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		
		if(i==0) {
			S.insert(x);
			ret=2*x;
		}
		else {
			if(x>*S.rbegin()) {
				auto it=prev(S.end());
				y=*it;
				k=*prev(it);
				ret+=x-y;
				ret-=(y-k);
				ret+=min(x-y,y-k);
				S.insert(x);
			}
			else {
				S.insert(x);
				auto it=S.find(x);
				int p1=*prev(it);
				int p2=(prev(it)==S.begin())?(-1<<30):*prev(prev(it));
				int n1=*next(it);
				int n2=(next(next(it))==S.end())?(2000000003):*next(next(it));
				ret-=min(p1-p2,n1-p1);
				ret-=min(n2-n1,n1-p1);
				ret+=min(n1-x,x-p1);
				ret+=min(x-p1,p1-p2);
				ret+=min(n2-n1,n1-x);
			}
		}
		cout<<ret<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
