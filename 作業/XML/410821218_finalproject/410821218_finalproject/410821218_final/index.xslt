<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
  <html>
	<body background="images\back.jpg">
     <h2 align="center">Hello</h2>
     <center>
       <img src="images/winnie.webp" alt="Welcome~"></img>
     </center>
  	  <table align="center" border="0">		
	    <tr>
	   	    <xsl:for-each select="index/page"> 
		      <td align="center">
                 <a>
                    <xsl:attribute name="href">
                       <xsl:value-of select="name"/>
			        </xsl:attribute>                    
		            <xsl:value-of select="title"/>
                 </a>
		      </td>
		    </xsl:for-each>
	    </tr>
	  </table>
	</body>
  </html>
</xsl:template>
</xsl:stylesheet>