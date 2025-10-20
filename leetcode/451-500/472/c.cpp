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


class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
		int C[26]={};
		int N=s.size();
		FORR(a,s) C[a-'a']++;
		
		int i,j,x;
		for(i=N-1;i>=0;i--) {
			int D[26];
			FOR(j,26) D[j]=C[j];
			FOR(j,i) {
				D[target[j]-'a']--;
				if(D[target[j]-'a']<0) break;
			}
			cout<<j<<" "<<i<<endl;
			if(j!=i) continue;
			FOR(j,26) {
				if(D[j]&&j>target[i]-'a') {
					cout<<"!"<<i<<" "<<j<<endl;
					string v=target;
					v[i]='a'+j;
					D[j]--;
					for(j=i+1;j<N;j++) {
						FOR(x,26) if(D[x]) {
							v[j]='a'+x;
							D[x]--;
							break;
						}
					}
					return v;
				}
			}
		}
		return "";
        
    }
};

