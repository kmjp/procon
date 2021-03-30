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

int K;
int N[202020];
deque<int> A[202020];
int L[202020],R[202020];
pair<int,int> C[202020];
int SK;

int F(deque<int>& D) {
	if(D.size()==1) {
		return D[0];
	}
	else {
		int N=D.size();
		int a=D[N/2-1];
		int b=D[N/2];
		int c=D[N/2+1];
		
		if(SK%2==0) {
			return min(b,max(a,c));
		}
		else {
			return max(b,min(a,c));
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	vector<pair<int,int>> cand;
	
	FOR(i,K) {
		cin>>N[i];
		FOR(j,N[i]){
			cin>>x;
			A[i].push_back(x);
		}
		SK+=N[i]-1;
	}
	FOR(i,K) if(N[i]%2==0) {
		x=A[i].back();
		A[i].pop_back();
		C[i].first=F(A[i]);
		A[i].push_back(x);
		x=A[i][0];
		A[i].pop_front();
		C[i].second=F(A[i]);
		
		cand.push_back({abs(C[i].first-C[i].second),i});
	}
	
	int turn=0;
	sort(ALL(cand));
	reverse(ALL(cand));
	ll ret=0;
	FORR2(c,i,cand) {
		if(turn==0) {
			ret+=max(C[i].first,C[i].second);
		}
		else {
			ret+=min(C[i].first,C[i].second);
		}
		turn^=1;
	}
	
	FOR(i,K) if(N[i]%2==1) {
		ret+=F(A[i]);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
