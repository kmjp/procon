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
ll L[101010],R[101010];
int ret[604040];
vector<ll> ev[604040];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> cand;
	cand.push_back(-(5LL<<30));
	cand.push_back((5LL<<30));
	cin>>N;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		cand.push_back(4*L[i]);
		cand.push_back(4*L[i]-2);
		cand.push_back(4*R[i]+2);
		L[i]=4*L[i]-1;
		R[i]=4*R[i]+1;
		cand.push_back(L[i]);
		cand.push_back(R[i]);
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	FOR(i,N) {
		L[i]=lower_bound(ALL(cand),L[i])-cand.begin();
		R[i]=lower_bound(ALL(cand),R[i])-cand.begin();
	}
	
	FOR(j,2) {
		FOR(i,cand.size()) ev[i].clear();
		FOR(i,N) ev[R[i]].push_back(L[i]);
		multiset<int> uniq;
		
		FOR(i,cand.size()) {
			FORR(e,ev[i]) {
				while(uniq.size()&&*uniq.rbegin()>=e) uniq.erase(*uniq.rbegin());
				uniq.insert(i);
			}
				
			if(j==0) {
				ret[i]+=uniq.size();
			}
			else {
				ret[cand.size()-1-i]+=uniq.size();
			}
		}
		
		
		FOR(i,N) {
			L[i]=cand.size()-1-L[i];
			R[i]=cand.size()-1-R[i];
			swap(L[i],R[i]);
		}
	}
	
	cout<<*max_element(ret,ret+cand.size())<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
