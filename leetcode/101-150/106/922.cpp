#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> P[2],C;
        FORR(a,A) {
            P[a%2].push_back(a);
        }
        for(int i=0;i<P[0].size();i++) C.push_back(P[0][i]), C.push_back(P[1][i]);
        return C;
    }
};
