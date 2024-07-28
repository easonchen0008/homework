<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/"> 
  <html>
      <body background="images\back.jpg">
      <font size="7">
        <h1 align="center">走到了盡頭，你看了出去的門</h1>
        </font>
          <table align="center" border="0">	
                <center>
                  <img src="images/end.png" alt="Welcome~"></img>
                </center>
                 <tr>
                 <xsl:for-each select="introduction/page"> 
		      <td align="center">
<font size="15">
                 <a>
                    <xsl:attribute name="href">
                       <xsl:value-of select="name"/>
			        </xsl:attribute>                    
		            <xsl:value-of select="title"/>
                 </a>
</font>
		      </td>
		    </xsl:for-each>
	    	</tr>
        </table>
      </body>
  </html>
</xsl:template>
</xsl:stylesheet>