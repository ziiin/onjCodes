import java.io.*;
class pali1
{
int palindrome(String n,int i,int j)
{
 if (n.charAt(i) != n.charAt(j))
 return 0;

if (i>=j)
return 1;

return palindrome(n,i+1,j-1);
          
}

public static void main(String args[])throws Exception
{
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
String Name=new String();
int i,len;
System.out.println("Enter the string");
Name=br.readLine();
System.out.println(" "+Name);
len=Name.length();
System.out.println(""+len);
pali1 p1=new pali1();
i=p1.palindrome(Name,0,len-1);
if(i==1)
System.out.println("yes,palindrome");
else
System.out.println("String isn't a palindrome");
}
}
