#include <iostream>
#include <string>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numberSeasons, numberEpisodesInSeasons, numberEpsOnPlatform;

    std::cin >> numberSeasons >>numberEpisodesInSeasons >> numberEpsOnPlatform;

    int arrInput[numberSeasons][numberEpisodesInSeasons];

    for(int i = 0; i < numberSeasons; i++){
        for(int j = 0; j < numberEpisodesInSeasons; j++){
            arrInput[i][j] = 0;
        }
    }
    int season, episode, count = 0;
    std::string result = "";
    for(int i = 0; i < numberEpsOnPlatform; i++){
        std::cin >> episode >> season;
        arrInput[season - 1][episode - 1] = 1;

    }
    for(int i = 0; i < numberSeasons; i++){
        for(int j = 0; j < numberEpisodesInSeasons; j++){
            if(arrInput[i][j] == 0){
                count++;
                result += std::to_string(j + 1) + " " + std::to_string(i + 1) + "\n";
            }
        }
    }
    std::cout << count << "\n" <<  result;
    return 0;
}