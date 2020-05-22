#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;

string A[6]={
	"",
	"000",
	"",
	"000121122",
	"000113122332",
	"000112134423324",
};
string B[6]={
	"",
	"",
	"111000",
	"002011212",
	"001012312233",
	"001011234223344",
};

deque<int> V;
void goB(int N);
void goA(int N){
	if(N<=5) {
		FORR(v,A[N]) V.push_back(v-'0');
		return;
	}
	
	int i;
	if(N%2==1) {
		for(i=N-1;i>=N/2;i--) {
			V.push_back(i);
			V.push_back(i);
		}
		for(i=N-1;i>=N/2;i--) {
			V.push_back(i);
		}
		goA(N/2);
	}
	else {
		for(i=N/2;i<N;i++) V.push_back(i);
		V.push_back(N-1);
		for(i=N/2;i<N;i++) {
			V.push_back(i);
			V.push_back(i);
		}
		goB(N/2);
	}
	
}
void goB(int N){
	if(N<=5) {
		V[V.size()-2]=B[N][0]-'0';
		int i;
		for(i=1;i<B[N].size();i++) V.push_back(B[N][i]-'0');
		return;
	}
	
	int i;
	if(N%2==1) {
		for(i=N/2;i<N;i++) {
			V.push_front(i);
		}
		for(i=N/2;i<N;i++) {
			V.push_front(i);
			V.push_front(i);
		}
		goB(N/2);
	}
	else {
		V[V.size()-2]=N-1;
		for(i=N-2;i>=N/2;i--) {
			V.push_back(i);
			V.push_back(i);
		}
		V.push_back(N-1);
		for(i=N-1;i>=N/2;i--) V.push_back(i);
		goA(N/2);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N==2) return _P("-1\n");
	goA(N);
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
