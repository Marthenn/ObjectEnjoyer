#include "GameCapsa.hpp"

#include <iostream>
using namespace std;

template <typename T>
GameCapsa<T>::GameCapsa(){
    splashScreen();
}

template <typename T>
void GameCapsa<T>::splashScreen(){
    cout << "Game Capsa splash screen\n\n";
}

template <typename T>
void GameCapsa<T>::start(){

}

template <typename T>
bool GameCapsa<T>::isWinning(){
    // return (winningPlayer()!=0)
    return false;
}


template <typename T>
void GameCapsa<T>::newGame(){
    // deck card baru
}

template <typename T>
void GameCapsa<T>::endOfGame(){
}

template <typename T>
void GameCapsa<T>::startRound(){


}

template <typename T>
void GameCapsa<T>::playerAction(int cmd){

}

template <typename T>
string GameCapsa<T>::inputCommand(){
}

template <typename T>
string GameCapsa<T>::isCommandValid(string userCommand){

    string oriCommand = userCommand;
    transform(userCommand.begin(),userCommand.end(),userCommand.begin(),::tolower);

    map<string,Command>::iterator it;
    it = cmd.find(userCommand);

    if (it != cmd.end()){
        //userCommand valid
        return it->first;
    } else{
        //userCommand invalid
        throw CommandInvalid(oriCommand);
    }
}


template GameCapsa<int>::GameCapsa();
