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
int N;
int P[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		deque<int> D;
		ll ret=0;
		FOR(i,N) {
			cin>>x;
			if(D.empty()) {
				D.push_back(x);
			}
			else if(bt(x)==bt(N)-bt(x)) {
				ret+=bt(x);
				if(x<D.front()) {
					D.push_front(x);
				}
				else {
					D.push_back(x);
				}
			}
			else if(bt(x)<bt(N)-bt(x)) {
				ret+=bt(x);
				D.push_front(x);
			}
			else {
				ret+=bt(N)-bt(x);
				D.push_back(x);
			}
			bt.add(x,1);
		}
		cout<<ret<<endl;
		
		FOR(i,N) {
			cout<<D[i]<<" ";
			bt.add(i+1,-1);
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
