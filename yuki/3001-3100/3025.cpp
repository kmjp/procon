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

int N,M,Q;
int X[101010],Y[101010];


const int B=500;
unordered_set<int> E[101010],big;
ll A[101010];
ll S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N) {
		if(E[i].size()>=B) {
			big.insert(i);
			FORR(e,E[i]) S[i]+=A[e];
		}
	}
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>y;
			x--;
			y--;
			if(E[x].count(y)) {
				E[x].erase(y);
				E[y].erase(x);
				S[x]-=A[y];
				S[y]-=A[x];
				if(E[x].size()==B-1) big.erase(x);
				if(E[y].size()==B-1) big.erase(y);
			}
			else {
				E[x].insert(y);
				E[y].insert(x);
				if(E[x].size()==B) {
					S[x]=0;
					FORR(e,E[x]) S[x]+=A[e];
					big.insert(x);
				}
				else if(E[x].size()>B) {
					S[x]+=A[y];
				}
				if(E[y].size()==B) {
					S[y]=0;
					FORR(e,E[y]) S[y]+=A[e];
					big.insert(y);
				}
				else if(E[y].size()>B) {
					S[y]+=A[x];
				}
			}
		}
		else if(i==2) {
			cin>>x>>y;
			x--;
			FORR(a,big) if(E[a].count(x)) S[a]+=y-A[x];
			A[x]=y;
		}
		else {
			cin>>x;
			x--;
			if(big.count(x)) {
				cout<<S[x]<<endl;
			}
			else {
				ll sum=0;
				FORR(e,E[x]) sum+=A[e];
				cout<<sum<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
