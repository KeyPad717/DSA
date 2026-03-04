class Solution {
public:
    string s="";
    long long int i=0,sign=1,number=0;
    void whitespace(string s){
        if(s[i]==' '){
            whitespace(s.substr(1,s.length()-1));
        }
        sign_num(s);
    }
    void sign_num(string s){
        if(s[i]=='-'){
            sign=0;
            num(s.substr(1,s.length()-1));
        }
        else if(s[i]=='+'){
            num(s.substr(1,s.length()-1));
        }
        num(s);
    }
    void num(string s){
        //cout<<number<<" ";
        if(s[i]=='0'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+0;
            num(s.substr(1,s.length()-1));
        }  
        else if(s[i]=='1'){
            //cout<<"l"<<" ";
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+1;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='2'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+2;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='3'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+3;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='4'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+4;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='5'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+5;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='6'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+6;
            num(s.substr(1,s.length()-1));
        }  
        else if(s[i]=='7'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+7;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='8'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+8;
            num(s.substr(1,s.length()-1));
        } 
        else if(s[i]=='9'){
            if(number<-2147483648)   return;
            if(number>2147483647)   return;
            number=number*10+9;
            num(s.substr(1,s.length()-1));
        }
        return;
    }
    int myAtoi(string s) {
        whitespace(s);
        if(sign==0)     number=0-number;
        if(number<-2147483648)   return(-2147483648);
        if(number>2147483647)   return(2147483647);
        return(number);
    }   
};