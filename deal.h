#ifndef DEAL_H
#define DEAL_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"node.h"

#define STACKSIZE 108
node stack[STACKSIZE];
void push(node stack[STACKSIZE]);
int top=-1;//發牌堆空
node deal();
int Empty();
node pop();
//void shuffle(node stack[i]);


//放入資料
void push(node stack[]){
	srand(time(NULL));
	int i;
	//分配紅黃綠藍牌
	for(i=0;i<100;i++){
		int normalcolor=i/25;//0為紅，1為黃，2為綠，3為黃
		int normalname=i%25;
		//
		switch(normalcolor){
			case 0:
				stack[i].color=red;
				break;
			case 1:
				stack[i].color=yellow;
				break;
			case 2:
				stack[i].color=green;
				break; 
		case 3:
				stack[i].color=blue;
				break;
		}
		switch(normalname){
			case 0:
				stack[i].name=zero;
				break;
			case 1:
				stack[i].name=one;
				break;
			case 2:
				stack[i].name=two;
				break;
			case 3:
				stack[i].name=three;
				break;
			case 4:
				stack[i].name=four;
				break;
			case 5:
				stack[i].name=five;
				break;
			case 6:
				stack[i].name=six;
				break;
			case 7:
				stack[i].name=seven;
				break;
			case 8:
				stack[i].name=eight;
				break;
			case 9:
				stack[i].name=nine;
				break;
			case 10:
				stack[i].name=skip;
				break;
			case 11:
				stack[i].name=one;
				break;
			case 12:
				stack[i].name=two;
				break;
			case 13:
				stack[i].name=three;
				break;
			case 14:
				stack[i].name=four;
				break;
			case 15:
				stack[i].name=five;
				break;
			case 16:
				stack[i].name=six;
				break;
			case 17:
				stack[i].name=seven;
				break;
			case 18:
				stack[i].name=eight;
				break;
			case 19:
				stack[i].name=nine;
				break;
			case 20:
				stack[i].name=skip;
				break;
			case 21:
				stack[i].name=reverse;
				break;
			case 22:
				stack[i].name=reverse;
				break;
			case 23:
				stack[i].name=drawtwo;
				break;
			case 24:
				stack[i].name=drawtwo;
				break;
		}
	}
	for(i=100;i<108;i++){
		stack[i].name=black;
		int j=(i-100)/4;
		switch(j){
			case 0:
				stack[i].name=wild;
				break;
			case 1:
				stack[i].name=wild_draw_four;
				break;
		}
	}
}	
//發牌（1次1張）
node deal(){
    if(Empty==0){
        node data;
    	data=stack[top];
    	top--;
    	return data;  
    }
}

//判斷是否為空堆疊
int Empty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}


#endif