package javaswing;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

//Test.java : sert a tester (inclus main)
public class Test {

	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3333;
	
	public static void main (String argv[]){

		


		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;

		if (argv.length >=2) host = argv[0];
		if (argv.length >=3) port = Integer.parseInt(argv[1]);

		Client client = null;

		try {
			client = new Client(host, port);
		}
		catch (Exception e) {
			System.out.println("Client: couldn't connect: "+host+":"+port);
			System.exit(1);
		}

		System.out.println("Client connected to "+host+":"+port);
		
		ActionExample ac = new ActionExample(client);






	}

}