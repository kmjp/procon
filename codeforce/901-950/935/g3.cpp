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

int T,N,D;
ll K[303030];
int S[303030];
vector<int> add[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		vector<pair<ll,int>> V;
		multiset<ll> FQ;
		multiset<pair<ll,int>> Q;
		cin>>N>>D;
		FOR(i,N) {
			cin>>K[i]>>S[i];
			K[i]*=1000000;
			V.push_back({K[i],i});
			FQ.insert(K[i]);
		}
		reverse(ALL(V));
		int nex=1;
		FOR(i,D) {
			if(Q.size()&&Q.rbegin()->first>*FQ.rbegin()) {
				x=Q.rbegin()->second;
				Q.erase(*Q.rbegin());
			}
			else {
				x=V.back().second;
				V.pop_back();
				FQ.erase(FQ.find(K[x]));
			}
			if(i+S[x]<D) {
				add[i+S[x]].push_back(x);
			}
			
			if(V.empty()) {
				cout<<i+1<<endl;
				break;
			}
			reverse(ALL(add[i]));
			FORR(e,add[i]) {
				Q.insert({K[e]-nex++,e});
			}
		}
		if(i==D) cout<<-1<<endl;
		FOR(i,D) add[i].clear();
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
