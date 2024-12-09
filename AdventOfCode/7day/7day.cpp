#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.txt");
#define isz(a) (int)a.size()
#define all(a) a.begin(),a.end()


bool gen_new_comb(vector<int> &v){            //useless combinations generator 
    for(int i = isz(v)-1; i >= 0; --i){
        if(v[i] == 0){
            v[i] = 1;
            return 1;
        }
        if(v[i] == 1){
            v[i] = 2;
            return 1;
        }
        if(v[i] == 2){
            v[i] = 0;
        }
    }
    return 0;
}

void concat(uint64_t &a, uint64_t b){
    uint64_t pow10 = 1;
    while(pow10 <= b) pow10 *= 10;
    a = a * pow10 + b;
}

bool achivible(vector<uint64_t> &v, uint64_t goal){
    vector<int> signs(isz(v)-1,0);
    vector<int> t;
    uint64_t temp;
    do{
        t = signs;
        sort(all(t));
        do{
            temp = v[0];
            for(int i = 0; i + 1 < isz(v); ++i){
                if(t[i] == 0)
                    temp += v[i+1];
                else if(t[i] == 1)
                    temp *= v[i+1];
                else 
                    concat(temp, v[i+1]);
            }
            if (temp == goal) return 1;
        }while(next_permutation(all(t)));
    }while(gen_new_comb(signs));
    return 0;
}

void part1(){
    uint64_t ans{};
    for(string s; getline(fin,s);){
        uint64_t goal;
        string t;
        vector<uint64_t> v;
        istringstream sin(s); sin >> goal;
       
        istringstream ssin(s.substr(isz(to_string(goal))+1));
        for (int temp; ssin >> temp;) v.push_back(temp);
        if (achivible(v,goal)) ans += goal;
    }
    cout << ans;


}



void part2(){
    
    uint64_t ans{};
    for(string s; getline(fin,s);){
        uint64_t goal;
        vector<uint64_t> v;
        stringstream sin(s); sin >> goal;
        char ch;
        sin >> ch;
        for (uint64_t temp; sin >> temp; v.push_back(temp));
        const uint64_t limit = pow(3,isz(v)-1);
        bool ok = false;
        for (uint64_t mask = 0; mask < limit; ++mask){
            uint64_t crrResult = v[0];
            for (int bit = 0, temp = mask; bit < isz(v)-1; ++ bit){
                int crrOp = temp % 3;
                temp /= 3;
                switch (crrOp){
                    case 0: crrResult += v[bit+1];break;
                    case 1: crrResult *= v[bit+1];break;
                    case 2: concat(crrResult,v[bit+1]);break;
                    default: cout << "err";
                };
            }
            if (crrResult == goal){
                ok = true;
                break;
            }
        }
        if(ok) ans += goal;
    }
    cout << ans << endl;




}

int main(){
   

    part2();
    

}