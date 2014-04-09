//解法一
//引用自gnuhpc  
while( current<=end )        
{             
  if( array[current] ==0 )             
   {                 
      swap(array[current],array[begin]);                  
      current++;                  
      begin++;            
   }             
   else if( array[current] == 1 )            
   {                 
      current++;            
   }   

   else //When array[current] =2   
   {               
      swap(array[current],array[end]);                
      end--;            
   }      
}  
