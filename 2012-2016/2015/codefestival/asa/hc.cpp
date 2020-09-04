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

int N,K;
int A[101010];
int alive[101010];
set<pair<int,int>> C[2];
vector<int> R;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		alive[A[i]]=1;
		if(i) C[1].insert({A[i],i});
	}
	C[0].insert({A[0],0});
	A[101000]=101000;
	
	int pos=0;
	while(R.size()<N) {
		int cand[3]={101000,101000,101000};
		
		// cost 0
		if(alive[A[pos]]) cand[0]=pos;
		if(K>=alive[A[pos]] && C[0].size()) cand[1]=C[0].begin()->second;
		if(((pos==0&&K)||(K>=alive[A[pos]]+1)) && C[1].size()) cand[2]=C[1].begin()->second;
		
		
		if(A[cand[0]]<=A[cand[1]]&&A[cand[0]]<=A[cand[2]]) {
			pos=cand[0];
		}
		else if(A[cand[1]]<=A[cand[0]]&&A[cand[1]]<=A[cand[2]]) {
			if(alive[A[pos]]) K--;
			pos=cand[1];
		}
		else {
			if(pos!=0 && alive[A[pos]]) K--;
			pos=cand[2];
			K--;
		}
		//cout<<cand[0]<<" "<<cand[1]<<" "<<cand[2]<<" "<<pos<<" "<<K<<endl;
		
		
		C[0].erase({A[pos],pos});
		C[1].erase({A[pos],pos});
		R.push_back(A[pos]);
		alive[A[pos]]=0;
		pos++;
		if(alive[A[pos]]) {
			C[1].erase({A[pos],pos});
			C[0].insert({A[pos],pos});
		}
		
	}
	
	FORR(r,R) cout<<r<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
