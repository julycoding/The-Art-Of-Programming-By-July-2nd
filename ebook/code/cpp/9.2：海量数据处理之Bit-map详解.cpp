//定义每个Byte中有8个Bit位  
#include ＜memory.h＞  
#define BYTESIZE 8  
void SetBit(char *p, int posi)  
{  
    for(int i=0; i ＜ (posi/BYTESIZE); i++)  
    {  
        p++;  
    }  
  
    *p = *p|(0x01＜＜(posi%BYTESIZE));//将该Bit位赋值1  
    return;  
}  
  
void BitMapSortDemo()  
{  
    //为了简单起见，我们不考虑负数  
    int num[] = {3,5,2,10,6,12,8,14,9};  
  
    //BufferLen这个值是根据待排序的数据中最大值确定的  
    //待排序中的最大值是14，因此只需要2个Bytes(16个Bit)  
    //就可以了。  
    const int BufferLen = 2;  
    char *pBuffer = new char[BufferLen];  
  
    //要将所有的Bit位置为0，否则结果不可预知。  
    memset(pBuffer,0,BufferLen);  
    for(int i=0;i＜9;i++)  
    {  
        //首先将相应Bit位上置为1  
        SetBit(pBuffer,num[i]);  
    }  
  
    //输出排序结果  
    for(int i=0;i＜BufferLen;i++)//每次处理一个字节(Byte)  
    {  
        for(int j=0;j＜BYTESIZE;j++)//处理该字节中的每个Bit位  
        {  
            //判断该位上是否是1，进行输出，这里的判断比较笨。  
            //首先得到该第j位的掩码（0x01＜＜j），将内存区中的  
            //位和此掩码作与操作。最后判断掩码是否和处理后的  
            //结果相同  
            if((*pBuffer&(0x01＜＜j)) == (0x01＜＜j))  
            {  
                printf("%d ",i*BYTESIZE + j);  
            }  
        }  
        pBuffer++;  
    }  
}  
  
int _tmain(int argc, _TCHAR* argv[])  
{  
    BitMapSortDemo();  
    return 0;  
} 
