<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/"> 
  <html>
      <body background="images\back.jpg">
        <h2 align="center">羅仁甫's Features</h2>
          <table align="center" border="0">	
                <center>
                  <img src="images/me.png" alt="Welcome~"></img>
                </center>
                <xsl:for-each select="introduction/feature">
                    <tr>
                        <td>
                          <xsl:value-of select="."/>
                        </td>
                    </tr>
                </xsl:for-each>
        </table>
      </body>
  </html>
</xsl:template>
</xsl:stylesheet>