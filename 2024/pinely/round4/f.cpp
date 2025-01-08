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

int N,Q;
int A[101010];

int L[101010],R[101010],ret[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<vector<int>,vector<int>>> cand;
	int mask;
	FOR(mask,1<<6) if(__builtin_popcount(mask)==3 && mask%2==0) {
		vector<int> X[2];
		FOR(i,6) X[(mask>>i)%2].push_back(i);
		cand.push_back({X[0],X[1]});
	}
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
	}
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		if(R[i]-L[i]>=100) {
			ret[i]=1;
		}
		else {
			vector<int> V;
			for(j=L[i];j<R[i];j++) V.push_back(A[j]);
			sort(ALL(V));
			for(x=1;x<V.size();x++) for(y=x+3;y+1<V.size();y++) if(ret[i]==0) {
				if(V[x-1]+V[x]>V[x+1]&&V[y-1]+V[y]>V[y+1]) ret[i]=1;
			}
			for(x=0;x+6<=V.size();x++) if(ret[i]==0) {
				FORR2(X,Y,cand) {
					if(V[x+X[0]]+V[x+X[1]]>V[x+X[2]]&&V[x+Y[0]]+V[x+Y[1]]>V[x+Y[2]]) ret[i]=1;
				}
			}
			
		}
		if(ret[i]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
