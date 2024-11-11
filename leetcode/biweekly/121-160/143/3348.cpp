#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

vector<int> D[10];
int C[10];

string get(vector<int> V) {
	string S;
	int i;
	FOR(i,V[7]) S+="7";
	FOR(i,V[5]) S+="5";
	FOR(i,V[3]/2) S+="9";
	FOR(i,V[2]/3) S+="8";
	V[3]%=2;
	V[2]%=3;
	if(V[3]>0&&V[2]>0) S+="6", V[3]--,V[2]--;
	if(V[3]==1) S+="3", V[3]--;
	if(V[2]==2) S+="4", V[2]-=2;
	if(V[2]==1) S+="2", V[2]-=1;
	return S;
	
}

class Solution {
public:
    string smallestNumber(string num, long long t) {
		int i,j,x;
		for(i=2;i<=9;i++) {
			D[i].clear();
			j=i;
			for(x=2;x<=i;x++) while(j%x==0) D[i].push_back(x), j/=x;
		}
		vector<int> C(10);
		for(i=2;i<=9;i++) while(t%i==0) C[i]++,t/=i;
		if(t>1) return "-1";
		
		FOR(i,num.size()) {
			if(num[i]=='0') {
				for(;i<num.size();i++) {
					num[i]='1';
				}
				break;
			}
		}
		FORR(c,num) FORR(a,D[c-'0']) C[a]--;
		
		if(get(C)=="") return num;
		reverse(ALL(num));
		num+="0000000000000000000000000000000000000000000";
		int N=num.size();
		FOR(i,N) {
			FORR(a,D[num[i]-'0']) C[a]++;
			for(x=num[i]-'0'+1;x<=9;x++) {
				FORR(a,D[x]) C[a]--;
				string T=get(C);
				if(T.size()<=i) {
					while(T.size()<i) T+="1";
					sort(ALL(T));
					reverse(ALL(T));
					num[i]='0'+x;
					FOR(x,i) num[x]=T[x];
					while(num.back()=='0') num.pop_back();
					reverse(ALL(num));
					return num;
				}
				FORR(a,D[x]) C[a]++;
			}
		}
		return "";
        
    }
};

