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
int A[303030],P[303030];
int Q;
int L[303030],R[303030],ret[303030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

vector<pair<int,int>> ev[303030];
vector<int> Qs[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		P[A[i]]=i;
	}
	set<pair<int,int>> over={{0,N}},down;
	for(i=1;i<=N;i++) {
		x=P[i];
		auto it=over.lower_bound({x+1,0});
		it--;
		auto p=*it;
		over.erase(p);
		if(p.first<x) over.insert({p.first,x});
		if(p.second>x+1) over.insert({x+1,p.second});
		
		it=down.lower_bound({x,0});
		if(it!=down.begin()) {
			it--;
			if(it->second==x) {
				auto p=*it;
				down.erase(p);
				down.insert({p.first,x+1});
			}
			else {
				down.insert({x,x+1});
			}
		}
		else {
			down.insert({x,x+1});
		}
		it=down.lower_bound({x+1,0});
		if(it!=down.end()&&it->first==x+1) {
			auto p=*it;
			auto p2=*--it;
			down.erase(p);
			down.erase(p2);
			down.insert({p2.first,p.second});
		}
		it=over.lower_bound({x,0});
		if(it!=over.end()) {
			auto p=*it;
			it=down.lower_bound({x+1,0});
			auto p2=*--it;
			
			ev[p2.first].push_back({p.first,1});
			ev[p2.first].push_back({p.second,-1});
			ev[p2.second].push_back({p.first,-1});
			ev[p2.second].push_back({p.second,1});
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		Qs[L[i]-1].push_back(i);
	}
	FOR(i,N+1) {
		FORR2(a,b,ev[i]) bt.add(a,b);
		FORR(q,Qs[i]) {
			ret[q]=bt(R[q]-1);
		}
	}
	FOR(i,Q) {
		if(ret[i]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
