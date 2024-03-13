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
pair<int,int> A[202020];

vector<int> add[202020];

int can(int v) {
	int i;
	FOR(i,N) add[i].clear();
	FOR(i,N) {
		int smi;
		if(A[i].first<=v) {
			smi=0;
		}
		else {
			smi=A[i].first-v;
			if(smi>=N) return 0;
		}
		if(A[i].second<v) return 0;
		add[smi].push_back(A[i].second-v);
	}
	multiset<int> A;
	FOR(i,N) {
		FORR(a,add[i]) A.insert(a);
		if(A.size()&&*A.begin()<i) return 0;
		if(A.empty()) return 0;
		A.erase(A.begin());
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i].first>>A[i].second;
	}
	sort(A,A+N);
	
	int kmi=0;
	FOR(i,N) {
		kmi=max(kmi,A[i].first-i);
		swap(A[i].first,A[i].second);
	}
	sort(A,A+N);
	int kma=1<<30;
	FOR(i,N) {
		kma=min(kma,A[i].first-i);
		swap(A[i].first,A[i].second);
	}
	
	if(can(kmi)&&can(kma)) cout<<max(0,kma-kmi+1)<<endl;
	else cout<<0<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
