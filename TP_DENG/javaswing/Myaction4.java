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

//Myaction4.java : definition d'un action qui sert a lister tous les medias d'un meme type;
public class Myaction4 extends AbstractAction {
	private static final long serialVersionUID = 1L;
	private ActionExample obj;


	//constructor
	public  Myaction4(String name,String shortDescription,ActionExample _obj){
		super(name);
		putValue(SHORT_DESCRIPTION,shortDescription);
		//putValue(MNEMONIC_KEY,mnemonic);
		this.obj=_obj;
	}



	public void actionPerformed(ActionEvent e){
		final JComponent[] inputs=new JComponent[]{
				new JLabel("Please input the name of the type of media to list(Photo,Vedio,Film)"),obj.nmedia
		};
		obj.nmedia.setText("");
		JOptionPane.showMessageDialog(null,inputs,"Search Media of The Same Type",JOptionPane.PLAIN_MESSAGE);
		String cmdsm="showall "+obj.nmedia.getText();
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
