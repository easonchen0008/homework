package edu.ndhu;

import java.util.Base64;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class AES_CBC_Encryption_Lab
{
    static String plainText = "Teather is a handsome man.";
	
    public static void main(String[] args) throws Exception
    {

        SecretKey key =  KeyReadWrite.readKeyFromFile("kiki.key");
        byte[] IV = IVReadWrite.readIVFromFile("kiki.iv");
      
        System.out.println("Original Text  : "+plainText);
        
        byte[] cipherText = AES_CBC_Encryption.encrypt(plainText.getBytes(),key, IV);
        System.out.println("Encrypted Text : "+Base64.getEncoder().encodeToString(cipherText) );
        String encryptedText = Base64.getEncoder().encodeToString(cipherText);
        
        cipherText = Base64.getDecoder().decode(encryptedText);
        String decryptedText = AES_CBC_Encryption.decrypt(cipherText,key, IV);
        System.out.println("DeCrypted Text : "+decryptedText);
        
    }
}