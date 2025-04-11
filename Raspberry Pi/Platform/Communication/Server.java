/**
 * The code for using TCP came from https://www.geeksforgeeks.org/how-to-create-a-simple-tcp-client-server-connection-in-java/ 
 * 
 * @author Andrew Corbo
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class Server {
	//creates the universal variables, the port to use, a boolean needed by multiple methods, and the server and client sockets
	private int port = 0;
	ServerSocket serverSocket = new ServerSocket();
	Socket clientSocket= new Socket();
	int[] bannedPorts = {9119,9306,9312,9389,9418,9535,9536,9695,9800};
	
	public Server(int port_in)throws IOException{//creates the constructor
		//checks if the port is in a list of used ports.
		boolean bannedPort= false; 
		for(int i=0; i<bannedPorts.length;i++){
			if (port_in==bannedPorts[i]){
				bannedPort=true;
				break;
			}
		}
		if (port_in >=10000 || (port_in>=9100 && port_in <=9103)|| bannedPort==true){ //checks if the port is valid 
			throw new IllegalArgumentException("Please provide an unallocated port between 9000 and 9999, see this link for a list of open ports https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers ");
		}
		port=port_in; //sets the universal port to the one that was input
		// create a server socket at the port
		serverSocket = new ServerSocket(9090);
		System.out.println("Server is running and waiting for client connection...");
		// Accept incoming client connection
		clientSocket = serverSocket.accept();
		System.out.println("Client connected!");
	}
	public void write(String content) throws IOException{ //creates our method to write to the client
		PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true); // Setup output stream to send data to the server
		out.println(content); // send the data
	}
	public String read()throws IOException{//creates our method to read from the client
		System.out.println("Currently Reading");
		BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); // Setup input stream to receive data from the server
		String response = in.readLine();// Receive response from the server
		return response;
	}
	public void close()throws IOException{
		// Close the socket
		serverSocket.close();
	}
	public static void jsonSave(String data, String path) throws IOException{ //creates our method to save data to a file
		//This method assumes data incoming is properly formatted for the desitnation and does not modify it
		// https://www.w3schools.com/java/java_files_create.asp
		
		// the code below checks that there isnt a "break" character anywhere in the incoming data,
		for (int i=3; i<data.length(); i++){
			String tempData=(""+data.charAt(i-3))+(""+data.charAt(i-2))+(""+data.charAt(i-1))+(""+data.charAt(i));
			if (tempData.equals("----")){
				throw new IllegalArgumentException("Data to save cannot contain \"----\"");
			}
		}
		FileWriter JsonWriter = new FileWriter(path, true);// opens the file
		JsonWriter.write(data+"----"); //writes the incoming data plus the break character
		JsonWriter.close(); //closes the file
		
	} 
	public static void takeTurns(Server server, Scanner scan, String file) throws IOException{ //creates a static method that accepts a server and a scanner and demos the protocol by having the client and server "take turns" talking back and forth
		//creates variables to store the data being sent back and forth
		String incoming="";
		String outgoing="";
		//loops until we break it. For this method, we break out of the loop when either device sends a message strictly containing "end"
		while (true){
			incoming =server.read();
			if (incoming.equals( "end")){
				break;
			}
			System.out.print("Client says: ");
			System.out.println(incoming);
			jsonSave(incoming,file);
			System.out.print("Type text to send: ");
			outgoing=scan.nextLine();
			server.write(outgoing);
			if (outgoing.equals( "end")){
				try {   //code from https://stackoverflow.com/questions/24104313/how-do-i-make-a-delay-in-java
					Thread.sleep(100); //sleeps to give the client time to process the end message before the server shuts down
				} catch (InterruptedException f) {
					Thread.currentThread().interrupt();
				}
				break;
			}
		}
		server.close(); //once we escaped the loop we close the server
		System.out.println("Connection Terminated"); // inform the user we terminated the connection
	}
	public static void main(String args[]) throws IOException {
		Server testServer = new Server(9090); //create our server
		Scanner scan = new Scanner(System.in); //create our scanner to read from the terminal
		takeTurns(testServer, scan, "server.json"); // run our method to take turns sending data back and forth
	}
    
}

