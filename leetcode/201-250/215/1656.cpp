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


string S[1010];
int ptr=0;
class OrderedStream {
public:
    OrderedStream(int n) {
        int i;
        FOR(i,n+3) S[i]="";
        ptr=0;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> V;
        S[id]=value;
        while(S[ptr+1].size()) {
			V.push_back(S[ptr+1]);
			ptr++;
		}
		return V;
    }
};

