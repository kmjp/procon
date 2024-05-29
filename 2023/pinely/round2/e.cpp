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
int N,M,K;
ll H[202020];
ll C[202020];
int in[202020],in2[202020];
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		FOR(i,N) {
			E[i].clear();
			in[i]=in2[i]=0;
		}
		
		FOR(i,N) {
			cin>>C[i];
			H[i]=C[i];
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			in[y-1]++;
			in2[y-1]++;
		}
		priority_queue<pair<ll,int>> Q;
		FOR(i,N) if(in[i]==0) {
			Q.push({-H[i],i});
		}
		while(Q.size()) {
			ll co=-Q.top().first;
			int x=Q.top().second;
			Q.pop();
			FORR(e,E[x]) {
				if(C[e]>=C[x]) {
					H[e]=max(H[e],H[x]+(C[e]-C[x]));
				}
				else {
					H[e]=max(H[e],H[x]+(C[e]+K-C[x]));
				}
				in[e]--;
				if(in[e]==0) Q.push({-H[e],e});
			}
		}
		multiset<ll> Ts;
		vector<pair<ll,int>> cand;
		FOR(i,N) {
			Ts.insert(H[i]);
			if(in2[i]==0) cand.push_back({H[i],i});
		}
		ll ma=*Ts.rbegin()-*Ts.begin();
		sort(ALL(cand));
		FORR2(h,i,cand) {
			Ts.erase(Ts.find(H[i]));
			H[i]+=K;
			Ts.insert(H[i]);
			Q.push({-H[i],i});
			while(Q.size()) {
				ll co=-Q.top().first;
				int x=Q.top().second;
				Q.pop();
				if(H[x]!=co) continue;
				FORR(e,E[x]) {
					ll ne;
					if(C[e]>=C[x]) {
						ne=H[x]+(C[e]-C[x]);
					}
					else {
						ne=H[x]+(C[e]+K-C[x]);
					}
					if(ne>H[e]) {
						Ts.erase(Ts.find(H[e]));
						H[e]=ne;
						Ts.insert(H[e]);
						Q.push({-H[e],e});
					}
				}
			}
			ma=min(ma,*Ts.rbegin()-*Ts.begin());
			
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
