import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class JDBCExample_CreateTable {
   static final String DB_URL = "jdbc:mysql://localhost:3306/XMLCLASS";
   static final String USER = "root";
   static final String PASS = "a19991130";

   public static void main(String[] args) {
      // Open a connection
      try(Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
         Statement stmt = conn.createStatement();
      ) {		      
          String sql = "CREATE TABLE score_data" +
                   "(id INTEGER not NULL, " +
                   " xml_class VARCHAR(255), " + 
                   " data_structure VARCHAR(255), " + 
                   " algorithm VARCHAR(255), " + 
                   " network VARCHAR(255), " + 
                   " PRIMARY KEY ( id ))"; 

         stmt.executeUpdate(sql);
         System.out.println("Created table in given database...");   	  
      } catch (SQLException e) {
         e.printStackTrace();
      } 
   }
}