package edu.ndhu;

import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class KeyReadWrite
{
    /*
    public static void main(String[] args) throws Exception
    {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(128);

        // Generate Key
        SecretKey key_temp = keyGenerator.generateKey();
        // Saving the Key to the file
        saveKeyToFile("mysecret.key",key_temp);
        SecretKey key = readKeyFromFile("mysecret.key");
    }
    */
    
    public static void saveKeyToFile(String fileName, SecretKey key) throws IOException
    {
    	byte[] keybyte = key.getEncoded();
 	    //System.out.println(key.getFormat());	    	   
 	    FileOutputStream out = new FileOutputStream(fileName);
 	    out.write(keybyte);
 	    out.flush();
 	    out.close();   	
 	    System.out.println("The key file "+"\""+fileName+"\""+" is generated.");	
    }
    
    public static SecretKey readKeyFromFile(String fileName) throws IOException
    {
 	    //System.out.println(key.getFormat());	    	   
 	    FileInputStream in = new FileInputStream(fileName);
 	    byte[] keybyte = new byte[in.available()];
        in.read(keybyte);
 	    in.read();
 	    in.close();   	
 	    SecretKeySpec skey = new SecretKeySpec(keybyte, "AES");
 	    return skey;	
    }
}