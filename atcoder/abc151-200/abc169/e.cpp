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
int L[202020],R[202020];
int S[2][402020];

int ok1(int v,int tar) {
	int C[3]={};
	int i;
	FOR(i,N) {
		if(R[i]<v) C[0]++;
		else if(v<L[i]) C[2]++;
		else C[1]++;
	}
	
	return C[0]<tar;
}

int ok2(int v,int tar) {
	int C[3]={};
	int i;
	FOR(i,N) {
		if(R[i]<v) C[0]++;
		else if(v<L[i]) C[2]++;
		else C[1]++;
	}
	
	return C[2]<tar;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> V;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		V.push_back(L[i]);
		V.push_back(R[i]+1);
	}
	
	int ma[2]={};
	int mi[2]={1<<30,1<<30};
	FOR(i,2) {
		int tar;
		if(N%2==0) {
			tar=N/2+i;
		}
		else {
			tar=(N+1)/2;
		}
		
		for(j=29;j>=0;j--) {
			if(ok1(ma[i]+(1<<j),tar)) ma[i]+=1<<j;
			if(ok2(mi[i]-(1<<j),tar)) mi[i]-=1<<j;
		}
	}
	
	//cout<<mi[0]<<" "<<mi[1]<<" "<<ma[0]<<" "<<ma[1]<<endl;
	if(N%2==0) {
		cout<<(ma[1]+ma[0]-mi[0]-mi[1])+1<<endl;
	}
	else {
		cout<<ma[0]-mi[0]+1<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
