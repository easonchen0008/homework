import java.sql.Connection;
import java.io.File;
import java.io.IOException;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class inser {
	static final String DB_URL = "jdbc:mysql://localhost/XMLCLASS";
	   static final String USER = "root";
	   static final String PASS = "a19991130";

	   public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException {
	      // Open a connection
	      try(Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
	         Statement stmt = conn.createStatement();
	      ) {		      
	         // Execute a query
	         System.out.println("Inserting records into the table...");          

	         
	            File file = new File("score_data.xml");
	            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
	            DocumentBuilder db = dbf.newDocumentBuilder();
	            Document document = db.parse(file);
	            document.getDocumentElement().normalize();
	            System.out.println("Root Element :" + document.getDocumentElement().getNodeName());
	            NodeList nList = document.getElementsByTagName("student");
	            System.out.println("----------------------------");
	            for (int temp = 0; temp < nList.getLength(); temp++) {
	                Node nNode = nList.item(temp);
	                System.out.println("\nCurrent Element :" + nNode.getNodeName());
	                if (nNode.getNodeType() == Node.ELEMENT_NODE) {
	                    Element eElement = (Element) nNode;
	                    String  sql_insert = "INSERT INTO score_data(id ,xml_class ,data_structure ,algorithm ,network) VALUES (?,?,?,?,?)";
	                    PreparedStatement preparedStatement = conn.prepareStatement(sql_insert);
	                    preparedStatement.setInt(1, temp);
	                    preparedStatement.setString(2, eElement.getElementsByTagName("xml_class").item(0).getTextContent());
	                    preparedStatement.setString(3, eElement.getElementsByTagName("data_structure").item(0).getTextContent());
	                    preparedStatement.setString(4, eElement.getElementsByTagName("algorithm").item(0).getTextContent());
	                    preparedStatement.setString(5, eElement.getElementsByTagName("network").item(0).getTextContent());
	                    System.out.println(preparedStatement);
	                    preparedStatement.executeUpdate();  
	                }
	            }
	         
	      } catch (SQLException e) {
	         e.printStackTrace();
	      } 
	   }
}
