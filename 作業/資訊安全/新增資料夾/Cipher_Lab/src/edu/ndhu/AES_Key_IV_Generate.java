package edu.ndhu;

import java.security.SecureRandom;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class AES_Key_IV_Generate
{
        
    public static void main(String[] args) throws Exception
    {
        KeyGenerator keyGenerator = KeyGenerator.getInstance("AES");
        keyGenerator.init(128);

        // Generate Key
        SecretKey key = keyGenerator.generateKey();
        // Saving the Key to the file
        KeyReadWrite.saveKeyToFile("kiki.key",key);
        key =  KeyReadWrite.readKeyFromFile("kiki.key");

        // Generating IV.
        byte[] IV = new byte[16];
        SecureRandom random = new SecureRandom();
        random.nextBytes(IV);
        
        IVReadWrite.saveIVToFile("kiki.iv", IV);
        IV=IVReadWrite.readIVFromFile("kiki.iv");
    }
}