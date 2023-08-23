#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef enum{
    VO_DO,
    VO_VANG,
    VO_XANH
}VO;

typedef struct 
{
    VO *ptr;
    int size;
}TypeBox;

// cho mot cai thung, no chua ngau nhien so vo do vang xanh, dem xem co bao nhieu doi 
 void NhapThongTin(TypeBox *value){

    char name[8];

    printf("\nNhap vao kich thuoc cua mang: ");
    scanf("%d", &(value->size));

    value->ptr = (VO*)malloc(value->size * sizeof(VO));//tao mang cap phat dong va dia chi dau tien cua mang se duoc luu vao ptr 

    for(int i = 0; i < value->size; i++)
    {
    
    lable:
       printf("Nhap gia tri tai arr[%d]: ", i);
       scanf("%s", name);

       if(strcmp((char*)"VO_DO", name) == 0)
       { 
         value->ptr[i] = VO_DO;
       }else if(strcmp((char*)"VO_VANG", name) == 0)
       {
        value->ptr[i] = VO_VANG;
       }else if(strcmp((char*)"VO_XANH", name) == 0)
       {
        value->ptr[i] = VO_XANH;
       }else{
        printf("Nhap sai dinh dang!!\n");
        goto lable;
       }
    }
    
 }
 void DemSoVo(TypeBox *value){
    int DemDo = 0;
    int DemVang = 0;
    int DemXanh = 0;
    for (int i = 0; i < value->size; i++)
    {
        if(value->ptr[i] == VO_DO){
         DemDo++;
    }else if(value->ptr[i] == VO_VANG){
         DemVang++;
    }else if(value->ptr[i] == VO_XANH){
         DemXanh++;
    }
    }
        if(DemDo % 2 == 0){
         printf("So doi vo do la: %d doi\n", DemDo/2);
        }else{
            printf("So doi vo do la: %d doi + %d chiec\n", (DemDo/2), (DemDo%2));
        }
        if(DemVang % 2 == 0){
         printf("So doi vo vang la: %d doi\n", DemVang/2);
        }else{
            printf("So doi vo vang la: %d doi + %d chiec\n", (DemVang/2), (DemVang%2));
        }
        if(DemXanh % 2 == 0){
         printf("So doi vo xanh la: %d doi\n", DemXanh/2);
        }else{
            printf("So doi vo xanh la: %d doi + %d chiec\n", (DemXanh/2), (DemXanh%2));
        }
    

 }
int main(){
     TypeBox value;
     NhapThongTin(&value);
     DemSoVo(&value);


    return 0;
}
