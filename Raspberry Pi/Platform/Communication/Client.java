/**
 * The code for using TCP came from https://www.geeksforgeeks.org/how-to-create-a-simple-tcp-client-server-connection-in-java/ 
 * 
 * @author Andrew Corbo
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class Client {
	//creates our universal variables, our port, IP, socket, and a list of banned ports in the available range    
	private int port = 0;
	private String IP = "x.x.x.x";
	private Socket socket = new Socket();
	private int[] bannedPorts = {9119,9306,9312,9389,9418,9535,9536,9695,9800};
	
	public Client (String IP_in, int port_in) throws IOException{//creates the constructor
		if(IP_in==null){ //throws an error if our IP doesnt exist
			throw new IllegalArgumentException("Ip does not exist");
		}
		//creates a series of variables to keep track of the parts of an IP
		String IPnumString="";
		int IPnum=0;
		int dots=0;
		for (int i=0; i<IP_in.length();i++){//iterates over the ip
			if (IP_in.charAt(i) != '.'){ //if we arent at a "." add the current character to the string keeping track of each "section"
				IPnumString+=""+IP_in.charAt(i);
			}
			else{ //if we are at a "." then we need to check if the previous number was valid
				dots++;//incremement our count of "."s to make sure we have the correct number at the end
				IPnum=-1;//set our number value to be negative one intitially, so it trips our error check even if it isnt changed
					try { // tries to parse the characters before the dot as an integer, this throws an error if they are integers
						IPnum = Integer.parseInt(IPnumString); //https://stackoverflow.com/questions/5585779/how-do-i-convert-a-string-to-an-int-in-java
					}
					catch (NumberFormatException e) {// if we couldnt convert it to an integer it is invalid
						throw new IllegalArgumentException("Please provide valid IP");
					}
					IPnumString="";//since we have the integer we can clear the string
					if ( 0 > IPnum || IPnum>255){//throw an error if the integer isnt between 0 and 255
						throw new IllegalArgumentException("Please provide valid IP");
					}
			}
		}
		if(dots!=3 && (!IP_in.equals("localhost"))){ //if there is the wrong number of dots and we arent using the local host, then throw an error
			throw new IllegalArgumentException("Please provide valid IP");
		}
		IP=IP_in;//if we passed all the error checks we can set our universal IP to be the one weve input
		boolean bannedPort= false; //set a boolean indicating our port isnt banned to false
		for(int i=0; i<bannedPorts.length;i++){ //iterate over our banned ports list, checking if our port we want to use is on it, then set our boolean to be true if it is
			if (port_in==bannedPorts[i]){
				bannedPort=true;
				break;
			}
		}
		if (port_in<9000 || port_in >=10000 || (port_in>=9100 && port_in <=9103)|| bannedPort==true){ //checks if the port is in the valid range and not on the ban list
			throw new IllegalArgumentException("Please provide an unallocated port between 9000 and 9999, see this link for a list of open ports https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers ");
		}
		port=port_in; //if we passed the checks we can use this port
		System.out.print("Attempting to connect to "+IP+":"+port);//indicate to the user that we are attempting to connect to the desired ip and socket
		while(true){ //loop until we break out
			try{ //attempt to connect
			// create a socket to connect to the server
			socket.connect(new InetSocketAddress(IP, port), 1000);
			System.out.println("\n"+"Connection Successful!");
			break;//if we connected, then break out of our infinite loop
			}
			catch (IOException e){ //if the server doesnt exist yet, reset everything and try again
				socket.close();
				socket = new Socket();
				for (int i=0; i<3; i++){ //this will add a small loading bar to indicate to the user that the program is still running, and just waiting for a connection
					System.out.print('.');
					try {   //code from https://stackoverflow.com/questions/24104313/how-do-i-make-a-delay-in-java
						Thread.sleep(500);
					} catch (InterruptedException f) {
						Thread.currentThread().interrupt();
					}
				}
				System.out.print("\b"+"\b"+"\b"+"   "+"\b"+"\b"+"\b");
			}
		}
	}
	public void write(String content) throws IOException{ //creates our write method
		// Setup output stream to send data to the server
		PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
		// Send  the message to the server
		out.println(content);
	}
	public String read()throws IOException{ //creates our read method
		System.out.println("Currently Reading");
		// Setup input stream to receive data from the server
		BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		// Receive response from the server
		String response = in.readLine();
		return response;
	}
	public void close()throws IOException{
		// Close the socket
		socket.close();
	}
	public static void jsonSave(String data, String path) throws IOException{ //creates a method to save data to a file
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
		JsonWriter.write(data+"----");//writes the incoming data plus a break character
		JsonWriter.close();//closes the file
		
	} 
	public static void takeTurns(Client client, Scanner scan, String file) throws IOException{ //creates a static method that accepts a cllient and a scanner and demos the protocol by having the client and server "take turns" talking back and forth
		//creates variables to store the data being sent back and forth
		String incoming="";
		String outgoing="";
		//loops until we break it. For this method, we break out of the loop when either device sends a message strictly containing "end"
		while (true){
			System.out.print("Type text to send: ");
			outgoing=scan.nextLine();
			client.write(outgoing);
			if (outgoing.equals( "end")){
				try {   //code from https://stackoverflow.com/questions/24104313/how-do-i-make-a-delay-in-java
					Thread.sleep(100);// sleeps to give the server time to process the end message before the client shuts down
				} catch (InterruptedException f) {
					Thread.currentThread().interrupt();
				}
				break;
			}
			incoming =client.read();
			if (incoming.equals( "end")){
				break;
			}
			System.out.print("Server says: ");
			System.out.println(incoming);
			jsonSave(incoming,file);
		}
		client.close(); //once we escaped the loop we close the server
		System.out.println("Connection Terminated"); //iform the user the connection is terminated
	}
	public static void main(String args[]) throws IOException {
		Client testClient = new Client("localhost",9090);//creates our new client
		Scanner scan = new Scanner(System.in); //creates our scanner to read from the terminal
		takeTurns(testClient, scan, "client.json"); //run our method to send data back and forth
	}
}
