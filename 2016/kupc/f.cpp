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
int N;
string S;
int ptr,L;


pair<int,int> hoge() {
	if(ptr>=L) return {0,99};
	int x=ptr;
	if(S[x]=='0') {
		ptr++;
		return {0,0};
	}
	else if(S[x]>='1' && S[x]<='9') {
		ptr++;
		if(x==L-1) {
			return {S[x]-'0',(S[x]-'0')*10+9};
		}
		
		if(S[ptr]>='0' && S[ptr]<='9') {
			ptr++;
			return {(S[x]-'0')*10+(S[x+1]-'0'),(S[x]-'0')*10+(S[x+1]-'0')};
		}
		else {
			return {S[x]-'0',S[x]-'0'};
		}
	}
	else if(S[x]=='^' || S[x]=='_') {
		ptr++;
		ptr++;
		if(ptr>=L) return {0,99};
		auto lh=hoge(),rh=lh;
		ptr++;
		if(ptr>=L) rh={0,99};
		else rh=hoge();
		
		ptr++;
		if(S[x]=='^') return {max(lh.first,rh.first),max(lh.second,rh.second)};
		else return {min(lh.first,rh.first),min(lh.second,rh.second)};
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>Q;
	while(Q--) {
		cin>>S;
		N=S.size();
		for(i=1;i<=N;i++) {
			ptr=0;
			L=i;
			auto ret=hoge();
			if(ret.first==ret.second) {
				cout<<ret.first<<" "<<i<<endl;
				break;
			}
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
