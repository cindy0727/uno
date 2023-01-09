#ifndef MODE_H
#define MODE_H
#include<stdio.h>
#include<stdlib.h>
#include"node.h"
#include"stack.h"
#include"player.h"
#include"setupplayer.h"
#include"cardfunction.h"
#include"computeruser.h"
void ThreePlayer();
void FourPlayer();
void initialize();

void SetupThreePlayerCard();
void SetupFourPlayerCard();

int GameOver(int PlayerAmount);

void ComputerCurrentCard(node *player);


int i, j;
int WhoWin = -1;//誰獲勝 -1:遊戲繼續




//三人模式
void ThreePlayer(){
    PlayerNumber = 3;
    RevserseOrNot = 0;
    int player_amount = (int) sizeof(three_player_order) / sizeof(three_player_order[0]);
    
    initialize();

    //打亂順序
    //ShuffleOrder(three_player_order, player_amount);
    SetUpDeck();
    ShuffleDeck(stack, 108);
    while((stack[top].name == wild) || (stack[top].name == wild_draw_four)){
        ShuffleDeck(stack, 108);
    }
    //設置底牌
    printf("Usedcard = %p\n\n", UsedCard);
    UsedCard = DrawOne(UsedCard);
    printf("底牌是: ");
    PrintCard(UsedCard);
    printf("\n");

    //開局一人發七張牌
    SetupThreePlayerCard();
    while (GameOver(3) == 0){
        
        printf("ReverseOrNot = %d    ", RevserseOrNot);
        printf("order = %d\n", order);
        // for(i = 0; i < 3; i++){
        //     printf("%d  ", three_player_order[i]);
        // }
        // printf("\n");
        
        //真人玩家出牌
        if(three_player_order[order] == 0){
            PlayerInput();
        }
        
        //玩家2出牌
        else if(three_player_order[order] == 1){
            printf("%s\n",G(玩家2手中有:));
            //printf("");
            ComputerCurrentCard(player2);
            cardpool = computeruser(UsedCard, &player2, &drawNumber);
            if(cardpool == UsedCard){
                printf("玩家2抽了一張牌\n");
            }
            UsedCard = cardpool;
        }
        
        
        //玩家3出牌
        else if(three_player_order[order] == 2){
            printf("%s\n",B(玩家3手中有:));
            //printf("");
            ComputerCurrentCard(player3);
            //printf("%s\n",R(玩家3出牌設定中......));
        }

        printf("上一位玩家出的牌 : ");
        PrintCard(UsedCard);
        printf("\n");
        
        if(RevserseOrNot % 2 == 0){
            order = (order == 2) ? 0 : (order + 1);
        }else{
            order = (order == 0) ? player_amount : (order - 1);
        }
        
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
    PlayerNumber = 4;
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
    node *player1 = NULL;//真人玩家手中的牌
    node *player2 = NULL;//電腦玩家手中的牌
    node *player3 = NULL;//電腦玩家手中的牌
    node *player4 = NULL;//電腦玩家手中的牌
    node *UsedCard = NULL;//已出的牌
    node *cardpool = NULL;
    input = makelist(input);
}


//遊戲結束 1:遊戲結束,0:遊戲繼續
int GameOver(int PlayerAmount){
    WhoWin = -1;
    if(PlayerAmount == 3){
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
        player1 = DrawOne(player1);
        player2 = DrawOne(player2);
        player3 = DrawOne(player3);
    }
}

//開局一人7張牌
void SetupFourPlayerCard(){
    for(i = 0; i < 7; i++){
        player1 = DrawOne(player1);
        player2 = DrawOne(player2);
        player3 = DrawOne(player3);
        player4 = DrawOne(player4);
    }
}

void ComputerCurrentCard(node *player){
    //printf("您有:");
    node *tmp;
    tmp = player;
    while (tmp != NULL){
        PrintCard(tmp);
        tmp = tmp->next;
    }
    printf("\n");
}

#endif