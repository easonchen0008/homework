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
				int id = rs.getInt("id");
				String mark = rs.getString("xml_class");
				String first = rs.getString("data_structure");
				String last = rs.getString("algorithm");
				String nick = rs.getString("network");
				System.out.print("ID: " + id);
				System.out.print(", Mark: " + mark);
				System.out.print(", First: " + first);
				System.out.print(", Last: " + last);
				System.out.println(", Nick: " + nick);
				
			}
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
	}
}