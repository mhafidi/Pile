#include<stdlib.h>
#include<stdio.h>
 
#include "Pile.h"
 
static TPile* TPile_Init(TPile*);
 
TPile TPile_Create()
{
       TPile This;
       TPile_Init(&This);
       This.Free = TPile_Free;
       return This;
}
/******************************************************************************/
 
TPile* New_TPile()
{
       TPile *This = malloc(sizeof(TPile));
       if(!This) return NULL;
       TPile_Init(This);
       This->Free = TPile_New_Free;
       return This;
}
/******************************************************************************/
 
static void TPile_Init(TPile *This)
{
       This->Push = TPile_Push;
       This->Pop = TPile_Pop;
       This->Clear = TPile_Clear;
       This->Length = TPile_Length;
       This->View = TPile_View;
       This->Nombre = 0;
       This->Top = NULL;
}
/******************************************************************************/
 
int TPile_Push(TPile *This, int Val)
{
        Titem *new_item = malloc(sizeof(Titem));
        if(!new_item) return ITEM_ALLOC_ERROR;
        new_item->Value = Val;
        new_item->prec = This->Top;
        This->Top = new_item;
        This->Nombre++;
        return 0;
}
/******************************************************************************/
 
int TPile_Pop(TPile *This)
{
        int Val;
        Titem *tmp;
        if(!This->Top) return PILE_EMPTY;
        tmp = This->Top->prec;
        Val = This->Top->Value;
        free(This->Top);
        This->Top = tmp;
        This->Nombre--;
        return Val;
}
/******************************************************************************/
 
void TPile_Clear(TPile *This)
{
        Titem *tmp;
        while(This->Top)
          {
             tmp = This->Top->prec;
             free(This->Top);
             This->Top = tmp;
          }
        This->Nombre = 0;
}
/******************************************************************************/
 
int TPile_Length(TPile *This)
{
        return This->Nombre;
}
/******************************************************************************/
 
void TPile_View(TPile *This)
{
       Titem *tmp = This->Top;
       while(tmp)
          {
             printf("%d\n",tmp->Value);
             tmp = (*tmp).prec;
          }
}
/******************************************************************************/
 
void TPile_Free(TPile *This)
{
        TPile_Clear(This);
        puts("Destruction de la pile static.\n");
}
/******************************************************************************/
 
void TPile_New_Free(TPile *This)
{
        if(This) TPile_Clear(This);
        free(This);        
        puts("Destruction de la pile dynamique.\n");
}
