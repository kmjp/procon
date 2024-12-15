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
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        map<string,double> S;
        S[initialCurrency]=1;
        int i,j;
        FOR(i,100) {
			FOR(j,pairs1.size()) {
				S[pairs1[j][1]]=max(S[pairs1[j][1]],S[pairs1[j][0]]*rates1[j]);
				S[pairs1[j][0]]=max(S[pairs1[j][0]],S[pairs1[j][1]]/rates1[j]);
			}
		}
        FOR(i,100) {
			FOR(j,pairs2.size()) {
				S[pairs2[j][1]]=max(S[pairs2[j][1]],S[pairs2[j][0]]*rates2[j]);
				S[pairs2[j][0]]=max(S[pairs2[j][0]],S[pairs2[j][1]]/rates2[j]);
			}
		}
        return S[initialCurrency];
        
    }
};

