#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<typename V> struct meldable { //手抜きmeldable heapもどき。mergeがマージテクに頼って遅い。
	multiset<V> lo,hi;
	int size() {return lo.size()+hi.size();}
	void add(V v) {
		hi.insert(v);
		lo.insert(*hi.begin());
		hi.erase(hi.begin());
		if(lo.size()>hi.size()+1) hi.insert(*lo.rbegin()), lo.erase(--lo.end());
	}
	
	pair<V,V> median() {
		if(lo.size()==hi.size()) return {*lo.rbegin(),*hi.begin()};
		else return {*lo.rbegin(),*lo.rbegin()};
	}
	V max() {
		assert(lo.size()+hi.size()>0);
		if(hi.size()) return *hi.rbegin();
		else return *lo.rbegin();
	}
	
	void remove(V v) {
		auto it=hi.find(v);
		if(it!=hi.end()) {
			hi.erase(it);
			if(lo.size()>hi.size()+1) hi.insert(*lo.rbegin()), lo.erase(--lo.end());
		}
		else {
			it=lo.find(v);
			assert(it!=lo.end());
			lo.erase(it);
			if(lo.size()<hi.size()) lo.insert(*hi.begin()), hi.erase(hi.begin());
		}
	}
	
	void merge(meldable<V>& R) {
		if(lo.size()<R.lo.size()) swap(lo,R.lo), swap(hi,R.hi);
		FORR(v,R.lo) add(v);
		FORR(v,R.hi) add(v);
		R.lo.clear();
		R.hi.clear();
	}
};


int N;
ll C[101010];
int P[101010];
int D[101010];
set<int> E[101010];
ll med[101010];
meldable<pair<ll,int>> S[101010],child[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C[0];
	S[0].add({C[0],0});
	for(i=1;i<N;i++) {
		cin>>P[i]>>C[i];
		P[i]--;
		E[P[i]].insert(i);
		D[i]=D[P[i]]+1;
		C[i]+=D[i];
		S[i].add({C[i],i});
	}	
	
	for(i=N-1;i>=0;i--) {
		FORR(e,E[i]) child[i].add(make_pair(med[e],e));
		med[i]=C[i];
		while(child[i].size()&&child[i].max().first>med[i]) {
			auto a=child[i].max();
			child[i].remove(a);
			S[i].merge(S[a.second]);
			child[i].merge(child[a.second]);
			med[i]=max(med[i],S[i].median().first.first);
		}
	}
	ll ret=0;
	FOR(i,N) if(S[i].size()) {
		ll med=S[i].median().first.first;
		FORR(s,S[i].lo) ret+=abs(s.first-med);
		FORR(s,S[i].hi) ret+=abs(s.first-med);
		/*
		cout<<i<<" "<<S[i].size()<<" "<<med<<" ";
		FORR(s,S[i].lo) cout<<s.first<<":"<<s.second<<"("<<abs(s.first-med)<<") ";
		FORR(s,S[i].hi) cout<<s.first<<":"<<s.second<<"("<<abs(s.first-med)<<") ";
		cout<<endl;
		*/
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
