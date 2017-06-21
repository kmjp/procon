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
map<string,int> M;
set<int> S[101010];
int ne[101010];
string C[3];

pair<string,int> split(string F) {
	if(F.back()==')') {
		int num=0;
		int v=1;
		F.pop_back();
		while(F.back()!='(') {
			num+=(F.back()-'0')*v;
			v*=10;
			F.pop_back();
		}
		F.pop_back();
		return {F,num};
	}
	else {
		return {F,0};
	}
}
void make(string F,int num) {
	if(num==0) {
		cout<<F;
	}
	else {
		cout<<F<<"("<<num<<")";
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[0]>>C[1];
		if(C[0]=="crt") {
			if(M.count(C[1])==0) M[C[1]]=M.size();
			
			y=M[C[1]];
			x=0;
			
			if(S[y].size()) {
				x=*S[y].begin();
				S[y].erase(x);
			}
			else {
				x=ne[y]++;
			}
			
			cout<<"+ ";
			make(C[1],x);
			cout<<endl;
		}
		else if(C[0]=="del") {
			auto p=split(C[1]);
			S[M[p.first]].insert(p.second);
			cout<<"- "<<C[1]<<endl;
		}
		else {
			cin>>C[2];
			auto p=split(C[1]);
			y=M[p.first];
			S[y].insert(p.second);
			
			if(M.count(C[2])==0) M[C[2]]=M.size();
			y=M[C[2]];
			if(S[y].size()) {
				x=*S[y].begin();
				S[y].erase(x);
			}
			else {
				x=ne[y]++;
			}
			
			cout<<"r "<<C[1]<<" -> ";
			make(C[2],x);
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
