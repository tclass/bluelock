package de.htw.bluelock;

import java.io.IOException;

public class LocalLocker {

	public void logout() throws IOException{
		String shutdownCmd = "shutdown -l";	
		Process child = Runtime.getRuntime().exec(shutdownCmd);
	}
}
