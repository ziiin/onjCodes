import java.io.*;

class str {
        public static void main(String args[])throws Exception {
                BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
                String sen,space="	";
                // why is space initialized to so many spaces ??
                System.out.println("enter the sentence");
                sen=br.readLine();
                String str1[]=sen.split(space);
                String str2[];
                int count=0,itr=0,index,length;

                while(str[itr]) {// there is nothing called str
                        if(str1[itr++])
                                // java does not accept any type as condition
                                // needs strict boolean result to compute if
                                count++;
                }
                System.out.println("length:"+count);

                for(index=0;index<=count;index++) {
                        if(str1[index]!=space)
                                break;
                }
                str1=(index==0)? str1:(str1.substring(index,count));
                // str1 and str2 are arrays of String, not sure.
                // Therefor doesnot have substring method defined.
                System.out.println("leading zeroes removed!");


                for (index=count-1;index>=0;index--) {
                        if (str1[index]!=space)
                                break;
                }
                str1=(index == length-1) ? str1:(str1.substring(0,index+1));

                System.out.println("trailing zeroes removed!");

                for(itr=count-1;itr>=0;itr--) {
                        str2=str1[count]+space;
                        //str2 is an Array and you are trying to return string, i guess.
                }

                System.out.println(str2);
        }
}
