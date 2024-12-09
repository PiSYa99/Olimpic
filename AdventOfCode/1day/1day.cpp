#include <bits/stdc++.h>

std::ifstream fin("in.txt");


#define intsize(a) (int)a.size()
void part1(){
    std::vector<int> f,s;

    for (int a,b; fin >> a >> b;){
        f.push_back(a);
        s.push_back(b);
    }
    uint64_t ans{};
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    for (int i = 0; i < intsize(f); ++i){
        ans += abs(f[i]-s[i]);
    }
    std::cout << ans;
}

void part2(){
    std::vector<int> f,s;

    for (int a,b; fin >> a >> b;){
        f.push_back(a);
        s.push_back(b);
    }
    uint64_t ans{};
    
    for (int i = 0; i < intsize(f); ++i){
        ans += f[i]*std::count(s.begin(),s .end(), f[i]);
    }
    std::cout << ans;


}


int main(){
    part2();

}