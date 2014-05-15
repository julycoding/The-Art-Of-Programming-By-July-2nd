#include <stdio.h>  
#include <ctype.h>     //多谢citylove指正。  
//crytTable[]里面保存的是HashString函数里面将会用到的一些数据，在prepareCryptTable  
//函数里面初始化  
unsigned long cryptTable[0x500];  
  
//以下的函数生成一个长度为0x500（合10进制数：1280）的cryptTable[0x500]  
void prepareCryptTable()  
{   
    unsigned long seed = 0x00100001, index1 = 0, index2 = 0, i;  
  
    for( index1 = 0; index1 < 0x100; index1++ )  
    {   
        for( index2 = index1, i = 0; i < 5; i++, index2 += 0x100 )  
        {   
            unsigned long temp1, temp2;  
  
            seed = (seed * 125 + 3) % 0x2AAAAB;  
            temp1 = (seed & 0xFFFF) << 0x10;  
  
            seed = (seed * 125 + 3) % 0x2AAAAB;  
            temp2 = (seed & 0xFFFF);  
  
            cryptTable[index2] = ( temp1 | temp2 );   
       }   
   }   
}  
  
//以下函数计算lpszFileName 字符串的hash值，其中dwHashType 为hash的类型，  
//在下面GetHashTablePos函数里面调用本函数，其可以取的值为0、1、2；该函数  
//返回lpszFileName 字符串的hash值；  
unsigned long HashString( char *lpszFileName, unsigned long dwHashType )  
{   
    unsigned char *key  = (unsigned char *)lpszFileName;  
unsigned long seed1 = 0x7FED7FED;  
unsigned long seed2 = 0xEEEEEEEE;  
    int ch;  
  
    while( *key != 0 )  
    {   
        ch = toupper(*key++);  
  
        seed1 = cryptTable[(dwHashType << 8) + ch] ^ (seed1 + seed2);  
        seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;   
    }  
    return seed1;   
}  
  
//在main中测试argv[1]的三个hash值：  
//./hash  "arr/units.dat"  
//./hash  "unit/neutral/acritter.grp"  
int main( int argc, char **argv )  
{  
    unsigned long ulHashValue;  
    int i = 0;  
  
    if ( argc != 2 )  
    {  
        printf("please input two arguments/n");  
        return -1;  
    }  
  
     /*初始化数组：crytTable[0x500]*/  
     prepareCryptTable();  
  
     /*打印数组crytTable[0x500]里面的值*/  
     for ( ; i < 0x500; i++ )  
     {  
         if ( i % 10 == 0 )  
         {  
             printf("/n");  
         }  
  
         printf("%-12X", cryptTable[i] );  
     }  
  
     ulHashValue = HashString( argv[1], 0 );  
     printf("/n----%X ----/n", ulHashValue );  
  
     ulHashValue = HashString( argv[1], 1 );  
     printf("----%X ----/n", ulHashValue );  
  
     ulHashValue = HashString( argv[1], 2 );  
     printf("----%X ----/n", ulHashValue );  
  
     return 0;  
}  
