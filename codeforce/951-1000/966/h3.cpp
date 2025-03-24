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

int T;
int N,Q;
set<int> A;
set<int> cand[(4<<20)+1];
set<int> M;

void del(int a,int b) {
	int len=b-a-1;
	int id=a+1;
	if(len<=0) return;
	cand[len].erase(id);
	if(cand[len].empty()) M.erase(len);
}

void add(int a,int b) {
	int len=b-a-1;
	int id=a+1;
	if(len<=0) return;
	cand[len].insert(id);
	M.insert(len);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		A={0};
		int pre=0;
		FOR(i,N+1) {
			if(i<N) {
				cin>>x;
			}
			else {
				x=4<<20;
			}
			y=x-1-pre;
			A.insert(x);
			add(pre,x);
			pre=x;
		}
		
		cin>>Q;
		while(Q--) {
			cin>>s>>x;
			if(s=="-") {
				auto it=A.find(x);
				int pre=*prev(it);
				int nex=*next(it);
				del(pre,x);
				del(x,nex);
				add(pre,nex);
				A.erase(it);
			}
			else if(s=="+") {
				auto it=A.insert(x).first;
				int pre=*prev(it);
				int nex=*next(it);
				del(pre,nex);
				add(pre,x);
				add(x,nex);
			}
			else if(s=="?") {
				int ret=10<<20;
				FORR(a,M) if(a>=x) ret=min(ret,*cand[a].begin());
				cout<<ret<<" ";
			}
		}
		
		
		FORR(a,M) cand[a].clear();
		M.clear();
		A.clear();
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
