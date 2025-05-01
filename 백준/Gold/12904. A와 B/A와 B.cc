#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string S, T;
    std::cin >> S >> T;
    int s_size = S.length();
    
    while(1) {
        
        int t_size = T.length();
        
        if(T[t_size - 1] == 'A') {
            T = T.substr(0, t_size - 1);
        }
        else if(T[t_size - 1] == 'B') {
            T = T.substr(0, t_size - 1);
            std::reverse(T.begin(), T.end());
        }
        
        if(S == T) {
            std::cout << 1;
            break;
        }
        if(S != T && S.length() == T.length()){
            std::cout << 0;
            break;
        }
    }
}