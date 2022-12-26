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
int B[101010];
int D[101010];
int same[101010];
vector<int> C;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>B[i];
		if(i&&B[i]>B[i-1]+1) return _P("No\n");
		if(B[i]) same[i-(B[i]-1)]=max(same[i-(B[i]-1)],B[i]);
	}
	
	int left=0;
	int pos=0;
	FOR(i,N) {
		if(same[i]>left) {
			pos=0;
			left=same[i];
		}
		if(left==0) C.push_back(i+1);
		else {
			C.push_back(C[pos]);
			pos++;
			left--;
		}
	}
	
	auto cand=Zalgo(C);
	
	queue<pair<int,int>> Q;
	FOR(i,N) {
		if(i&&cand[i]>0) Q.push({i,cand[i]});
		while(Q.size()&&i>=Q.front().first+Q.front().second) Q.pop();
		
		if(Q.size()) D[i]=i-Q.front().first+1;
		if(D[i]!=B[i]) return _P("No\n");
		
	}
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<C[i]<<" ";
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
