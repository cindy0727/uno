#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

//參數
typedef struct node_t
{
    int card;//哪張卡片
    
}node;
//為所有牌編碼

//紅牌0~24(小於25)
//數字牌 red21代表紅色數字2第一張
#define red0 0
#define red11 1
#define red21 2 
#define red31 3
#define red41 4
#define red51 5
#define red61 6
#define red71 7
#define red81 8
#define red91 9
#define red12 11
#define red22 12
#define red32 13
#define red42 14
#define red52 15
#define red62 16
#define red72 17
#define red82 18
#define red92 19
//帶紅色功能牌
//skip牌除以10餘數為0
#define redskip1 10
#define redskip2 20
//reverse牌-20/2餘數為1
#define redreverse1 21
#define redreverse2 23
//drawtwo牌-20/2餘數為0
#define reddrawtwo1 22
#define reddraetwo2 24

//黃牌25~49
#define yellow0 25
#define yellow11 31
#define yellow21 32
#define yellow31 33
#define yellow41 34
#define yellow51 35
#define yellow61 36
#define yellow71 37
#define yellow81 38
#define yellow91 39
#define yellow12 41
#define yellow22 42
#define yellow32 43
#define yellow42 44
#define yellow52 45
#define yellow62 46
#define yellow72 47
#define yellow82 48
#define yellow92 49
//帶黃色功能牌
//skip牌除以10餘數為0
#define yellowskip1 30
#define yellowskip2 40
//reverse牌-26/2餘數為1
#define yellowreverse1 27
#define yellowreverse2 29
//drawtwo牌-26/2餘數為0
#define yellowdrawtwo1 26
#define yellowdrawtwo2 28

//綠牌50~74
#define green0 50
#define green11 51
#define green21 52 
#define green31 53
#define green41 54
#define green51 55
#define green61 56
#define green71 57
#define green81 58
#define green91 59
#define green12 61
#define green22 62
#define green32 63
#define green42 64
#define green52 65
#define green62 66
#define green72 67
#define green82 68
#define green92 69
//帶綠色功能牌
//skip牌除以10餘數為0
#define greenskip1 60
#define greenskip2 70
//reverse牌-70/2餘數為1
#define greenreverse1 71
#define greenreverse2 73
//drawtwo牌-70/2餘數為0
#define greendrawtwo1 72
#define greendraetwo2 74

//藍牌75~99
#define blue0 75
#define blue11 81
#define blue21 82 
#define blue31 83
#define blue41 84
#define blue51 85
#define blue61 86
#define blue71 87
#define blue81 88
#define blue91 89
#define blue12 91
#define blue22 92
#define blue32 93
#define blue42 94
#define blue52 95
#define blue62 96
#define blue72 97
#define blue82 98
#define blue92 99
//帶藍色功能牌
//skip牌除以10餘數為0
#define blueskip1 80
#define blueskip2 90
//reverse牌-76/2餘數為1
#define bluereverse1 77
#define bluereverse2 79
//drawtwo牌-76/2餘數為0
#define bluedrawtwo1 76
#define bluedraetwo2 78

//黑色功能牌100~107
//wild牌-100/2餘數為1
#define wild1 101
#define wild2 103
#define wild3 105
#define wild4 107
//wilddrawfour牌-100/2餘數為0
#define wilddrawfour1 100
#define wilddrawfour2 102
#define wilddrawfour3 104
#define wilddrawfour4 106



#endif