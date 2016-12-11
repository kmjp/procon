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
int P10,P30;

int ask(vector<int> A,vector<int> B) {
	int x;
	cout<<"Q "<<A.size()<<" "<<B.size();
	FORR(r,A) cout<<" "<<(r+1);
	FORR(r,B) cout<<" "<<(r+1);
	cout<<endl;
	cin>>x;
	return x;
	
}

pair<pair<vector<int>,vector<int>>,int> split(vector<int> A) {
	vector<int> B,C;
	int R,i;
	
	if(A.size()%2==1) {
		R=A.back();
		A.pop_back();
	}
	FOR(i,A.size()) {
		if(i%2) B.push_back(A[i]);
		else C.push_back(A[i]);
	}
	return {{B,C},R};
}


void getless(vector<int> A) {
	if(A.size()==1) {
		P10=A[0];
		return;
	}
	auto v=split(A);
	auto a=v.first.first;
	auto b=v.first.second;
	int x=ask(a,b);
	if(x==-1) getless(a);
	else if(x==1) getless(b);
	else P10=v.second;
}

void getmore(vector<int> A) {
	if(A.size()==1) {
		P30=A[0];
		return;
	}
	auto v=split(A);
	auto a=v.first.first;
	auto b=v.first.second;
	int x=ask(a,b);
	if(x==-1) getmore(b);
	else if(x==1) getmore(a);
	else P30=v.second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	int del=-1;
	if(N%2==1) {
		i = ask({0},{1});
		j = ask({0},{2});
		k = ask({1},{2});
		if(i==0 || j==0) del=0;
		else if(k==0) del=1;
		else if(i==-1&&j==-1) del=(k==-1)?1:2;
		else if(i==1&&j==1) del=(k==1)?1:2;
		else del=0;
	}
	vector<int> A;
	FOR(i,N) if(i!=del) A.push_back(i);
	
	while(1) {
		random_shuffle(ALL(A));
		auto D=split(A);
		x = ask(D.first.first,D.first.second);
		if(x==0) continue;
		
		if(x==-1) {
			getless(D.first.first);
			getmore(D.first.second);
		}
		else {
			getmore(D.first.first);
			getless(D.first.second);
		}
		break;
	}
	
	cout<<"A "<<(P10+1)<<" "<<(P30+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
