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

int hoge(string s) {
	int ret=0,i;
	FOR(i,s.size()) {
		if(i<s.size()-1) {
			if(s.substr(i,2)=="CM") {
				ret+=900;
				i++;
				continue;
			}
			if(s.substr(i,2)=="CD") {
				ret+=400;
				i++;
				continue;
			}
			if(s.substr(i,2)=="XC") {
				ret+=90;
				i++;
				continue;
			}
			if(s.substr(i,2)=="XL") {
				ret+=40;
				i++;
				continue;
			}
			if(s.substr(i,2)=="IX") {
				ret+=9;
				i++;
				continue;
			}
			if(s.substr(i,2)=="IV") {
				ret+=4;
				i++;
				continue;
			}
		}
		if(s[i]=='M') ret+=1000;
		if(s[i]=='D') ret+=500;
		if(s[i]=='C') ret+=100;
		if(s[i]=='L') ret+=50;
		if(s[i]=='X') ret+=10;
		if(s[i]=='V') ret+=5;
		if(s[i]=='I') ret+=1;
	}
	return ret;
	
	
}

string hoge2(int T) {
	string s;
	if(T>3999) return "ERROR";
	while(T>=1000) s+="M", T-=1000;
	if(T>=900) s+="CM", T-=900;
	if(T>=500) s+="D", T-=500;
	if(T>=400) s+="CD", T-=400;
	while(T>=100) s+="C", T-=100;
	if(T>=90) s+="XC", T-=90;
	if(T>=50) s+="L", T-=50;
	if(T>=40) s+="XL", T-=40;
	while(T>=10) s+="X", T-=10;
	if(T>=9) s+="IX", T-=9;
	if(T>=5) s+="V", T-=5;
	if(T>=4) s+="IV", T-=4;
	while(T>=1) s+="I", T-=1;
	
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int tot=0;
	FOR(i,N) {
		cin>>s;
		tot+=hoge(s);
	}
	cout<<hoge2(tot)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
