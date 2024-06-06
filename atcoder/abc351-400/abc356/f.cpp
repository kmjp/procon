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
ll K;
int T[202020];
ll X[202020];


template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q>>K;
	vector<ll> Xs;
	map<ll,int> Ms;
	K*=2;
	Xs={-3LL<<60,7LL<<60,(-3LL<<60)+1};
	FOR(i,Q) {
		cin>>T[i]>>X[i];
		X[i]*=2;
		Xs.push_back(X[i]);
		Xs.push_back(X[i]+1);
	}
	sort(ALL(Xs));
	FOR(i,Xs.size()) Ms[Xs[i]]=i;
	
	
	set<int> S={0,(int)Xs.size()-1};
	set<int> W={1};
	
	FOR(i,Q) {
		x=Ms[X[i]];
		if(T[i]==1) {
			if(S.count(x)) {
				auto it=S.find(x);
				int pre=*prev(it);
				int nex=*next(it);
				S.erase(it);
				W.erase(pre+1);
				W.erase(x+1);
				if(Xs[nex]-Xs[pre]>K) W.insert(pre+1);
				bt.add(x,-1);
			}
			else {
				S.insert(x);
				auto it=S.find(x);
				int pre=*prev(it);
				int nex=*next(it);
				W.erase(pre+1);
				if(Xs[x]-Xs[pre]>K) W.insert(pre+1);
				if(Xs[nex]-Xs[x]>K) W.insert(x+1);
				bt.add(x,1);
			}
		}
		else {
			auto it=W.lower_bound(x);
			cout<<bt(*it)-bt(*prev(it))<<endl;
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
