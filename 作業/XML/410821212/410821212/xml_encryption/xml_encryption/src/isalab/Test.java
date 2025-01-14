package isalab;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;

import org.apache.xml.security.encryption.EncryptedKey;
import org.apache.xml.security.encryption.XMLCipher;
import org.apache.xml.security.utils.XMLUtils;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;

import javax.xml.transform.TransformerFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.OutputKeys;

import isalab.ndhu.encryption.*;

public class Test
{
   public static void main(String args[]) throws Exception
   {
      DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
      dbf.setNamespaceAware(true);
      dbf.setIgnoringElementContentWhitespace(true);
      DocumentBuilder db = dbf.newDocumentBuilder();
      Document document = db.parse(new File("xmlDemo.xml"));

      FileInputStream keyFile1 = new FileInputStream("key.ser");
      byte[] dataEnckey = new byte[keyFile1.available()];
      keyFile1.read(dataEnckey);
      keyFile1.close();

      FileInputStream keyFile2 = new FileInputStream("kek.pub");
      byte[] keyEncKey = new byte[keyFile2.available()];
      keyFile2.read(keyEncKey);
      keyFile2.close();

      FileInputStream keyFile3 = new FileInputStream("kek.prv");
      byte[] keyDecKey = new byte[keyFile3.available()];
      keyFile3.read(keyDecKey);
      keyFile3.close();
            
      AlgorithmRSA algRSA = new AlgorithmRSA();
      
      //encrypt the symmetric key.
      EncryptedKey enckey = algRSA.encrypt(document, keyEncKey, dataEnckey, "DESede");
           
      AlgorithmTripleDES alg3DES = new AlgorithmTripleDES();
      
      //encrypt the element.
      document = alg3DES.encrypt(document, "/addressbook/name/sin", true, dataEnckey, enckey);
      
      File encryptionFile1 = new File("encryptedInfo.xml");
      FileOutputStream f = new FileOutputStream(encryptionFile1);

      XMLUtils.outputDOMc14nWithComments(document, f);

      f.close();
      System.out.println("Wrote document containing encrypted data to " +
                                                            encryptionFile1.toURI().toURL().toString() + "\n");
      
      //decrypt the xml data encryption key.
      XMLCipher xmlCipher = algRSA.decrypt(document, keyDecKey);
      
      //decrypt xml data
      document = alg3DES.decrypt(document, null, xmlCipher);
      
      File encryptionFile2 = new File("decryptedInfo.xml");
      FileOutputStream f2 = new FileOutputStream(encryptionFile2);

      XMLUtils.outputDOMc14nWithComments(document, f2);

      f2.close();
      System.out.println("Wrote document containing decrypted data to " + encryptionFile2.toURI().toURL().toString());
   }
}