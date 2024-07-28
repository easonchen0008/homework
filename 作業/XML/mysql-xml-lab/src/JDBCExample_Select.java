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


public class JDBCExample_Select {
	static final String DB_URL = "jdbc:mysql://localhost/XMLDB";
	static final String USER = "root";
	static final String PASS = "a19991130";
	static final String QUERY = "SELECT id, first, last, nick, mark FROM class";

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
			Element rootElement = doc.createElement("class");
			doc.appendChild(rootElement);
			
			while (rs.next()) {
				// Display values
				int id = rs.getInt("id");
				String mark = rs.getString("mark");
				String first = rs.getString("first");
				String last = rs.getString("last");
				String nick = rs.getString("nick");
				System.out.print("ID: " + id);
				System.out.print(", Mark: " + mark);
				System.out.print(", First: " + first);
				System.out.print(", Last: " + last);
				System.out.println(", Nick: " + nick);
				
				// student element
				Element student = doc.createElement("student");
				rootElement.appendChild(student);

				// setting attribute to element
				Attr attr = doc.createAttribute("rollno");
				attr.setValue(Integer.toString(id));
				student.setAttributeNode(attr);

				// firstname element
				Element firstname = doc.createElement("firstname");
				firstname.appendChild(doc.createTextNode(first));
				student.appendChild(firstname);

				// lastname element
				Element lastname = doc.createElement("lastname");
				lastname.appendChild(doc.createTextNode(last));
				student.appendChild(lastname);

				// nickname element
				Element nickname = doc.createElement("nickname");
				nickname.appendChild(doc.createTextNode(nick));
				student.appendChild(nickname);

				// marks element
				Element marks = doc.createElement("marks");
				marks.appendChild(doc.createTextNode(mark));
				student.appendChild(marks);
				
			}
			// write the content into xml file
			TransformerFactory transformerFactory = TransformerFactory.newInstance();
			Transformer transformer = transformerFactory.newTransformer();
			DOMSource source = new DOMSource(doc);
			// StreamResult result = new StreamResult(new File("C:\\cars.xml"));
			StreamResult result = new StreamResult(new File("test.xml"));
			transformer.transform(source, result);

			// Output to console for testing
			StreamResult consoleResult = new StreamResult(System.out);
			transformer.transform(source, consoleResult);
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}