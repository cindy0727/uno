#ifndef STACK_H
#define STACK_H
#include<time.h>
#include"node.h"
#define STACKSIZE 108

int i, j;
int top = -1;

node stack[STACKSIZE];

node *UsedCard = NULL;//已出的牌
node *cardpool = NULL;

node SetCard(int color, int name);
void SetUpDeck();
void ShuffleDeck(node deck[], size_t amount);
int empty();
int full();
void push(node data);
node pop();
node deal();
void reshuffledeck();

node SetCard(int Color, int Name){
    node card;
    card.color = Color;
    card.name = Name;
    card.next = NULL;
    return card;
}

void SetUpDeck(){
    node data;
    //red, yellow, green, blue
    for(i = 1; i < 5; i++){
        //每個顏色的0
        j = 0;
        data = SetCard(i, j);
        push(data);

        //每個顏色(黑以外)除0以外各2張
        for(j = 1; j < 13; j++){
            data = SetCard(i, j);
            push(data);
            push(data);
        }
    }
    //black
    for(i = 0, j = 13; j < 15; j++){
        data = SetCard(i ,j);
        push(data);
        push(data);
        push(data);
        push(data);
    }
}

void ShuffleDeck(node deck[], size_t amount){
    srand(time(NULL));
    if(amount > 1){
        size_t x;
        for(x = 0; x < amount; x++){
            size_t y = rand() / (RAND_MAX / (amount));
            node t = deck[y];
            deck[y] = deck[x];
            deck[x] = t;
        }
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

void push(node data){
    if(full() != 1){
        top++;
        stack[top] = data;
        stack[top].next = NULL;
    }
}

node pop(){
    node card;
    card = stack[top];
    top--;
    return card;
}

node deal(){
    node card;
    //如果無牌可抽，將已出的牌回收，重新放到stack
    if(empty() == 1){
        reshuffledeck();
    }
    card = pop();
    return card;
}

void reshuffledeck(){
    while(UsedCard != NULL){
        if((UsedCard == NULL) || (UsedCard->next == NULL)){
            
            break;
        }else{
            node *nextptr;
            nextptr = UsedCard->next;
            UsedCard->next = nextptr->next;
            free(nextptr);
        }
    }
    printf("abcdefg\n");
    SetUpDeck();
    ShuffleDeck(stack, 108);
}

#endif