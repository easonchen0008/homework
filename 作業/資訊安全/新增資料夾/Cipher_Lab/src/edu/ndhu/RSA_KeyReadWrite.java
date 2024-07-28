package edu.ndhu;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.X509EncodedKeySpec;
import java.security.spec.PKCS8EncodedKeySpec;

public class RSA_KeyReadWrite
{
    
    public static void savePublicKeyToFile(String fileName, PublicKey key) throws IOException
    {
    	byte[] keybyte = key.getEncoded();
 	    //System.out.println(key.getFormat());	    	   
 	    FileOutputStream out = new FileOutputStream(fileName);
 	    out.write(keybyte);
 	    out.flush();
 	    out.close();   	
 	    System.out.println("The key file "+"\""+fileName+"\""+" is generated.");	
    }
    
    public static void savePrivateKeyToFile(String fileName, PrivateKey key) throws IOException
    {
    	byte[] keybyte = key.getEncoded();
 	    //System.out.println(key.getFormat());	    	   
 	    FileOutputStream out = new FileOutputStream(fileName);
 	    out.write(keybyte);
 	    out.flush();
 	    out.close();   	
 	    System.out.println("The key file "+"\""+fileName+"\""+" is generated.");	
    }
    
    public static PublicKey readPublicKeyFromFile(String fileName) throws IOException
    {
 	    //System.out.println(key.getFormat());	    	   
 	    FileInputStream in = new FileInputStream(fileName);
 	    byte[] keybyte = new byte[in.available()];
        in.read(keybyte);
 	    in.read();
 	    in.close();   	
 	    X509EncodedKeySpec publicSpec = new X509EncodedKeySpec(keybyte);
 	   PublicKey pubkey=null;
 	    try {
          KeyFactory keyFactory = KeyFactory.getInstance("RSA");
          pubkey = keyFactory.generatePublic(publicSpec);
 	    } catch(Exception e) {
          e.printStackTrace();
        }
 	    return pubkey;	
    }
    
    public static PrivateKey readPrivateKeyFromFile(String fileName) throws IOException
    {
 	    //System.out.println(key.getFormat());	    	   
 	    FileInputStream in = new FileInputStream(fileName);
 	    byte[] keybyte = new byte[in.available()];
        in.read(keybyte);
 	    in.read();
 	    in.close();   	
 	    PKCS8EncodedKeySpec priKeySpec = new PKCS8EncodedKeySpec(keybyte);
 	    PrivateKey prikey=null;
 	    try {
 	      KeyFactory keyFactory = KeyFactory.getInstance("RSA");
          prikey = keyFactory.generatePrivate(priKeySpec);
 	    }catch(Exception e){
 	      e.printStackTrace();
 	    }
 	    return prikey;	
    }
}
