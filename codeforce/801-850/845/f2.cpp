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

int T,N,A[202020];
int S[202020];
ll ret=0;

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;
	}
	void add(ll s,int pos=29) {
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,pos-1);
		}
	}
	ll pick(ll val,int pos=29) { // sum [0,s-1]
		if(pos<0) return 0;
		
		int tar=0;
		if(!(val&(1LL<<pos))) {
			if(nex[1]) tar=1;
			else tar=0;
		}
		else {
			if(nex[0]) tar=0;
			else tar=1;
		}
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
	void del() {
		if(nex[0]) {
			nex[0]->del();
			delete nex[0];
		}
		if(nex[1]) {
			nex[1]->del();
			delete nex[1];
		}
	}
};

BinarySumTrie* bst[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		set<pair<int,int>> D;
		FOR(i,N+2) {
			if(bst[i]) {
				bst[i]->del();
				delete bst[i];
				bst[i]=NULL;
			}
		}
			
		FOR(i,N) {
			cin>>A[i+1];
			S[i+1]=S[i]^A[i+1];
			V.push_back({A[i+1],i+1});
		}
		D.insert({0,0});
		D.insert({N+1,N+1});
		
		bst[0]=new BinarySumTrie();
		bst[N+1]=new BinarySumTrie();
		bst[0]->add(0);
		bst[N+1]->add(S[N]);
		
		ll ma=0;
		sort(ALL(V));
		FORR2(v,i,V) {
			pair<int,int> L={-1,-1},R={-1,-1};
			auto it=D.lower_bound({i+1,i+1});
			if(it->first==i+1) {
				R=*it;
			}
			it--;
			if(it->second==i-1) {
				L=*it;
			}
			if(L.first==-1&&R.first==-1) {
				bst[i]=new BinarySumTrie();
				bst[i]->add(S[i]);
				bst[i]->add(S[i-1]);
				D.insert({i,i});
			}
			else if(L.first==-1) {
				D.erase(R);
				D.insert({i,R.second});
				ma=max(ma,S[i-1]^A[i]^bst[R.first]->pick(S[i-1]^A[i]));
				swap(bst[i],bst[i+1]);
				bst[i]->add(S[i-1]);
			}
			else if(R.first==-1) {
				D.erase(L);
				D.insert({L.first,i});
				ma=max(ma,S[i]^A[i]^bst[L.first]->pick(S[i]^A[i]));
				bst[L.first]->add(S[i]);
			}
			else {
				D.erase(L);
				D.erase(R);
				D.insert({L.first,R.second});
				if(i-L.first<R.second-i) {
					for(j=max(0,L.first-1);j<i;j++) ma=max(ma,S[j]^A[i]^bst[R.first]->pick(S[j]^A[i]));
					for(j=max(0,L.first-1);j<i;j++) bst[R.first]->add(S[j]);
					swap(bst[L.first],bst[R.first]);
				}
				else {
					for(j=i;j<=min(N,R.second);j++) ma=max(ma,S[j]^A[i]^bst[L.first]->pick(S[j]^A[i]));
					for(j=i;j<=min(N,R.second);j++) bst[L.first]->add(S[j]);
				}
				bst[R.first]->del();
				delete bst[R.first];
				bst[R.first]=NULL;
			}
		}
		cout<<ma<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
