//24.4、暴雪的Hash算法
//函数prepareCryptTable以下的函数生成一个长度为0x500（合10进制数：1280）的cryptTable[0x500]  
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


//函数HashString以下函数计算lpszFileName 字符串的hash值，其中dwHashType 为hash的类型 
unsigned long HashString(const char *lpszkeyName, unsigned long dwHashType )  
{  
	unsigned char *key  = (unsigned char *)lpszkeyName;  
	unsigned long seed1 = 0x7FED7FED;  
	unsigned long seed2 = 0xEEEEEEEE;  
	int ch;  

	while( *key != 0 )  
	{  
		ch = *key++;  
		seed1 = cryptTable[(dwHashType<<8) + ch] ^ (seed1 + seed2);  
		seed2 = ch + seed1 + seed2 + (seed2<<5) + 3;  
	}  
	return seed1;  
} 


//函数GetHashTablePos下述函数为在Hash表中查找是否存在目标字符串，有则返回要查找字符串的Hash值，无则return -1.  
int GetHashTablePos( har *lpszString, SOMESTRUCTURE *lpTable )   
	//lpszString要在Hash表中查找的字符串，lpTable为存储字符串Hash值的Hash表。  
{   
	int nHash = HashString(lpszString);  //调用上述函数HashString，返回要查找字符串lpszString的Hash值。  
	int nHashPos = nHash % nTableSize;  

	if ( lpTable[nHashPos].bExists  &&  !strcmp( lpTable[nHashPos].pString, lpszString ) )   
	{  //如果找到的Hash值在表中存在，且要查找的字符串与表中对应位置的字符串相同，  
		return nHashPos;    //返回找到的Hash值  
	}   
	else  
	{  
		return -1;    
	}   
}  


//函数GetHashTablePos中，lpszString 为要在hash表中查找的字符串；lpTable 为存储字符串hash值的hash表；nTableSize 为hash表的长度：   
int GetHashTablePos( char *lpszString, MPQHASHTABLE *lpTable, int nTableSize )  
{  
	const int  HASH_OFFSET = 0, HASH_A = 1, HASH_B = 2;  

	int  nHash = HashString( lpszString, HASH_OFFSET );  
	int  nHashA = HashString( lpszString, HASH_A );  
	int  nHashB = HashString( lpszString, HASH_B );  
	int  nHashStart = nHash % nTableSize;  
	int  nHashPos = nHashStart;  

	while ( lpTable[nHashPos].bExists )  
	{  
		//     如果仅仅是判断在该表中时候存在这个字符串，就比较这两个hash值就可以了，不用对结构体中的字符串进行比较。  
		//         这样会加快运行的速度？减少hash表占用的空间？这种方法一般应用在什么场合？  
		if ( 　 lpTable[nHashPos].nHashA == nHashA  
			&&  lpTable[nHashPos].nHashB == nHashB )  
		{  
			return nHashPos;  
		}  
		else  
		{  
			nHashPos = (nHashPos + 1) % nTableSize;  
		}  

		if (nHashPos == nHashStart)  
			break;  
	}  
	return -1;  
}  



//24.5、不重复Hash编码
//函数prepareCryptTable以下的函数生成一个长度为0x500（合10进制数：1280）的cryptTable[0x500]  
void prepareCryptTable()  
{  
	unsigned long seed = 0x00100001, index1 = 0, index2 = 0, i;  

	for( index1 = 0; index1 <0x100; index1++ )  
	{  
		for( index2 = index1, i = 0; i < 5; i++, index2 += 0x100)  
		{  
			unsigned long temp1, temp2;  
			seed = (seed * 125 + 3) % 0x2AAAAB;  
			temp1 = (seed & 0xFFFF)<<0x10;  
			seed = (seed * 125 + 3) % 0x2AAAAB;  
			temp2 = (seed & 0xFFFF);  
			cryptTable[index2] = ( temp1 | temp2 );  
		}  
	}  
}  

