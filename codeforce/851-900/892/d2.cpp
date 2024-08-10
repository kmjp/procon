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

int T,N,L[202020],R[202020],A[202020],B[202020];
int Q;
int X[202020];

int ret[1202020];
vector<int> add[1808080],del[1808080];
int TL[1808080],TR[1808080];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		vector<int> Xs={0};
		cin>>N;
		FOR(i,N) {
			cin>>L[i]>>R[i]>>A[i]>>B[i];
			Xs.push_back(L[i]);
			Xs.push_back(A[i]);
			Xs.push_back(B[i]);
			Xs.push_back(R[i]);
		}
		cin>>Q;
		FOR(i,Q) {
			cin>>X[i];
			Xs.push_back(X[i]);
		}
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(i,Xs.size()) {
			add[i].clear();
			del[i].clear();
		}
		vector<int> C;
		FOR(i,N) {
			L[i]=lower_bound(ALL(Xs),L[i])-Xs.begin();
			R[i]=lower_bound(ALL(Xs),R[i])-Xs.begin();
			A[i]=lower_bound(ALL(Xs),A[i])-Xs.begin();
			B[i]=lower_bound(ALL(Xs),B[i])-Xs.begin();
			add[A[i]].push_back(L[i]);
			add[A[i]].push_back(R[i]);
			del[B[i]].push_back(L[i]);
			del[B[i]].push_back(R[i]);
			C.push_back(B[i]);
		}
		multiset<int> M;
		set<int> fixed;
		FOR(i,Xs.size()) {
			fixed.insert(i);
			ret[i]=0;
			FORR(a,add[i]) {
				M.insert(a);
			}
			if(M.size()) {
				TL[i]=*M.begin();
				TR[i]=*M.rbegin();
			}
			else {
				TL[i]=TR[i]=i;
			}
			FORR(a,del[i]) {
				M.erase(M.find(a));
			}
		}
		sort(ALL(C));
		reverse(ALL(C));
		FORR(c,C) {
			if(fixed.count(c)==0) continue;
			fixed.erase(c);
			ret[c]=c;
			queue<int> PQ;
			PQ.push(c);
			while(PQ.size()) {
				int cur=PQ.front();
				PQ.pop();
				auto it=fixed.lower_bound(TL[cur]);
				while(it!=fixed.end()&&*it<=TR[cur]) {
					ret[*it]=c;
					PQ.push(*it);
					it=fixed.erase(it);
				}
			}
		}
		FOR(i,Q) {
			x=lower_bound(ALL(Xs),X[i])-Xs.begin();
			if(fixed.count(x)) {
				cout<<Xs[x]<<" ";
			}
			else {
				cout<<Xs[max(ret[x],x)]<<" ";
			}
		}
		cout<<endl;
	}
			
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
