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

int Q;
int A[1010101];
int R;
set<int> S[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	vector<pair<int,int>> hist;
	
	MINUS(A);
	
	cin>>Q;
	while(Q--) {
		cin>>s;
		if(s=="+") {
			cin>>x;
			y=A[R];
			hist.push_back({0,y});
			if(y!=-1) {
				bt.add(*S[y].begin(),-1);
				S[y].erase(R);
				if(S[y].size()) bt.add(*S[y].begin(),1);
			}
			A[R]=x;
			if(S[x].size()) bt.add(*S[x].begin(),-1);
			S[x].insert(R);
			bt.add(*S[x].begin(),1);
			R++;
		}
		else if(s=="-") {
			cin>>x;
			R-=x;
			hist.push_back({1,x});
		}
		else if(s=="!") {
			if(hist.back().first==1) {
				R+=hist.back().second;
			}
			else {
				x=hist.back().second;
				R--;
				y=A[R];
				bt.add(*S[y].begin(),-1);
				S[y].erase(R);
				if(S[y].size()) bt.add(*S[y].begin(),1);
				
				A[R]=x;
				if(x>=0) {
					if(S[x].size()) bt.add(*S[x].begin(),-1);
					S[x].insert(R);
					bt.add(*S[x].begin(),1);
				}
			}
			hist.pop_back();
		}
		else {
			cout<<bt(R-1)<<endl;
		}

		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