//函数HashString以下函数计算lpszFileName 字符串的hash值，其中dwHashType 为hash的类型，  
unsigned long HashString(const char *lpszkeyName, unsigned long dwHashType )  
{  
	unsigned char *key  = (unsigned char *)lpszkeyName;  
	unsigned long seed1 = 0x7FED7FED;  
	unsigned long seed2 = 0xEEEEEEEE;  
	int ch;  

	while( *key != 0 )  
	{  
		ch = *key++;  
		seed1 = cryptTable[(dwHashType<<8) + ch] ^ (seed1 + seed2);  
		seed2 = ch + seed1 + seed2 + (seed2<<5) + 3;  
	}  
	return seed1;  
}  

/////////////////////////////////////////////////////////////////////  
//function: 哈希词典 编码  
//parameter:  
//author: lei.zhou  
//time: 2011-12-14  
/////////////////////////////////////////////////////////////////////  
MPQHASHTABLE TestHashTable[nTableSize];  
int TestHashCTable[nTableSize];  
int TestHashDTable[nTableSize];  
key_list test_data[nTableSize];  

//直接调用上面的hashstring，nHashPos就是对应的HASH值。  
int insert_string(const char *string_in)  
{  
	const int HASH_OFFSET = 0, HASH_C = 1, HASH_D = 2;  
	unsigned int nHash = HashString(string_in, HASH_OFFSET);  
	unsigned int nHashC = HashString(string_in, HASH_C);  
	unsigned int nHashD = HashString(string_in, HASH_D);  
	unsigned int nHashStart = nHash % nTableSize;  
	unsigned int nHashPos = nHashStart;  
	int ln, ires = 0;  

	while (TestHashTable[nHashPos].bExists)  
	{  
		//      if (TestHashCTable[nHashPos]  == (int) nHashC && TestHashDTable[nHashPos] == (int) nHashD)  
		//          break;  
		//      //...  
		//      else  
		//如之前所提示读者的那般，暴雪的Hash算法对于查询那样处理可以，但对插入就不能那么解决  
		nHashPos = (nHashPos + 1) % nTableSize;  

		if (nHashPos == nHashStart)  
			break;  
	}  

	ln = strlen(string_in);  
	if (!TestHashTable[nHashPos].bExists && (ln < nMaxStrLen))  
	{   
		TestHashCTable[nHashPos] = nHashC;  
		TestHashDTable[nHashPos] = nHashD;  

		test_data[nHashPos] = (KEYNODE *) malloc (sizeof(KEYNODE) * 1);  
		if(test_data[nHashPos] == NULL)  
		{  
			printf("10000 EMS ERROR !!!!\n");  
			return 0;  
		}  

		test_data[nHashPos]->pkey = (char *)malloc(ln+1);  
		if(test_data[nHashPos]->pkey == NULL)  
		{  
			printf("10000 EMS ERROR !!!!\n");  
			return 0;  
		}  

		memset(test_data[nHashPos]->pkey, 0, ln+1);  
		strncpy(test_data[nHashPos]->pkey, string_in, ln);  
		*((test_data[nHashPos]->pkey)+ln) = 0;  
		test_data[nHashPos]->weight = nHashPos;  

		TestHashTable[nHashPos].bExists = 1;  
	}  
	else  
	{  
		if(TestHashTable[nHashPos].bExists)  
			printf("30000 in the hash table %s !!!\n", string_in);  
		else  
			printf("90000 strkey error !!!\n");  
	}  
	return nHashPos;  
}


