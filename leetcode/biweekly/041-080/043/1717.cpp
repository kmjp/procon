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
    int maximumGain(string s, int x, int y) {
		int ret=0;
		if(x>=y) {
			string t;
			FORR(c,s) {
				if(t.size()&&t.back()=='a'&&c=='b') {
					t.pop_back();
					ret+=x;
				}
				else {
					t.push_back(c);
				}
			}
			s=t;
			t="";
			FORR(c,s) {
				if(t.size()&&t.back()=='a'&&c=='b') {
					t.pop_back();
					ret+=x;
				}
				else if(t.size()&&t.back()=='b'&&c=='a') {
					t.pop_back();
					ret+=y;
				}
				else {
					t.push_back(c);
				}
			}
		}
		else {
			string t;
			FORR(c,s) {
				if(t.size()&&t.back()=='b'&&c=='a') {
					t.pop_back();
					ret+=y;
				}
				else {
					t.push_back(c);
				}
			}
			s=t;
			t="";
			FORR(c,s) {
				if(t.size()&&t.back()=='a'&&c=='b') {
					t.pop_back();
					ret+=x;
				}
				else if(t.size()&&t.back()=='b'&&c=='a') {
					t.pop_back();
					ret+=y;
				}
				else {
					t.push_back(c);
				}
			}
		}
		return ret;
        
    }
};
