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

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	return A.substr(A[0]=='0');
}

string sq(string a) {
	int tmp[2022]={};
	reverse(ALL(a));
	int i,j;
	FOR(i,a.size()) FOR(j,a.size()) tmp[i+j] += (a[i]-'0')*(a[j]-'0');
	FOR(i,2019) {
		tmp[i+1] += tmp[i]/10;
		tmp[i]%=10;
	}
	string s;
	int fl=0;
	for(i=2019;i>=0;i--) {
		if(tmp[i]) fl=1;
		if(fl) s+='0'+tmp[i];
	}
	return s;
}

string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	
	if(count(ALL(S),'9')==S.size()) {
		if(S.size()%2==0) cout<<S<<endl;
		else cout<<S.substr(1)<<"81"<<endl;
		return;
	}
	
	T=incinc(S);
	string SS=sq(S);
	string TT=sq(T);
	
	if(SS.size()!=TT.size()) SS="0"+SS;
	
	int n0=0,n1=0;
	for(i=SS.size()-1;i>=0;i--) {
		if(SS[i]=='0') n0++;
		else break;
	}
	for(i=TT.size()-1;i>=0;i--) {
		if(TT[i]=='0') n1++;
		else break;
	}
	
	for(i=1;i<=SS.size();i++) if((SS.size()-i)%2==0) {
		string SSS = SS.substr(0,i);
		string TTT = TT.substr(0,i);
		if(n0<SS.size()-i) SSS=incinc(SSS);
		if(n1>=TT.size()-i) TTT=decdec(TTT);
		
		if(SSS[0]=='0') SSS=SSS.substr(1);
		if(SSS.size()<TTT.size() || (SSS.size()==TTT.size() && SSS<=TTT)) {
			cout<<SSS<<endl;
			return;
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
