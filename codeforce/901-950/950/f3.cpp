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

int T,H,W,K;
int Y[202020],X[202020];
ll A[202020];
vector<int> cand[202020];

class AreaRect {
	map<ll,ll> M;
public:
	ll sum;
	AreaRect() {
		M[0]=1LL<<60;
		M[1LL<<60]=0;
		sum=0;
	}
	void add(ll x,ll y) {
		auto k=M.lower_bound(x);
		if(k->second>=y) return;
		while(prev(M.lower_bound(x))->second<=y) {
			auto p=*prev(M.lower_bound(x));
			M.erase(p.first);
			sum-=(p.first-prev(M.lower_bound(p.first))->first)*(p.second-M.lower_bound(p.first)->second);
		}
		sum += (x-prev(M.lower_bound(x))->first)*(y-M.lower_bound(x)->second);
		M[x]=y;
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>K;
		vector<pair<pair<int,int>,int>> ev;
		
		FOR(i,K) {
			cin>>Y[i]>>X[i];
			Y[i]=H-Y[i];
			ev.push_back({{X[i],Y[i]},i});
			A[i]=0;
			cand[i].clear();
		}
		ev.push_back({{0,H},-1});
		ev.push_back({{W+1,0},-1});
		
		int py=H;
		int px=0;
		ll ret=0;
		sort(ALL(ev));
		vector<pair<int,int>> st;
		FORR2(r,i,ev) {
			if(i<0) continue;
			if(r.second<py) {
				ret+=1LL*py*(r.first-px-1);
				A[i]=1;
				py=r.second;
				px=r.first-1;
				st.push_back({H-r.second,i});
			}
			else {
				x=lower_bound(ALL(st),make_pair(H-r.second,0))-st.begin();
				cand[st[x].second].push_back(i);
			}
		}
		ret+=1LL*py*(W-px);
		FOR(i,st.size()) {
			int nextx;
			int prevy;
			x=st[i].second;
			if(i==st.size()-1) nextx=W+1;
			else nextx=X[st[i+1].second];
			if(i==0) prevy=H;
			else prevy=Y[st[i-1].second];
			ll add=1LL*(nextx-X[x])*(prevy-Y[x]);
			AreaRect ar;
			FORR(c,cand[x]) if(X[c]<nextx) {
				ar.add(nextx-X[c],prevy-Y[c]);
			}
			A[x]=add-ar.sum;
		}
		
		cout<<ret<<endl;
		FOR(i,K) cout<<A[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
