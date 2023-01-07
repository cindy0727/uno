#ifndef MODE_H
#define MODE_H
#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"stack.h"
#include"player.h"
#include"setupplayer.h"
void ThreePlayer();
void FourPlayer();
void initialize();

void SetupThreePlayerCard();
void SetupFourPlayerCard();

int GameOver(int PlayerNumber);



int i, j;
int WhoWin = -1;//誰獲勝 -1:遊戲繼續
int order = 0;//出排順序

//三人模式
void ThreePlayer(){
    int three_player_order[3] = {0, 1, 2};//出排順序:0代表player1,以此類推
    int player_amount = (int) sizeof(three_player_order) / sizeof(three_player_order[0]);
    initialize();

    //打亂順序
    ShuffleOrder(three_player_order, player_amount);

    
    SetUpDeck();
    ShuffleDeck(stack, 108);
    

    //開局一人發七張牌
    SetupThreePlayerCard();
    while (GameOver(3) == 0){
        
        // for(i = 0; i < 3; i++){
        //     printf("%d  ", three_player_order[i]);
        // }
        // printf("\n");
        if(three_player_order[order] == 0){
            //printf("1\n");
            PlayerInput();
        }else if(three_player_order[order] == 1){
            printf("玩家2出牌設定中......\n");
        }else if(three_player_order[order] == 2){
            printf("玩家3出牌設定中......\n");
        }

        printf("上一位玩家出的牌 : ");
        PrintCard(UsedCard);
        order = (order == player_amount) ? 0 : (order + 1);

    }
    
    //獲勝玩家
    if(WhoWin == 0){
        printf("\033[1;33m恭喜您獲勝!\n\033[m");
    }else if(WhoWin == 1){
        printf("\033[1;33m玩家2獲勝!\n\033[m");
    }else if(WhoWin == 2){
        printf("\033[1;33m玩家3獲勝!\n\033[m");
    }
    
}

//四人模式
void FourPlayer(){
    int four_player_order[4] = {0, 1, 2, 3};//出排順序:0代表player1,以此類推
    int player_amount = (int) sizeof(four_player_order) / sizeof(four_player_order[0]);
    void initialize();
    
    //打亂順序
    ShuffleOrder(four_player_order, player_amount);

    SetUpDeck();
    ShuffleDeck(stack, 108);
    

    //開局一人發七張牌
    SetupThreePlayerCard();

    //獲勝玩家
    if(WhoWin == 0){
        printf("\033[1;33m恭喜您獲勝!\n\033[m");
    }else if(WhoWin == 1){
        printf("\033[1;33m玩家2獲勝!\n\033[m");
    }else if(WhoWin == 2){
        printf("\033[1;33m玩家3獲勝!\n\033[m");
    }else if(WhoWin == 3){
        printf("\033[1;33m玩家4獲勝!\n\033[m");
    }

}


void initialize(){
    player1 = makelist(player1);
    player2 = initialcomputeruser(player2);
    player3 = initialcomputeruser(player3);
    player4 = initialcomputeruser(player4);
    UsedCard = makelist(UsedCard);
    cardpool = makelist(cardpool);

}


//遊戲結束 1:遊戲結束,0:遊戲繼續
int GameOver(int PlayerNumber){
    WhoWin = -1;
    if(PlayerNumber == 3){
        if(player1 == NULL){
            WhoWin = 0;
        }else if(player2 == NULL){
            WhoWin = 1;
        }else if(player3 == NULL){
            WhoWin = 2;
        }
    }else{
        if(player1 == NULL){
            WhoWin = 0;
        }else if(player2 == NULL){
            WhoWin = 1;
        }else if(player3 == NULL){
            WhoWin = 2;
        }else if(player4 == NULL){
            WhoWin = 4;
        }
    }
    if(WhoWin != -1){
        return 1;
    }else{
        return 0;
    }
}

//開局一人7張牌
void SetupThreePlayerCard(){
    for(i = 0; i < 7; i++){
        DrawOne(player1);
        ComputerDrawOne(player2);
        ComputerDrawOne(player3);
    }
}

//開局一人7張牌
void SetupFourPlayerCard(){
    for(i = 0; i < 7; i++){
        DrawOne(player1);
        ComputerDrawOne(player2);
        ComputerDrawOne(player3);
        ComputerDrawOne(player4);
    }
}

#endif