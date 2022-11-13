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


int A[10101];
int S[10101];

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
		ZERO(A);
		int i,j;
		for(i=1;i<=10000;i++) A[i]++;
		for(i=10;i<=10000;i++) A[i]++;
		for(i=100;i<=10000;i++) A[i]++;
		for(i=1000;i<=10000;i++) A[i]++;
		for(i=10000;i<=10000;i++) A[i]++;
		FOR(i,10000) S[i+1]=S[i]+A[i+1];
		
		for(i=1;i<=10000;i++) {
			if(A[i]+A[i]+3>limit) continue;
			ll ret=limit*i-(S[i]+(A[i]+3)*i);
			if(ret>=message.size()) {
				vector<string> V;
				int cur=0;
				for(j=1;j<=i;j++) {
					int msg=limit-(A[j]+A[i]+3);
					int len=min(msg,(int)message.size()-cur);
					string s=message.substr(cur,len);
					s+="<";
					s+=to_string(j);
					s+="/";
					s+=to_string(i);
					s+=">";
					V.push_back(s);
					cur+=len;
				}
				return V;
			}
			
		}
		return {};
        
    }
};

