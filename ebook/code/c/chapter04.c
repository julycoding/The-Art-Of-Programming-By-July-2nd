/*
 * Zaks Wang
 * ultimate010@gmail.com
 * ultimate010.tk
 * 2014-1-8
 */
//字符串操作函数,strstr,strlen,strcpy
#include <string.h>
#include <stdio.h>
#include <assert.h>



/*
 * 字符串查找
 * @stra 字符串a
 * @strb 字符串b
 * @return 找到返回stra中的位置,找不到返回NULL
 */
const char * myStrstr(const char * stra,const char * strb){
  assert(stra != NULL && strb != NULL);
  const char *pa = stra,* pb = strb;
  if(*pa == '\0' || *pb == '\0'){
	return NULL;
  }
  while(*pa != '\0' && *pb != '\0'){
	if(*pb == *pa){
	  pb++;
	}else{
	  pb = strb; //从新开始
	}
	pa++;
  }
  if(*pb == '\0'){
	return (pa - (pb - strb));
  }
  return NULL;
}
/*
 * 找出字符串中第一个没重复的字符
 * @str 待查找的字符串
 * @return 找到返回字符,否则返回'\0'
 */
char firstSingleChar(const char * str){
  int table[256] = {0};
  const char * p = str;
  while(*p){
	table[(int)*p++]++;
  }
  p = str;
  while(*p){
	if(table[(int)*p] == 1){
	  return *p;
	}
	p++;
  }
  return '\0';
}
/*
 * 字符串拷贝函数
 * @dest 目标字符串指针
 * @source 源字符串指针
 * @return 指向目标字符串的指针
 */
char * myStrcpy(char * dest,const char * source){
  if(dest == source){
	return dest;
  }
  assert(dest != NULL && source != NULL);
  char * p = dest;
  while((*p++ = *source++) != '\0');
  return dest;
}
/*
 * 字符串拆分
 * @stra 待拆分的字符串
 * @strb 分隔符
 * @return 下一个开始位置
 */
char * myStrtok( char *stra, const char *strb ){
  assert(strb != NULL);
  static char * pStart = NULL;
  if(stra){ // new str to tok
	pStart = stra;
  }
  char * ret = pStart;
  if(pStart == NULL){
	return NULL;
  }
  pStart = (char *)myStrstr(pStart,strb);
  if(pStart != NULL){ //找到
	while(*strb++){
	  *pStart++ = '\0';
	}
  }
  return ret;
}
/*
 * 大部分情况和memcpy一样,不同之处可以处理源和目的重叠的情况
 * @to 目的指针
 * @from 源指针
 * @count 长度,byte为单位
 * @return 目的指针
 */
void *myMemmove( void *to, const void *from, size_t count ){
  assert(to != NULL && from != NULL);
  if(from == to){
	return to;
  }
  char * pTo = (char *)to;
  char * pFrom = (char *)from;
  if(from < to && (from + count > to)){ //from在前to在后,且from + count大于to
	while(count-- > 0){
	  *(pTo + count) = *(pFrom +  count);
	}
  }else{
	//简单情况直接拷贝
	while(count-- > 0){
	  *pTo++ = *pFrom++;
	}
  }
  return to;
}

int main(){
  char stra[50] = {0};
  char strb[50] = {0};
  char strc[50] = {0};
  sprintf(stra,"bbeeffABABcdfe");
  sprintf(strb,"AB");
  sprintf(strc,"ab");
  const char * str;
  //strstr
  if(NULL != (str = myStrstr(stra,strb))){
	printf("The str of %s in %s is %s\n",strb,stra,str);
  }else{
	printf("The %s is not in %s\n",strb,stra);
  }
  if(NULL != (str = myStrstr(stra,strc))){
	printf("The str of %s in %s is %s\n",strc,stra,str);
  }else{
	printf("The %s is not in %s\n",strc,stra);
  }

  //firstSingleChar
  printf("The firstSingleChar of %s is %c\n",stra,firstSingleChar(stra));

  //myStrcpy
  printf("The copy of %s is %s\n",stra,myStrcpy(strb,stra));

  //myStrtok
  char strd[] = "now # is the time for all # good men to come to the # aid of their country";
  char delims[] = "#";
  char *result = NULL;
  result = myStrtok( strd, delims );
  while( result != NULL ) {
	printf( "result is \"%s\"\n", result );
	result = myStrtok( NULL, delims );
  }
  printf("After myStrtok the str is %s \n",strd);
  char stre[] = "abcdefghijklmn";
  printf("Before the str is %s \n",stre);
  myMemmove(stre,stre + 3,8);
  printf("After memmove the str is %s \n",stre);
  return 0;
}

