#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#include "node.h"
#include "mode.h"

#define STACKSIZE 500
//getopt使用
#include<ctype.h>
#include<unistd.h>
extern char *ptarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;
int getopt(int argc,char *const *argv,const char *optstring);

int ch;
bool store = false;
bool load = false;

FILE *fptr;
//開新局為0,載入歷史紀錄為1  
int NeworOld;

typedef struct record{
	int x;//哪位玩家
	node *player1;//真人玩家的手牌
	node *cardpool;//目前牌池裡的牌
	char computerplay;//電腦玩家出牌
	char realplay;//真人玩家出牌
	char computerdraw;//電腦玩家抽牌
	char realdraw;//真人玩家抽牌
	struct record *prev;
	struct record *next;
}Record;
//指標
Record *head = NULL;
Record *current = NULL;
//放入資料
void push(int x,node *player1,node *cardpool,char computerplay,char realplay,char computerdraw,char realdraw);


int main(int argc,char *argv[]){

	//getopt
	opterr=0;
	while((ch=getopt(argc,argv,"ns:l:"))!=-1){
		switch(ch){
			case 'n':
				//printf("-n被印出");
				NeworOld=0;
				break;

			case 's':
				//printf("-s被印出 %s",optarg);
				store = true;
				if((fptr=fopen(optarg,"w"))==NULL){
					printf("File can not be opened.\n");
					return 0;
				}
				NeworOld=0;
				break;
			case 'l':
				//printf("-l被印出 %s",optarg);
				load = true;
				if((fptr=fopen(optarg,"r"))==NULL){
					printf("File can not be opened.\n");
					return 0;
				}
				NeworOld =1;
				break;
		}
	}
	//開始新局
	if(NeworOld==0){
		int i;
		printf("請選擇三人局或四人局\n");
		printf("三人局請輸入3，四人局請輸入4\n");
		scanf("%d",&i);
		if(i==3){
			ThreePlayer();
		}
		else if(i==4){
			FourPlayer();
		}
	}
	//store
		if(store){
			printf("遊戲開始\n");
			fprintf(fptr,"%s\n",head->player1);
			head = head->next;
			while(head != NULL){
				//此輪電腦出牌
				if(head->realplay==NULL&&head->computerdraw==NULL&&head->realdraw==NULL){
					fprintf(fptr,"%d %s %s %s\n",head->x,head->computerplay,head->cardpool,head->player1);
					head = head->next;
				}
				//此輪電腦抽牌
				else if(head->realplay==NULL&&head->computerplay==NULL&&head->realdraw==NULL){
					fprintf(fptr,"%d %s %s %s\n",head->x,head->computerdraw,head->cardpool,head->player1);
					head = head->next;
				}
				//此輪玩家出牌
				else if(head->computerplay==NULL&&head->computerdraw==NULL&&head->realdraw==NULL){
					fprintf(fptr,"%d %s %s %s\n",head->x,head->realplay,head->cardpool,head->player1);
					head = head->next;
				}
				//此輪玩家抽牌
				else if(head->realplay==NULL&&head->computerdraw==NULL&&head->computerplay==NULL){
					fprintf(fptr,"%d %s %s %s\n",head->x,head->realdraw,head->cardpool,head->player1);
					head = head->next;
				}
			}
		}
		//fprintf(fptr,"%c", SBL);
		//load
		if(load){

		}

	fclose(fptr);
	return 0;
}


//放入資料
void push(int x,node *player1,node *cardpool,char computerplay,char realplay,char computerdraw,char realdraw){
	Record *tmp = (Record*)malloc(sizeof(Record));
	tmp->x = x;
	tmp->player1 = player1;
	tmp->cardpool = cardpool;
	tmp->computerplay= computerplay;
	tmp->realplay = realplay;
	tmp->computerdraw = computerdraw;
	tmp->realdraw= realdraw;


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