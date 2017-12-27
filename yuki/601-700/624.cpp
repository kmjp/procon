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

int Q;
string S[100];
string T[100];
string R[100];


vector<int> ask() {
	int i;
	Q--;
	vector<int> V(3);
	FOR(i,100) {
		cout<<S[i];
		if(i!=100) cout<<" ";
	}
	cout<<endl;
	
	if(R[0].size()) {
		FOR(i,100) {
			V[(S[i][0]==R[i][0])+(S[i][1]==R[i][1])]++;
		}
		cout<<V[0]<<"/"<<V[1]<<"/"<<V[2]<<" : "<<Q<<endl;
	}
	else {
		cin>>V[0]>>V[1]>>V[2];
	}
	if(V[2]==100) exit(0);
	return V;
}

void solve(int num,int L,int R,vector<int>& V,int tot) {
	if(tot==0) return;
	while(L<R && T[V[L]][0]!='?') L++;
	while(L<R && T[V[R-1]][0]!='?') R--;
	int i;
	if(L+tot==R) {
		for(i=L;i<R;i++) T[V[i]][0]=num+'0';
		return;
	}
	int M=(L+R)/2;
	FOR(i,100) S[i]="??";
	for(i=L;i<M;i++) S[V[i]][0]='0'+num;
	
	int lp=ask()[1];
	solve(num,L,M,V,lp);
	solve(num,M,R,V,tot-lp);
}

void solve2(vector<int>& V,int n10,int num) {
	int L=0,R=V.size();
	int i;
	while(L+2<R) {
		int M1=(L*2+R)/3;
		int M2=(L+R*2)/3;
		FOR(i,100) S[i]="??";
		for(i=L;i<M1;i++) S[V[i]][0]='0'+n10;
		for(i=L;i<M2;i++) S[V[i]][1]='0'+num;
		auto ret=ask();
		if(ret[2]) R=M1;
		else if(ret[1]>M1-L) L=M1,R=M2;
		else L=M2;
	}
	
	while(L+1<R) {
		int M=(L+R)/2;
		FOR(i,100) S[i]="??";
		for(i=L;i<M;i++) S[V[i]][1]='0'+num;
		int lp=ask()[1];
		if(lp) R=M;
		else L=M;
	}
	T[V[L]][1]='0'+num;
	V.erase(V.begin()+L);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,100) S[i]=T[i]="??";
	/*
	FOR(i,100) {
		//cin>>R[i];
		R[i]=to_string(i);
		if(R[i].size()==1) R[i]="0"+R[i];
	}
	srand(time(NULL));
	//random_shuffle(R,R+100);
	*/
	
	FOR(j,10) {
		vector<int> V;
		FOR(i,100) if(T[i][0]=='?') V.push_back(i);
		solve(j,0,V.size(),V,10);
	}
	FOR(j,100) if(T[j][0]=='?') T[j][0]='9';
	FOR(i,10) {
		vector<int> V;
		FOR(j,100) if(T[j][0]=='0'+i) V.push_back(j);
		FOR(j,10) solve2(V,i,j);
	}
	
	FOR(i,100) S[i]=T[i];
	ask();
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
