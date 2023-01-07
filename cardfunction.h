#ifndef CARDFUNCTION_H
#define CARDFUNCTION_H
#include<stdlib.h>
#include<stdio.h>
#include"node.h"
#include"stack.h"
#include"setupplayer.h"

void SpecialCardFunction(node *player, int draw, int *PlayerOrder, int *OrderNumber, int playerAmount);
void Reverse(int *player_order, int player_number);
void DrawTwo(node *player);
void DrawFour(node *player);


//執行功能牌功能
void SpecialCardFunction(node *player, int draw, int *PlayerOrder, int *OrderNumber, int playerAmount){
    //+2
    if(draw == 2){
        DrawTwo(player);
    }
    //+4
    else if(draw == 4){
        DrawFour(player);
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
void DrawTwo(node *player){
    node *newnode;
    node data;
    for(i = 0; i < 2; i++){
        newnode = (node *) malloc (sizeof(node));
        data = deal();
        newnode->color = data.color;
        newnode->name = data.name;
        newnode->next = player->next;
        player->next = newnode;
    }
}

//+4
void DrawFour(node *player){
    node *newnode;
    node data;
    for(i = 0; i < 4; i++){
        newnode = (node *) malloc (sizeof(node));
        data = deal();
        newnode->color = data.color;
        newnode->name = data.name;
        newnode->next = player->next;
        player->next = newnode;
    }
}

#endif