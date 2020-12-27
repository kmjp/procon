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

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> D;
        FORR(s,students) D.push_back(s);
        reverse(ALL(sandwiches));
        int i;
        FOR(i,10101) if(D.size()&& sandwiches.size()) {
            int x=D.front();
            D.pop_front();
            if(x==sandwiches.back()) {
				sandwiches.pop_back();
			}
			else {
				D.push_back(x);
			}
        }
        return D.size();
                
    }
};
