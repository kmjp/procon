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

string memo1[2020];
string memo2[2020];
int N;

string hoge_plus(int v);
string hoge_mul(int v) {
	if(v==1) return "1";
	if(v==11) return "11";
	if(v==111) return "111";
	if(v==1111) return "1111";
	if(memo1[v].size()) return memo1[v];
	string ret;
	ret.resize(5050);
	
	//ä|ÇØéZÇ≈çœÇﬁÇ»ÇÁÇªÇøÇÁ
	int x;
	for(x=2;x<v;x++) if(v%x==0&&x<=v/x) {
		string a,b;
		{
			a=hoge_mul(x);
			b=hoge_mul(v/x);
			a=a+"*"+b;
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_plus(x);
			b=hoge_mul(v/x);
			a="("+a+")"+"*"+b;
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_mul(x);
			b=hoge_plus(v/x);
			a="("+b+")"+"*"+a;
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_plus(x);
			b=hoge_plus(v/x);
			a="("+a+")"+"*"+"("+b+")";
			if(a.size()<=ret.size()) ret=a;
		}
	}
	return memo1[v]=ret;
	
}
string hoge_plus(int v){
	if(v==1) return "1";
	if(v==11) return "11";
	if(v==111) return "111";
	if(v==1111) return "1111";
	if(memo2[v].size()) return memo2[v];
	string ret;
	ret.resize(5050);
	
	//ä|ÇØéZÇ≈çœÇﬁÇ»ÇÁÇªÇøÇÁ
	int x;
	for(x=1;x<v;x++) if(x<=v-x) {
		string a,b;
		{
			a=hoge_mul(x)+"+"+hoge_mul(v-x);
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_plus(x)+"+"+hoge_mul(v-x);
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_mul(x)+"+"+hoge_plus(v-x);
			if(a.size()<=ret.size()) ret=a;
		}
		{
			a=hoge_plus(x)+"+"+hoge_plus(v-x);
			if(a.size()<=ret.size()) ret=a;
		}
	}
	return memo2[v]=ret;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	string a=hoge_plus(N);
	string b=hoge_mul(N);
	if(b.size()<a.size()) a=b;
	cout<<a<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
