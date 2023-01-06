#include "function.h"

int test()
{
    int testdraw;
    int i;
    i = 0;
    node *test;
    node *testinput;
    node *computer;
    test = (node *)malloc(sizeof(node));
    testinput = (node *)malloc(sizeof(node));
    test->color = red;
    test->name = seven;
    test->next = NULL;
    test->prev = NULL;
    node *tmp;
    node *tmp1;
    node *tmp2;
    node *tmpcom;
    node *tmpcom1;
    // tmp2 = test;

    while(i < 7)
    {
        if(i == 0)
        {
            computer = (node *)malloc(sizeof(node));
            printf("enter the color and name:");
            scanf("%d %d", &computer->color, &computer->name);
            computer->prev = NULL;
            computer->next = NULL;
            i++;
            tmpcom1 = computer;
        }
        if(i > 0)
        {
            node *tmpcom;
            tmpcom = (node *)malloc(sizeof(node));
            printf("enter the color and name:");
            scanf("%d %d", &tmpcom->color, &tmpcom->name);
            tmpcom->prev = tmpcom1;
            tmpcom->next = NULL;
            tmpcom1->next = tmpcom;
            tmpcom1 = tmpcom;
            i++;
        }
    }

    tmp = computer;
    printf("computer:");
    for(int j = 0; tmp != NULL; j++)
    {
        printf("%d %d ", tmp->color, tmp->name);
        tmp1 = tmp;
        tmp = tmp->next;
    }
    printf("\n");

    test = (node *)malloc(sizeof(node));
    test->color = red;
    test->name = one;
    test->prev = NULL;
    test->next = NULL;

    tmp2 = test;
    printf("牌池:%d %d %d\n", test->color, test->name, testdraw);
    for(int i = 0; i < 5; i++)
    {
        printf("i = %d\n", i);
        test = computeruser(test, &computer, &testdraw);
        printf("pokerpile %d %d", test->color, test->name);
        printf("\n");
        printf("牌池:%d %d %d\n", test->color, test->name, testdraw);
        tmp = computer;
        for(int j = 0; tmp != NULL; j++)
        {
            printf("%d %d ", tmp->color, tmp->name);
            tmp1 = tmp;
            tmp = tmp->next;
        }
        printf("\n\n");
    }

    printf("最後牌池:");
    for(int j = 0; tmp2!= NULL; j++)
    {
        printf("%d %d \n", tmp2->color, tmp2->name);
        tmp2 = tmp2->next;
    }
    printf("\n");


   /*printf("\n");
    tmp = computer;
    for(int i = 0; i < 7; i++)
    {
        printf("%d %d \n", tmp->color, tmp->name);
        tmp1 = tmp;
        tmp = tmp->next;

    }*/

    /*for(int i = 0; i < 6; i++)
    {
        printf("%d %d \n", tmp1->color, tmp1->name);
        tmp1 = tmp1->prev;
    }*/




    return 0;
}