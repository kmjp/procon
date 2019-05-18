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

int H,W;
vector<int> A[505050];
vector<int> R,C;

vector<int> Zalgo(vector<int> s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}


ll hoge(vector<int> V) {
	int N=V.size();
	vector<int> VR=V;
	reverse(ALL(VR));
	V.push_back(-1);
	VR.push_back(-1);
	int i;
	FOR(i,N) VR.push_back(V[i]);
	FOR(i,N) V.push_back(VR[i]);
	
	auto A=Zalgo(V);
	auto B=Zalgo(VR);
	
	int ok=0;
	for(int l=1;l<N;l++) {
		if(A[V.size()-l]==l && B[V.size()-(N-l)]==N-l) ok++;
	}
	
	return ok;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	R.resize(H);
	C.resize(W);
	FOR(y,H) {
		cin>>s;
		int num=0;
		FOR(x,W) {
			A[y].push_back(s[x]-'0');
			R[y]+=A[y][x];
			C[x]+=A[y][x];
		}
	}
	cout<<hoge(R)*hoge(C)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
