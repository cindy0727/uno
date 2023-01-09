#ifndef CARDFUNCTION_H
#define CARDFUNCTION_H
#include<stdlib.h>
#include<stdio.h>
#include"node.h"
#include"stack.h"
#include"setupplayer.h"
#include"player.h"

void SpecialCardFunction(node *player, int draw, int *PlayerOrder, int *OrderNumber, int playerAmount);
void Reverse(int *player_order, int player_number);
void DrawTwo(int *playerOrder, int orderNumber, int playerAmount);
void DrawFour(int *playerOrder, int orderNumber, int playerAmount);


//執行功能牌功能  格式(以玩家2為): SpecialCardFunction(player2, draw, ); 其他3個參數我來填
void SpecialCardFunction(node *player, int draw, int *PlayerOrder, int *OrderNumber, int playerAmount){
    //+2
    if(draw == 2){
        DrawTwo(PlayerOrder, *OrderNumber, playerAmount);
    }
    //+4
    else if(draw == 4){
        DrawFour(PlayerOrder, *OrderNumber, playerAmount);
    }
    //skip
    else if(draw == 5){
        *OrderNumber = (*OrderNumber == playerAmount - 1) ? 0 : (*OrderNumber + 1); 
    }
    //reverse
    else if(draw == 6){
        Reverse(PlayerOrder, playerAmount);
    }
}

//迴轉: player_order[]:玩家出排順序陣列、player_number:玩家數量
void Reverse(int *player_order, int player_number){
    int tmp;
    for(int low = 0, high = player_number - 1; low < high; low++, high--){
        tmp = player_order[low];
        player_order[low] = player_order[high];
        player_order[high] = tmp;
    }
}

//+2
void DrawTwo(int *playerOrder, int orderNumber, int playerAmount){

    if(playerAmount == 3){
        if(playerOrder[orderNumber] == 0){
            for(i = 0; i < 2; i++){
                player2 = DrawOne(player2);
            }
        }else if(playerOrder[orderNumber] == 1){
            for(i = 0; i < 2; i++){
                player3 = DrawOne(player3);
            }
        }else if(playerOrder[orderNumber] == 2){
            for(i = 0; i < 2; i++){
                player1 = DrawOne(player1);
            }
        }
    }else if(playerAmount == 4){
        if(playerOrder[orderNumber] == 0){
            for(i = 0; i < 2; i++){
                player2 = DrawOne(player2);
            }
        }else if(playerOrder[orderNumber] == 1){
            for(i = 0; i < 2; i++){
                player3 = DrawOne(player3);
            }
        }else if(playerOrder[orderNumber] == 2){
            for(i = 0; i < 2; i++){
                player4 = DrawOne(player4);
            }
        }else if(playerOrder[orderNumber] == 3){
            for(i = 0; i < 2; i++){
                player1 = DrawOne(player1);
            }
        }
    }
}

//+4
void DrawFour(int *playerOrder, int orderNumber, int playerAmount){
    if(playerAmount == 3){
        if(playerOrder[orderNumber] == 0){
            for(i = 0; i < 4; i++){
                player2 = DrawOne(player2);
            }
        }else if(playerOrder[orderNumber] == 1){
            for(i = 0; i < 4; i++){
                player3 = DrawOne(player3);
            }
        }else if(playerOrder[orderNumber] == 2){
            for(i = 0; i < 4; i++){
                player1 = DrawOne(player1);
            }
        }
    }else if(playerAmount == 4){
        if(playerOrder[orderNumber] == 0){
            for(i = 0; i < 4; i++){
                player2 = DrawOne(player2);
            }
        }else if(playerOrder[orderNumber] == 1){
            for(i = 0; i < 4; i++){
                player3 = DrawOne(player3);
            }
        }else if(playerOrder[orderNumber] == 2){
            for(i = 0; i < 4; i++){
                player4 = DrawOne(player4);
            }
        }else if(playerOrder[orderNumber] == 3){
            for(i = 0; i < 4; i++){
                player1 = DrawOne(player1);
            }
        }
    }
}

#endif