import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
public class SQLtoXML {
	static final String DB_URL = "jdbc:mysql://localhost/XMLCLASS";
	static final String USER = "root";
	static final String PASS = "a19991130";
	static final String QUERY = "SELECT id, xml_class, data_structure, algorithm, network FROM score_data";

	public static void main(String[] args) throws ParserConfigurationException, TransformerException {
		// Open a connection
		try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
				Statement stmt = conn.createStatement();
				ResultSet rs = stmt.executeQuery(QUERY);)
		{
			DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
			DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
			Document doc = dBuilder.newDocument();

			// root element
			Element rootElement = doc.createElement("score_data");
			doc.appendChild(rootElement);
			
			while (rs.next()) {
				// Display values
				int id = rs.getInt("id")+1;
				int xml_class = Integer.valueOf(rs.getString("xml_class"));
				int data_structure = Integer.valueOf(rs.getString("data_structure"));
				int algorithm = Integer.valueOf(rs.getString("algorithm"));
				int network = Integer.valueOf(rs.getString("network"));
				System.out.print("ID: " + id);
				System.out.print(", Mark: " + xml_class);
				System.out.print(", First: " + data_structure);
				System.out.print(", Last: " + algorithm);
				System.out.println(", Nick: " + network);
				//gpa
				String gpa = null;
				int sc = xml_class;
				if(sc>=90)
				{	gpa="4.5";
				}else if (sc>=85&&sc<=89)
				{	gpa="4";
				}else if (sc>=80&&sc<=84)
				{	gpa="3.7";
				}else if (sc>=77&&sc<=79)
				{	gpa="3.3";
				}else if (sc>=73&&sc<=76)
				{	gpa="3.0";
				}else if (sc>=70&&sc<=72)
				{	gpa="2.7";
				}else if (sc>=67&&sc<=69)
				{	gpa="2.5";
				}else if (sc>=63&&sc<=66)
				{	gpa="2.3";
				}else if (sc>=60&&sc<=62)
				{	gpa="2.0";
				}else if (sc>=50&&sc<=59)
				{	gpa="1.0";
				}else if (sc<=50)
				{	gpa="0";
				}
				
				// student element
				Element student = doc.createElement("student");
				rootElement.appendChild(student);

				// setting attribute to element
				Attr attr = doc.createAttribute("student_id");
				attr.setValue("A00"+id);
				student.setAttributeNode(attr);

				// firstname element
				Element firstname = doc.createElement("xml_class");
				firstname.appendChild(doc.createTextNode(rs.getString("xml_class")));
				student.appendChild(firstname);
				// setting attribute to element
				Attr attr1 = doc.createAttribute("gpa");
				attr1.setValue(gpa);
				firstname.setAttributeNode(attr1);
				
				//gpa
				sc = data_structure;
				if(sc>=90)
				{	gpa="4.5";
				}else if (sc>=85&&sc<=89)
				{	gpa="4";
				}else if (sc>=80&&sc<=84)
				{	gpa="3.7";
				}else if (sc>=77&&sc<=79)
				{	gpa="3.3";
				}else if (sc>=73&&sc<=76)
				{	gpa="3.0";
				}else if (sc>=70&&sc<=72)
				{	gpa="2.7";
				}else if (sc>=67&&sc<=69)
				{	gpa="2.5";
				}else if (sc>=63&&sc<=66)
				{	gpa="2.3";
				}else if (sc>=60&&sc<=62)
				{	gpa="2.0";
				}else if (sc>=50&&sc<=59)
				{	gpa="1.0";
				}else if (sc<=50)
				{	gpa="0";
				}
				// lastname element
				Element lastname = doc.createElement("data_structure");
				lastname.appendChild(doc.createTextNode(rs.getString("data_structure")));
				student.appendChild(lastname);
				// setting attribute to element
				Attr attr2 = doc.createAttribute("gpa");
				attr2.setValue(gpa);
				lastname.setAttributeNode(attr2);
				
				//gpa
				sc = algorithm;
				if(sc>=90)
				{	gpa="4.5";
				}else if (sc>=85&&sc<=89)
				{	gpa="4";
				}else if (sc>=80&&sc<=84)
				{	gpa="3.7";
				}else if (sc>=77&&sc<=79)
				{	gpa="3.3";
				}else if (sc>=73&&sc<=76)
				{	gpa="3.0";
				}else if (sc>=70&&sc<=72)
				{	gpa="2.7";
				}else if (sc>=67&&sc<=69)
				{	gpa="2.5";
				}else if (sc>=63&&sc<=66)
				{	gpa="2.3";
				}else if (sc>=60&&sc<=62)
				{	gpa="2.0";
				}else if (sc>=50&&sc<=59)
				{	gpa="1.0";
				}else if (sc<=50)
				{	gpa="0";
				}
				// nickname element
				Element nickname = doc.createElement("algorithm");
				nickname.appendChild(doc.createTextNode(rs.getString("algorithm")));
				student.appendChild(nickname);
				// setting attribute to element
				Attr attr3 = doc.createAttribute("gpa");
				attr3.setValue(gpa);
				nickname.setAttributeNode(attr3);
				
				//gpa
				sc = network;
				if(sc>=90)
				{	gpa="4.5";
				}else if (sc>=85&&sc<=89)
				{	gpa="4";
				}else if (sc>=80&&sc<=84)
				{	gpa="3.7";
				}else if (sc>=77&&sc<=79)
				{	gpa="3.3";
				}else if (sc>=73&&sc<=76)
				{	gpa="3.0";
				}else if (sc>=70&&sc<=72)
				{	gpa="2.7";
				}else if (sc>=67&&sc<=69)
				{	gpa="2.5";
				}else if (sc>=63&&sc<=66)
				{	gpa="2.3";
				}else if (sc>=60&&sc<=62)
				{	gpa="2.0";
				}else if (sc>=50&&sc<=59)
				{	gpa="1.0";
				}else if (sc<=50)
				{	gpa="0";
				}
				// marks element
				Element marks = doc.createElement("network");
				marks.appendChild(doc.createTextNode(rs.getString("network")));
				student.appendChild(marks);
				// setting attribute to element
				Attr attr4 = doc.createAttribute("gpa");
				attr4.setValue(gpa);
				marks.setAttributeNode(attr4);
				
			}
			// write the content into xml file
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			// StreamResult result = new StreamResult(new File("C:\\cars.xml"));
			StreamResult result = new StreamResult(new File("output.xml"));
			transformer.transform(source, result);

			// Output to console for testing
			StreamResult consoleResult = new StreamResult(System.out);
			transformer.transform(source, consoleResult);
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}
