package edu.ndhu;

import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Base64;

import javax.crypto.Cipher;

public class RSA_Encryption_Lab
{
    static String plainText = "Teacher is a handsome man.";
    
    public static void main(String[] args) throws Exception
    {      
        // Get the public and private key
        PublicKey publicKey = RSA_KeyReadWrite.readPublicKeyFromFile("kiki.pub");
        PrivateKey privateKey = RSA_KeyReadWrite.readPrivateKeyFromFile("kiki.pri");
        
        System.out.println("Original Text  : "+plainText);
        
        // Encryption
        byte[] cipherTextArray = RSA_Encryption.encrypt(plainText, publicKey);
        String encryptedText = Base64.getEncoder().encodeToString(cipherTextArray);
        System.out.println("Encrypted Text : "+encryptedText);
        
        // Decryption
        cipherTextArray = Base64.getDecoder().decode(encryptedText);
        String decryptedText = RSA_Encryption.decrypt(cipherTextArray, privateKey);
        System.out.println("DeCrypted Text : "+decryptedText);
    }
}
