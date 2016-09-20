
<!--communicator_RegisterMap communicator_slmbEMeter = 				{{ 	{"channel.map.i", 0x01},	//Current Channel Mapping Configuration
																	    {"channel.map.u", 0x02},	//Voltage Channel Mapping Configuration
																	{"creq.hi.th", 0x0A},		//High Threshold for Frequency Detection
																	{"meter.en", 0x00},			//Metering Enable
																	{"o.i.th", 0xB0},			//Over Current Threshold
																	{"o.v.th", 0x06},			//Over Voltage Threshold
																	{"phase.loss.th", 0x09},	//Voltage Phase Losing Threshold
																	{"s.x.config", 0x07},		//Zero-Crossing Configuration
																	{"sag.peak.det", 0x05},		//Sag and Peak Detector Period Configuration
																	{"sag.th", 0x08},			//Voltage Sag Threshold
  											  	  	  	  		}};
-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:output method="text"/>
	<xsl:template match="/">
		<xsl:text>communicator_RegisterMap communicator_slmbEMeter = {{ </xsl:text>
		<xsl:apply-templates select="/root/register">
			<xsl:sort select="@designator"/>
		</xsl:apply-templates>
		<xsl:text>}};</xsl:text>
	</xsl:template>
	<!-- xxx -->
	<xsl:template name="repeat-space">
		<xsl:param name="number"/>
		<xsl:if test="$number > 0">
			<xsl:value-of select="'&#x20;'"/>
			<xsl:call-template name="repeat-space">
				<xsl:with-param name="number" select="$number - 1"/>
			</xsl:call-template>
		</xsl:if>
	</xsl:template>
	<!-- xxx -->
	<xsl:template match="register">
		<xsl:variable name="comment-indentation">
			<xsl:value-of select="string-length(concat(@designator,'&#x20;', @address))"/>
		</xsl:variable>
		<xsl:variable name="address">
			<xsl:value-of select="concat('0x',substring-before(@address, 'H'))"/>
		</xsl:variable>
		<xsl:if test="position() > 1">
			<xsl:call-template name="repeat-space">
				<xsl:with-param name="number" select="54"/>
			</xsl:call-template>
			<xsl:text/>
		</xsl:if>
		<xsl:text>{&quot;</xsl:text>
		<xsl:value-of select="@designator"/>
		<xsl:text>&quot;, </xsl:text>
		<xsl:value-of select="$address"/>
		<xsl:text>},</xsl:text>
		<xsl:call-template name="repeat-space">
			<xsl:with-param name="number" select="30 - $comment-indentation"/>
		</xsl:call-template>
		<xsl:text>//</xsl:text>
		<xsl:value-of select="@description"/>
		<xsl:value-of select="'&#13;&#10;'"/>
		<xsl:text/>
	</xsl:template>
	<!-- xxx -->
	<xsl:template match="text()"/>
</xsl:stylesheet>