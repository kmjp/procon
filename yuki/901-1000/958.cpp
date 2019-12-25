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

int N,Q;
ll K,A;
string S;

pair<vector<int>,pair<int,int> > manacher(string S) {
	int L=S.size(),i,j,k;
	vector<int> rad(2*L-1,0);
	for(i=j=0;i<2*L-1;i+=k,j=max(j-k,0)) {
		while(i-j>=0 && i+j+1<=2*L-1 && S[(i-j)/2]==S[(i+j+1)/2]) j++;
		rad[i]=j;
		for(k=1;i-k>=0 && rad[i]-k>=0 && rad[i-k]!=rad[i]-k; k++) rad[i+k]=min(rad[i-k],rad[i]-k);
	}
	i=max_element(rad.begin(),rad.end())-rad.begin();
	return make_pair(rad,make_pair((i-(rad[i]-1))/2,(i+(rad[i]-1))/2));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q>>S;
	S=S+S+S+S+S;
	
	auto V=manacher(S).first;
	
	while(Q--) {
		cin>>A;
		A--;
		x=V[(A%N+2*N)*2];
		
		if(x>=2*N) {
			cout<<min(A,N*K-1-A)*2+1<<endl;
		}
		else {
			cout<<min({min(A,N*K-1-A)*2+1,(ll)x})<<endl;
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
