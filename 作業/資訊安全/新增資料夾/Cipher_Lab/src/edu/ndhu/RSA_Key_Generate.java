package edu.ndhu;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;

public class RSA_Key_Generate
{
  
    public static void main(String[] args) throws Exception
    {
        // Get an instance of the RSA key generator
        KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("RSA");
        keyPairGenerator.initialize(4096);
        
        // Generate the KeyPair
        KeyPair keyPair = keyPairGenerator.generateKeyPair();
        
        // Get the public and private key
        PublicKey publicKey = keyPair.getPublic();
        PrivateKey privateKey = keyPair.getPrivate();
        
        RSA_KeyReadWrite.savePublicKeyToFile("kiki.pub", publicKey);
        RSA_KeyReadWrite.savePrivateKeyToFile("kiki.pri", privateKey);
        
    }
}
