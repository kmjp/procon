#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))


class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> S;
        FORR(e,emails) {
            string T;
            bool F=true,A=false;
            FORR(c,e) {
                if(A) {
                    T+=c;
                }
                else {
                    if(c=='@') {
                        T+=c;
                        A=true;
                    }
                    else if(c=='.') {
                        continue;
                    }
                    else if(c=='+') {
                        F=false;
                        continue;
                    }
                    else if(F) {
                        T+=c;
                    }
                }
            }
            S.insert(T);
        }
        return S.size();
        
    }
};
