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

void GameOver(int PlayerAmount);

void ComputerCurrentCard(node *player);


int i, j;
int WhoWin = -1;//誰獲勝 -1:遊戲繼續

//store 
typedef struct record{
	int order;//哪位玩家(真人玩家固定1)
	int IFpass;//動作
	node *card;
	struct record *prev;
	struct record *next;
}Record;

node StartCard;
int RealPlayer[14];

Record *head = NULL;
Record *current = NULL;

void StoreAct(int order, node *cur, int IFpass){
    Record *tmp = (Record*)malloc(sizeof(Record));
    tmp->order = order;
    tmp->IFpass = IFpass;
    tmp->card = cur;

    if(current == NULL){
		current = tmp;
		head = tmp;
		tmp->prev = NULL;
		tmp->next = NULL;

	}
	else{
		current -> next = tmp;

		tmp->prev = current;
		tmp->next = NULL;
		
		current = tmp;
	}

}

//三人模式
void ThreePlayer(){
    int ifpass=0;
    PlayerNumber = 3;
    RevserseOrNot = 0;
    int player_amount = (int) sizeof(three_player_order) / sizeof(three_player_order[0]);
    
    initialize();

    //打亂順序
    ShuffleOrder(three_player_order, player_amount);
    printf("出牌順序為:");
    for(i = 0; i < 3; i++){
        if(three_player_order[i] == 0){
            printf("玩家1 ");
        }else if(three_player_order[i] == 1){
            printf("玩家2 ");
        }else if(three_player_order[i] == 2){
            printf("玩家3 ");
        }
    }
    printf("\n您為玩家1\n\n");

    SetUpDeck();
    ShuffleDeck(stack, 108);
    while((stack[top].name == wild) || (stack[top].name == wild_draw_four)){
        ShuffleDeck(stack, 108);
    }
    //設置底牌
    UsedCard = DrawOne(UsedCard);
    StartCard.color = UsedCard->color;//store
    StartCard.name = UsedCard->name;//store
    printf("底牌是: ");
    PrintCard(UsedCard);
    printf("\n\n");

    //開局一人發七張牌
    SetupThreePlayerCard();

    while (WhoWin == -1){
        
        
        //真人玩家出牌
        if(three_player_order[order] == 0){
            PlayerInput();
            SpecialCardFunction(drawNumber, three_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        
        //玩家2出牌
        else if(three_player_order[order] == 1){
            printf("%s\n",G(玩家2原本手中有:));
            ComputerCurrentCard(player2);
            cardpool = computeruser(UsedCard, &player2, &drawNumber);
            if(cardpool == UsedCard){
                ifpass=1;
                printf("玩家2抽了一張牌\n");
                StoreAct(2,cardpool, ifpass);//最新store
            }else{
                printf("玩家2出了");
                PrintCard(cardpool);
                printf("\n");
                StoreAct(2,cardpool, ifpass);//最新store
            }
            UsedCard = cardpool;
            SpecialCardFunction(drawNumber, three_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        
        //玩家3出牌
        else if(three_player_order[order] == 2){
            printf("%s\n",B(玩家3原本手中有:));
            ComputerCurrentCard(player3);
            cardpool = computeruser(UsedCard, &player3, &drawNumber);
            if(cardpool == UsedCard){
                ifpass=1;
                printf("玩家3抽了一張牌\n");
                StoreAct(3,cardpool, ifpass);//最新store
            }else{
                printf("玩家3出了");
                PrintCard(cardpool);
                printf("\n");
                StoreAct(3,cardpool, ifpass);//最新store
            }
            UsedCard = cardpool;
            SpecialCardFunction(drawNumber, three_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        GameOver(3);
        if(WhoWin == -1){
            printf("上一位玩家出的牌 : ");
            PrintCard(UsedCard);
            printf("\n");
        }
    
        if(RevserseOrNot % 2 == 0){
            order = (order == 2) ? 0 : (order + 1);
        }else{
            order = (order == 0) ? 2 : (order - 1);
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
    int ifpass=0;
    PlayerNumber = 4;
    RevserseOrNot = 0;
    int player_amount = (int) sizeof(four_player_order) / sizeof(four_player_order[0]);
    
    void initialize();
    
    //打亂順序
    ShuffleOrder(four_player_order, player_amount);
    printf("出牌順序為:");
    for(i = 0; i < 4; i++){
        if(four_player_order[i] == 0){
            printf("玩家1 ");
        }else if(four_player_order[i] == 1){
            printf("玩家2 ");
        }else if(four_player_order[i] == 2){
            printf("玩家3 ");
        }else if(four_player_order[i] == 3){
            printf("玩家4 ");
        }
    }
    printf("\n\n您為玩家1\n");

    SetUpDeck();
    ShuffleDeck(stack, 108);
    while((stack[top].name == wild) || (stack[top].name == wild_draw_four)){
        ShuffleDeck(stack, 108);
    }
    //設置底牌
    UsedCard = DrawOne(UsedCard);
    StartCard.color = UsedCard->color;//store
    StartCard.name = UsedCard->name;//store
    printf("底牌是: ");
    PrintCard(UsedCard);
    printf("\n\n");
    
    //開局一人發七張牌
    SetupFourPlayerCard();

    while (WhoWin == -1){
        
        //真人玩家出牌
        if(four_player_order[order] == 0){
            PlayerInput();
            SpecialCardFunction(drawNumber, four_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        
        //玩家2出牌
        else if(four_player_order[order] == 1){
            printf("%s\n",G(玩家2原本手中有:));
            ComputerCurrentCard(player2);
            cardpool = computeruser(UsedCard, &player2, &drawNumber);
            if(cardpool == UsedCard){
                ifpass=1;
                printf("玩家2抽了一張牌\n");
                StoreAct(2,cardpool, ifpass);//最新store
            }else{
                printf("玩家2出了");
                PrintCard(cardpool);
                printf("\n");
                StoreAct(2,cardpool, ifpass);//最新store
            }
            UsedCard = cardpool;
            SpecialCardFunction(drawNumber, four_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        
        //玩家3出牌
        else if(four_player_order[order] == 2){
            printf("%s\n",B(玩家3原本手中有:));
            ComputerCurrentCard(player3);
            cardpool = computeruser(UsedCard, &player3, &drawNumber);
            if(cardpool == UsedCard){
                ifpass=1;
                printf("玩家3抽了一張牌\n");
                StoreAct(3,cardpool, ifpass);//最新store
            }else{
                printf("玩家3出了");
                PrintCard(cardpool);
                printf("\n");
                StoreAct(3,cardpool, ifpass);//最新store
            }
            UsedCard = cardpool;
            SpecialCardFunction(drawNumber, four_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }

        //玩家4出牌
        else if(four_player_order[order] == 3){
            printf("%s\n",Y(玩家4原本手中有:));
            ComputerCurrentCard(player4);
            cardpool = computeruser(UsedCard, &player4, &drawNumber);
            if(cardpool == UsedCard){
                ifpass=1;
                printf("玩家4抽了一張牌\n");
                StoreAct(4,cardpool, ifpass);//最新store
            }else{
                printf("玩家4出了");
                PrintCard(cardpool);
                printf("\n");
                StoreAct(4,cardpool, ifpass);//最新store
            }
            UsedCard = cardpool;
            SpecialCardFunction(drawNumber, four_player_order, &order, PlayerNumber);
            //迴轉
            if(drawNumber == 6){
                if(RevserseOrNot == 0){
                    RevserseOrNot = 1;
                }else if(RevserseOrNot == 1){
                    RevserseOrNot = 0;
                }
            }
        }
        GameOver(4);
        if(WhoWin == -1){
            printf("上一位玩家出的牌 : ");
            PrintCard(UsedCard);
            printf("\n");
        }
        
        if(RevserseOrNot % 2 == 0){
            order = (order == 3) ? 0 : (order + 1);
        }else{
            order = (order == 0) ? 3 : (order - 1);
        }
        
    }

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
    RealPlayer[0] = -1; //store 
    input = makelist(input);
}


//遊戲結束 1:遊戲結束,0:遊戲繼續
void GameOver(int PlayerAmount){
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
            WhoWin = 3;
        }
    }
}

//開局一人7張牌
void SetupThreePlayerCard(){
    for(i = 0; i < 7; i++){
        player1 = DrawOne(player1);
        player2 = DrawOne(player2);
        player3 = DrawOne(player3);
    }
    //store
    if(RealPlayer[0] == -1){
        node *tmp;
        tmp = player1;
        for(int i = 0; i < 7; ++i){
            RealPlayer[i*2] = tmp->color;
            RealPlayer[i*2+1] = tmp->name;
            tmp = tmp ->next;
        }
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
    //store
    if(RealPlayer[0] == -1){
        node *tmp;
        tmp = player1;
        for(int i = 0; i < 7; ++i){
            RealPlayer[i*2] = tmp->color;
            RealPlayer[i*2+1] = tmp->name;
            tmp = tmp ->next;
        }
    }
}

void ComputerCurrentCard(node *player){
    node *tmp;
    tmp = player;
    while (tmp != NULL){
        PrintCard(tmp);
        tmp = tmp->next;
    }
    printf("\n");
}

#endif