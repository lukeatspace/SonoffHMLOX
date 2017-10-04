void DEBUG(String DebugMessage, String Tag, byte Severity) {
#ifdef UDPDEBUG
  UDPClient.UDP.beginPacket(SYSLOGIP, SYSLOGPORT);
  byte severity = 8 + Severity;
  UDPClient.UDP.write(String("<" + String(severity) + ">" + String(GlobalConfig.DeviceName) + " " + Tag + " " + DebugMessage).c_str());
  UDPClient.UDP.endPacket();
#endif

#ifdef SERIALDEBUG
  Serial.println(DebugMessage);
#endif
}
