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
string S;

int hoge(string S) {
	int i,j;
	int ret=0;
	
	
	FOR(i,50) {
		string R;
		FORR(c,S) {
			R+=c;
			if(R.size()>=5 && R.substr(R.size()-5)=="phnom") {
				R.resize(R.size()-5);
				R+="penh";
				ret++;
			}
		}
		if(count(ALL(R),'h')||count(ALL(R),'e')) {
			S="";
			ret++;
			FORR(c,R) {
				if(c=='h') continue;
				if(c=='e') S+='h';
				else S+=c;
			}
		}
		else {
			S=R;
		}
	}
	int ma=0;
	
	FOR(i,(int)S.size()-4) {
		if(S.substr(i,5)=="phnom") {
			for(j=i+3;j<S.size()-1;j+=2) {
				if(S[j]!='o' || S[j+1]!='m') break;
				ret++;
				ma=max(ma,(j-i)/2+1);
			}
			i=j-1;
		}
	}
	if(ma==0 && count(ALL(S),'e')) ma=2;
	if(ma==0 && count(ALL(S),'h')) ma=1;
	ret+=ma;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	int ret=hoge(S);
	if(count(ALL(S),'h')||count(ALL(S),'e')) {
		string R;
		FORR(c,S) {
			if(c=='h') continue;
			if(c=='e') c='h';
			R+=c;
		}
		ret=max(ret,1+hoge(R));
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
