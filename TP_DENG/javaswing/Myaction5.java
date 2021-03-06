package javaswing;

import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

import javax.swing.AbstractAction;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

//Myaction5.java : definition d'un action qui sert a play media;
public class Myaction5 extends AbstractAction {
	private static final long serialVersionUID = 1L;
	private ActionExample obj;


	//constructor
	public  Myaction5(String name,String shortDescription,ActionExample _obj){
		super(name);
		putValue(SHORT_DESCRIPTION,shortDescription);
		//putValue(MNEMONIC_KEY,mnemonic);
		this.obj=_obj;
	}



	public void actionPerformed(ActionEvent e){
		final JComponent[] inputs=new JComponent[]{
				new JLabel("Please input the name of the media to play"),obj.nmedia
		};
		obj.nmedia.setText("");
		JOptionPane.showMessageDialog(null,inputs,"Play Media",JOptionPane.PLAIN_MESSAGE);
		String cmdsm="play "+obj.nmedia.getText();
		InputStream ins=new ByteArrayInputStream(cmdsm.getBytes());
		BufferedReader cin = new BufferedReader(new InputStreamReader(ins));


		//System.out.print("Message: ");
		try {
			String message = cin.readLine();
			String response= obj._client.send(message);
			obj.textarea.append(response + "\n");

		}
		catch (java.io.IOException _e) {
			System.out.println("Client: IO error");
			return;
		} 
	}
}
