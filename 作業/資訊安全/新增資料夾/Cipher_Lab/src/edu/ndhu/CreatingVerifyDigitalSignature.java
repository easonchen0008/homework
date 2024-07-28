package edu.ndhu;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.Signature;

public class CreatingVerifyDigitalSignature {
	
   public static void main(String args[]) throws Exception {
	   
      String msg = "Teacher is a handsome man.";
      
      //Creating KeyPair generator object
      KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
      
      //Initializing the key pair generator
      keyPairGen.initialize(4096);
      
      //Generate the pair of keys
      KeyPair pair = keyPairGen.generateKeyPair();
      
      //Getting the private key from the key pair
      PrivateKey privKey = pair.getPrivate();
      
      //Creating a Signature object
      Signature sign = Signature.getInstance("SHA256withRSA");
      
      //Initialize the signature
      sign.initSign(privKey);
      byte[] bytes = msg.getBytes();
      
      //Adding data to the signature
      sign.update(bytes);
      
      //Calculating the signature
      byte[] signature = sign.sign();
      
      //Printing the signature
      System.out.println("Digital signature for given text: "+new String(signature, "UTF8"));
      
      //Initializing the signature
      String msg1 = "Teacher is a handsome man.";
      byte[] bytes1 = msg1.getBytes();
      
      sign.initVerify(pair.getPublic());
      sign.update(bytes1);
      
      //Verifying the signature
      boolean bool = sign.verify(signature);
      
      if(bool) {
         System.out.println("Signature verified");   
      }else {
         System.out.println("Signature failed");
      }
   }
}
