<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
  <html>
	<body background="images\back.jpg">
	<font size="7">
     <h1 align="center">你被困在一個地牢中，想辦法逃出去</h1>
	 </font>
     <center>
       <img src="images/imgg1.jpg" alt="Welcome~"></img>
     </center>
  	  <table align="center" border="0">		
	    <tr>
	   	    <xsl:for-each select="index/page"> 
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