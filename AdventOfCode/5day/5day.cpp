#include <bits/stdc++.h>



using namespace std;

ifstream fin("in.txt");
#define isz(a) (int)a.size()


void print(vector<int> &v){
    for(int i = 0; i < (int) v.size(); ++i){
        cout << v[i] << ',';
    }
    cout << endl;
}

bool check_for_order(vector <int> &v, unordered_map<int, unordered_set<int>> &m){
    for(int i = 0; i+1 < isz(v); ++i){
        if (m[v[i]].count(v[i+1]) == 0 || m[v[i+1]].count(v[i]) == 1)
            return false;
    }
    return true;

}


void part1(){
    unordered_map <int, unordered_set<int>> m;
    int a, b;
    for (string s;getline(fin,s);){
        if (s.empty()) break;
        sscanf(s.c_str(), "%d|%d", &a, &b);
        //cout << "s " << s << endl;
        //cout << a << ' ' << b << endl;
        m[a].insert(b);
    }
    
    uint64_t ans = 0;
    for (string s; getline(fin,s);){
        vector<int> p;
        int t;
        for(int i = 0;i < isz(s)-1; i+=3){
            sscanf(s.substr(i,2).c_str(), "%d", &t);
            p.push_back(t);
        }
        bool ok = check_for_order(p,m);
        
        if(ok)ans += p[isz(p)/2]; 
    }
    cout << ans;


}



void part2(){
    unordered_map <int, unordered_set<int>> m;
    int a, b;
    for (string s;getline(fin,s);){
        if (s.empty()) break;
        sscanf(s.c_str(), "%d|%d", &a, &b);
        m[a].insert(b);
    }
    
    uint64_t ans = 0;
    for (string s; getline(fin,s);){
        vector<int> p;
        int t;
        for(int i = 0;i < isz(s)-1; i+=3){
            sscanf(s.substr(i,2).c_str(), "%d", &t);
            p.push_back(t);
        }
        bool ok = check_for_order(p,m);
        if(!ok){
            while(!check_for_order(p,m)){
                for(int i = 0; i + 1 < isz(p); ++i){
                    if (m[p[i]].count(p[i+1]) == 0 || m[p[i+1]].count(p[i]) == 1)
                        swap(p[i],p[i+1]);
                }
            }
            ans += p[isz(p)/2];
        }
    }
    cout << ans << '\n';




}


int main(){
    //auto start = chrono::steady_clock::now();
    part2();
    //auto stop = chrono::steady_clock::now();
    //auto diff = stop - start;
    //cout << chrono::duration_cast<chrono::milliseconds>(diff).count();

    // time complexity: O(infinity)



}