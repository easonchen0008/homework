package edu.ndhu;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class IVReadWrite
{
    /*
    public static void main(String[] args) throws Exception
    {
    	byte[] IV = new byte[16];
        SecureRandom random = new SecureRandom();
        random.nextBytes(IV);
        saveIVToFile("mysecret.iv",IV);
        byte[] temp_IV = readIVFromFile("mysecret.iv");
        System.out.println(temp_IV);
    }
    */
    
    public static void saveIVToFile(String fileName, byte[] iv) throws IOException
    {	    	   
 	    FileOutputStream out = new FileOutputStream(fileName);
 	    out.write(iv);
 	    out.flush();
 	    out.close();   	
 	    System.out.println("The iv file "+"\""+fileName+"\""+" is generated.");	
    }
    
    public static byte[] readIVFromFile(String fileName) throws IOException
    {   	   
 	    FileInputStream in = new FileInputStream(fileName);
 	    byte[] keybyte = new byte[in.available()];
        in.read(keybyte);
 	    in.read();
 	    in.close();   	
 	    return keybyte;	
    }
}