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

int H,W;
int Y,X;
int N;
map<int,set<int>> R;
map<int,set<int>> C;

int Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Y>>X;
	cin>>N;
	FOR(i,N) {
		cin>>y>>x;
		R[y].insert(x);
		C[x].insert(y);
	}
	
	cin>>Q;
	while(Q--) {
		int v;
		cin>>s>>v;
		if(s=="L") {
			if(R.count(Y)) {
				auto it=R[Y].lower_bound(X);
				if(it!=R[Y].begin()) {
					it--;
					X=max(*it+1,X-v);
				}
				else {
					X=max(1,X-v);
				}
			}
			else {
				X=max(1,X-v);
			}
		}
		if(s=="R") {
			if(R.count(Y)) {
				auto it=R[Y].lower_bound(X+1);
				if(it!=R[Y].end()) {
					X=min(*it-1,X+v);
				}
				else {
					X=min(W,X+v);
				}
			}
			else {
				X=min(W,X+v);
			}
		}
		if(s=="U") {
			if(C.count(X)) {
				auto it=C[X].lower_bound(Y);
				if(it!=C[X].begin()) {
					it--;
					Y=max(*it+1,Y-v);
				}
				else {
					Y=max(1,Y-v);
				}
			}
			else {
				Y=max(1,Y-v);
			}
		}
		if(s=="D") {
			if(C.count(X)) {
				auto it=C[X].lower_bound(Y+1);
				if(it!=C[X].end()) {
					Y=min(*it-1,Y+v);
				}
				else {
					Y=min(H,Y+v);
				}
			}
			else {
				Y=min(H,Y+v);
			}
		}
		cout<<Y<<" "<<X<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
