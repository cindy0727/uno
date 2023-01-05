#ifndef DEAL_H
#define DEAL_H

#include"node.h"
#include<time.h>
#define STACKSIZE 108

int i, j;
int top = -1;

Card stack[STACKSIZE];

void setupdeck();
int empty();
int full();
Card pop();
void push(Card card);
void ShuffleDeck(Card *deck, size_t amount);
node *deal(node *list);

//設置排組
void setupdeck(){
    Card data;
    for(i = 1; i < 5; i++){
        //每個顏色的0
        j = 0;
        data.color = i;
        data.name = j;
        push(data);
        
        //每個顏色(黑以外)除0以外各2張
        for(j = 1; j < 13; j++){
            data.color = i;
            data.name = j;
            push(data);
            push(data);
        }
    }
    for(i = 0, j = 13; j < 15; j++){
        data.color = i;
        data.name = j;
        push(data);
        push(data);
        push(data);
        push(data);
    }
}

int empty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}

int full(){
    if(top == 107){
        return 1;
    }else{
        return 0;
    }
}

Card pop(){
    Card data;
    if(empty() == 0){
        data = stack[top];
        top--;
        return data;
    }
    
}

void push(Card card){
    if(full() == 0){
        top++;
        stack[top] = card;
    }
}

//發牌 範例:player2 = deal(player2);
node *deal(node *list){
    if(list == NULL){
        list = (node *) malloc (sizeof(node));
        Card data = pop();
        list->color = data.color;
        list->name = data.name;
        list->next = NULL;
        return list;
    }else{
        node *newnode;
        newnode = (node *) malloc (sizeof(node));
        Card data = pop();
        newnode->color = data.color;
        newnode->name = data.name;
        newnode->next = list;
        return newnode;   
    }
}

//洗牌
void ShuffleDeck(Card *deck, size_t amount){
    //亂數前置
    srand(time(NULL));
    if(amount > 1){
        size_t x;
        for(x = 0; x < amount; x++){
            size_t y = rand() / (RAND_MAX / (amount));
            Card t = deck[y];
            deck[y] = deck[x];
            deck[x] = t;
        }
    }
}

#endif