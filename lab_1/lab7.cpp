#include <iostream>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numbersDepartments;
    std::string results;
    std::cin >> numbersDepartments;
    for (int  i = 0; i < numbersDepartments; i++){
        int numbersParticipants;
        std::cin >> numbersParticipants;
        char sign[2];

        int minCondition = 15, maxCondition = 30, temp;
        for (int j = 0; j < numbersParticipants; j++){
            std::cin >> sign[0] >> sign[1] >> temp;
            if(sign[0] == '>'){
                if (minCondition <= temp)
                    minCondition = temp;
            }
            else
                if(maxCondition >= temp)
                    maxCondition = temp;
                
            if (maxCondition >= minCondition)
                results += std::to_string(minCondition) + "\n";
            else
                results += "-1\n";
        }   
    }
    std::cout << results;
    return 0; 
}