#ifndef PLAYER_H
#define PLAYER_H
#include<stdio.h>
#include<string.h>
#include"node.h"
#include"mode.h"
#include"function.h"

#define R(card) "\033[1;31m"#card"\033[m" //紅色的牌
#define Y(card) "\033[1;33m"#card"\033[m" //黃色的牌
#define G(card) "\033[1;32m"#card"\033[m" //綠色的牌
#define B(card) "\033[1;34m"#card"\033[m" //藍色的牌

int drawNumber;

void PlayerInput();
node *InputToNode();
void PlayerCurrentCard();
char InputColor[];
char InputName[];
node *UsedCard = NULL;

void PlayerInput(){
    node *input;
    printf("先輸入顏色再輸入牌\n");
    printf("請輸入您想出的牌:");
    scanf("%s", InputColor);
    scanf("%s", InputName);

    input = InputToNode(InputColor, InputName);
    node *cardpool = ruleandrenewpokerpile(UsedCard, input, &drawNumber);
    while (UsedCard == cardpool){
        printf("\033[1;33m輸入不正確!請重新輸入!\n\033[m");
        printf("請輸入您想出的牌:");
        scanf("%s", InputColor);
        scanf("%s", InputName);
        cardpool = ruleandrenewpokerpile(UsedCard, input, &drawNumber);
    }
    UsedCard = cardpool;
}

node *InputToNode(char Color[], char Name[]){
    node *card;
    card->next = NULL;

    if(strcmp(Color, "黑")){
        card->color = black;
    }else if(strcmp(Color, "紅")){
        card->color = red;
    }else if(strcmp(Color, "黃")){
        card->color = yellow;
    }else if(strcmp(Color, "綠")){
        card->color= green;
    }else if(strcmp(Color, "藍")){
        card->color = blue;
    }else{
        card->color = -1;
    }

    if(strcmp(Name, "0")){
        card->name = zero;
    }else if(strcmp(Name, "1")){
        card->name = one;
    }else if(strcmp(Name, "2")){
        card->name = two;
    }else if(strcmp(Name, "3")){
        card->name = three;
    }else if(strcmp(Name, "4")){
        card->name = four;
    }else if(strcmp(Name, "5")){
        card->name = five;
    }else if(strcmp(Name, "6")){
        card->name = six;
    }else if(strcmp(Name, "7")){
        card->name = seven;
    }else if(strcmp(Name, "8")){
        card->name = eight;
    }else if(strcmp(Name, "9")){
        card->name = nine;
    }else if(strcmp(Name, "禁止")){
        card->name = skip;
    }else if(strcmp(Name, "迴轉")){
        card->name = reverse;
    }else if(strcmp(Name, "+2")){
        card->name = drawtwo;
    }else if(strcmp(Name, "萬用")){
        card->name = wild;
    }else if(strcmp(Name, "+4")){
        card->name = wild_draw_four;
    }else{
        card->name = -1;
    }
    return card;
}

void PlayerCurrentCard(){
    node *tmp;
    tmp = player1;
    while (tmp != NULL)    {
        
    }
}

#endif