#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T;
int N;
string A;
ll mo;

string incinc(string A) {
	reverse(A.begin(),A.end());
	FORR(r,A) {
		if(r=='9') r='0';
		else {
			r++;
			break;
		}
	}
	if(A.back()=='0') A += '1';
	reverse(A.begin(),A.end());
	return A;
}

string div2(string S) {
	string V;
	int i;
	reverse(ALL(S));
	FOR(i,S.size()) {
		int x=(S[i]-'0')/2;
		if(i+1<S.size()&&S[i+1]%2) x+=5;
		V.push_back('0'+x);
	}
	while(V.size()>1&&V.back()=='0') V.pop_back();
	reverse(ALL(V));
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>mo;
		string B=incinc(A);
		if(A.back()%2==0) A=div2(A);
		if(B.back()%2==0) B=div2(B);
		ll x=0,y=0;
		FORR(a,A) x=(x*10+a-'0')%mo;
		FORR(a,B) y=(y*10+a-'0')%mo;
		cout<<(x*y)%mo<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
