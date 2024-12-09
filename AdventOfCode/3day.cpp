#include<bits/stdc++.h>


using namespace std;

#define isize(a) (int)a.size()

ifstream fin("in.txt");




void part1(){

    uint64_t ans = 0;
    string s = "";
    for(string t; getline(fin, t);){
        s += t;
    }
    int fi, se;
    
    for(int i = 0; i < isize(s); ++i){
        if(s.substr(i,4)=="mul("){
            
            istringstream isf(s.substr(i+4,3));

            isf >> fi;
            int fs = int(to_string(fi).length());
            isf.clear();
            
            if (s[i+fs+4] != ',') continue;

            istringstream iss(s.substr(i+5+fs,3));
            iss >> se;
            int ss = int(to_string(se).length());
            iss.clear();
            
            if (s[i+fs+ss+5] != ')') continue;

            ans += fi * se;
            i += 5 +fs+ss;
        }
    }
    cout << ans;
}


void part2(){
    bool scan = true;
    uint64_t ans = 0;
    string s = "";
    for(string t; getline(fin, t);){
        s += t;
    }
    int fi, se;
    
    for(int i = 0; i < isize(s); ++i){
        if(!scan && s.substr(i,4)=="do()"){
            //i+=3;
            scan = true;
            continue;
        }
        if(scan && s.substr(i,7)=="don't()"){
            //i+=6;
            scan = false;
            continue;
        }
         
        if(scan && s.substr(i,4)=="mul("){
            
            istringstream isf(s.substr(i+4,3));

            isf >> fi;
            int fs = int(to_string(fi).length());

            isf.clear();
            
            if (s[i+fs+4] != ',') continue;

            istringstream iss(s.substr(i+5+fs,3));
            iss >> se;
            int ss = int(to_string(se).length());
            iss.clear();
            
            if (s[i+fs+ss+5] != ')') continue;

            ans += fi * se;
            //i += 5 +fs+ss;
        }
    }
    cout << ans << endl;


}


int main(){
    auto start = chrono::high_resolution_clock::now();
    part2();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count();


}