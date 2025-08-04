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

int T,N;
pair<int,int> A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<pair<int,int>> S;
		set<int> avail={0,N+1};
		A[0]=A[N+1]={1<<30,1};
		
		S.insert({1<<30,0});
		S.insert({1<<30,N+1});
		FOR(i,N) {
			cin>>x;
			A[i+1]={x,1};
			S.insert({x,i+1});
			avail.insert(i+1);
		}
		ll ret=0;
		while(S.size()>=3) {
			auto p=*S.begin();
			S.erase(p);
			int cur=p.second;
			avail.erase(cur);
			auto it=avail.lower_bound(cur);
			
			int nex=*it;
			int pre=*prev(it);
			
			assert(A[pre].first!=A[cur].first);
			if(A[nex].first==A[cur].first) {
				S.erase({A[nex].first,nex});
				avail.erase(nex);
				
				A[cur].second+=A[nex].second;
				S.insert({A[cur].first,cur});
				avail.insert(cur);
				continue;
			}
			if(A[cur].second>1) {
				A[cur].first++;
				ret+=A[cur].second%2;
				A[cur].second=(A[cur].second+1)/2;
				S.insert({A[cur].first,cur});
				avail.insert(cur);
				continue;
			}
			if(S.size()==2) break;
			assert(A[pre].first>A[cur].first);
			assert(A[nex].first>A[cur].first);
			int mi=min(A[nex].first,A[pre].first);
			ret+=mi-A[cur].first;
			A[cur].first=mi;
			
			S.insert({A[cur].first,cur});
			avail.insert(cur);
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
