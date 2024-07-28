package edu.ndhu;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.util.Base64;

import javax.crypto.Cipher;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

public class RSA_Encrypt_Descrypt_DES
{ 
    public static void main(String[] args) throws Exception
    {      
        // Get the public and private key
        PublicKey publicKey = RSA_KeyReadWrite.readPublicKeyFromFile("jame.pub");
        PrivateKey privateKey = RSA_KeyReadWrite.readPrivateKeyFromFile("jame.pri");
        
        // Get the AES key
        SecretKey key =  KeyReadWrite.readKeyFromFile("dakin.key");
        
        // Encryption AES key
        byte[] cipherTextArray = encrypt(key, publicKey);

        // Write key_encrypted to file
        String fileName="dakin_encryped.key";
        FileOutputStream out = new FileOutputStream(fileName);
 	    out.write(cipherTextArray);
 	    out.flush();
 	    out.close();   	
 	    System.out.println("The key file "+"\""+fileName+"\""+" is generated.");	
        
        // Read encrypted AES key
 	    FileInputStream in = new FileInputStream(fileName);
	    byte[] encrypted_keybyte = new byte[in.available()];
        in.read(encrypted_keybyte);
	    in.read();
	    in.close();
	    
	    // Decrypt encrypted AES key
        byte[] decrypted_keybyte = decrypt(encrypted_keybyte, privateKey);
        SecretKeySpec skey = new SecretKeySpec(decrypted_keybyte, "AES");
        byte[] IV = IVReadWrite.readIVFromFile("dakin.iv");
        
        // Decrypt cipher data
        String encryptedText = "YchTrv8arCia9vYPojRdHRbOB93g6w9H0ShrtJ05PjgF31KoW52/86k3p02Km8c8pLdLo0y1RfJohj5JCyqnCyVkzfttmkug6Q+jhzGvHo8=";      
        byte[] cipherText = Base64.getDecoder().decode(encryptedText);
        String decryptedText = AES_CBC_Encryption.decrypt(cipherText,skey, IV);
        System.out.println("DeCrypted Text : "+decryptedText);

    }
    
    public static byte[] encrypt (SecretKey key,PublicKey publicKey ) throws Exception
    {
        //Get Cipher Instance RSA With ECB Mode and OAEPWITHSHA-512ANDMGF1PADDING Padding
        Cipher cipher = Cipher.getInstance("RSA/ECB/OAEPWITHSHA-512ANDMGF1PADDING");
        
        //Initialize Cipher for ENCRYPT_MODE
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        
        //Perform Encryption
        byte[] cipherText = cipher.doFinal(key.getEncoded()) ;

        return cipherText;
    }
    
    public static byte[] decrypt (byte[] cipherTextArray, PrivateKey privateKey) throws Exception
    {
        //Get Cipher Instance RSA With ECB Mode and OAEPWITHSHA-512ANDMGF1PADDING Padding
        Cipher cipher = Cipher.getInstance("RSA/ECB/OAEPWITHSHA-512ANDMGF1PADDING");
        
        //Initialize Cipher for DECRYPT_MODE
        cipher.init(Cipher.DECRYPT_MODE, privateKey);
        
        //Perform Decryption
        byte[] decryptedTextArray = cipher.doFinal(cipherTextArray);
        
        return decryptedTextArray;
    }
}
