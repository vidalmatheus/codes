/*
I'm here
21:00h

Given an encoded string A consisting of lowercase English alphabets, square parentheses, and digits.
The encoding rule is X[encoded string],
where the encoded_string inside the square brackets is being repeated exactly X times.
Note that X is guaranteed to be a positive integer.

Find and return the decoded string.

10[a2[c]]

cdeh2[abc]3[cd]ef

accaccacc

rec(string:s, integer:left, integer: right):
    // grab the integer at left: n
    // repeat n times rec(s,left+numberOfDigitsOfn+1, right-1)

       
      (cc)10
    
 
rec(s,0,9):
    // grab the "first string": first
    // base case: dont find an integer, return first     
    // grab the integer at left: n:10
    // grab the number of digits of n: k
    // grab the last part: last
    // loop n times and concatenate
    str = rec(s,left+length(first)+k+1,right-length(last)-1);
    do 10 times:
        str+=str

    return  first + str + last;

                ||      
   s:    h10[a2[ce]]ab]ab
         0123456789   13  
  
 rec(0,13):
     first: h
     n:10
     k:2
     last: ab
     str: rec(4,11):"aceceab"
     return "h" + 10*"aceceab" + "ab"
         
         rec(4,11):
             first: a
             n: 2
             k: 1
             last:ab
             str: rec(7,8): ce
             str: cece
             return "a" + "cece" + "ab": aceceab
             
             rec(7,8):
                first: ce
                n: ? --> base case: return "ce"
                     
                     
                     "100" -> int 100
                     stoi("100")
                     quant =  3
                     char = a a c c e a c c e a c c e f
                 
                 str = ecca
            
            https://www.interviewbit.com/problems/nextgreater/
            https://www.interviewbit.com/problems/copy-list/ extra space O(1)
          .            
a3[a2[c]e]f         
                     
  stringstream number(s);
  int num = 0;
  number >> num;
    

*/
