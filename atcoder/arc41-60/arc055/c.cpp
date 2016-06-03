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

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	return v;
}

vector<int> Z1,Z2;

string S;
int L;
void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>S;
	L=S.size();
	Z1=Zalgo(S);
	reverse(ALL(S));
	Z2=Zalgo(S);
	reverse(ALL(S));
	reverse(ALL(Z2));
	
	ll ret=0;
	for(x=2;x<L;x++) if(x>L-x) {
		int pre=min(L-x-1,Z1[x]);
		int post=min(L-x-1,Z2[x-1]);
		if(pre<1 || post<1) continue;
		int len=pre+post;
		if(len>=L-x) ret += min(len-(L-x)+1,(L-x-1));
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