void bigIndex_hash(const char *docpath, const char *hashpath)  
{  
	FILE *fr, *fw;  
	int len;  
	char *pbuf, *p;  
	char dockey[TERM_MAX_LENG];  

	if(docpath == NULL || *docpath == '\0')  
		return;  

	if(hashpath == NULL || *hashpath == '\0')  
		return;  

	fr = fopen(docpath, "rb");  //读取文件docpath  
	fw = fopen(hashpath, "wb");  
	if(fr == NULL || fw == NULL)  
	{  
		printf("open read or write file error!\n");  
		return;  
	}  

	pbuf = (char*)malloc(BUFF_MAX_LENG);  
	if(pbuf == NULL)  
	{  
		fclose(fr);  
		return ;  
	}  

	memset(pbuf, 0, BUFF_MAX_LENG);  

	while(fgets(pbuf, BUFF_MAX_LENG, fr))  
	{  
		len = GetRealString(pbuf);  
		if(len <= 1)  
			continue;  
		p = strstr(pbuf, "#####");    
		if(p != NULL)  
			continue;  

		p = strstr(pbuf, "  ");  
		if (p == NULL)  
		{  
			printf("file contents error!");  
		}  

		len = p - pbuf;  
		dockey[0] = 0;  
		strncpy(dockey, pbuf, len);  

		dockey[len] = 0;        

		int num = insert_string(dockey);   

		dockey[len] = ' ';  
		dockey[len+1] = '\0';  
		char str[20];  
		itoa(num, str, 10);  

		strcat(dockey, str);  
		dockey[len+strlen(str)+1] = '\0';  
		fprintf (fw, "%s\n", dockey);  

	}  
	free(pbuf);  
	fclose(fr);  
	fclose(fw);  
} 


int main()  
{  
	prepareCryptTable();  //Hash表起初要初始化  

	//现在要把整个big_index文件插入hash表，以取得编码结果  
	bigIndex_hash("big_index.txt", "hashpath.txt");  
	system("pause");  

	return 0;  
}  



//在上面的bigIndex_hashcode函数的基础上，修改
void bigIndex_hashcode(const char *in_file_path, const char *out_file_path)  
{  
	FILE *fr, *fw;  
	int len, value;  
	char *pbuf, *pleft, *p;  
	char keyvalue[TERM_MAX_LENG], str[WORD_MAX_LENG];  

	if(in_file_path == NULL || *in_file_path == '\0') {  
		printf("input file path error!\n");  
		return;  
	}  

	if(out_file_path == NULL || *out_file_path == '\0') {  
		printf("output file path error!\n");  
		return;  
	}  

	fr = fopen(in_file_path, "r");  //读取in_file_path路径文件  
	fw = fopen(out_file_path, "w");  

	if(fr == NULL || fw == NULL)  
	{  
		printf("open read or write file error!\n");  
		return;  
	}  

	pbuf = (char*)malloc(BUFF_MAX_LENG);  
	pleft = (char*)malloc(BUFF_MAX_LENG);  
	if(pbuf == NULL || pleft == NULL)  
	{  
		printf("allocate memory error!");  
		fclose(fr);  
		return ;  
	}  

	memset(pbuf, 0, BUFF_MAX_LENG);  

	int offset = 1;  
	while(fgets(pbuf, BUFF_MAX_LENG, fr))  
	{  
		if (--offset > 0)  
			continue;  

		if(GetRealString(pbuf) <= 1)  
			continue;  

		p = strstr(pbuf, "#####");    
		if(p != NULL)  
			continue;  

		p = strstr(pbuf, "  ");  
		if (p == NULL)  
		{  
			printf("file contents error!");  
		}  

		len = p - pbuf;  

		// 确定跳过行数  
		strcpy(pleft, p+1);   
		offset = atoi(pleft) + 1;  

		strncpy(keyvalue, pbuf, len);    
		keyvalue[len] = '\0';  
		value = insert_string(keyvalue);  

		if (value != -1) {  

			// key value中插入空格  
			keyvalue[len] = ' ';  
			keyvalue[len+1] = '\0';  

			itoa(value, str, 10);  
			strcat(keyvalue, str);  

			keyvalue[len+strlen(str)+1] = ' ';  
			keyvalue[len+strlen(str)+2] = '\0';  

			keysize++;  
			itoa(keysize, str, 10);  
			strcat(keyvalue, str);  

			// 将key value写入文件  
			fprintf (fw, "%s\n", keyvalue);  

		}  
	}  
	free(pbuf);  
	fclose(fr);  
	fclose(fw);  
} 
