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

//Myaction2.java : definition d'un action qui sert a search media group.
public class Myaction2 extends AbstractAction {

	private ActionExample obj;
	private static final long serialVersionUID = 1L;

	//constructor
	public  Myaction2(String name,String shortDescription,ActionExample _obj){
		super(name);
		putValue(SHORT_DESCRIPTION,shortDescription);
		//putValue(MNEMONIC_KEY,mnemonic);
		this.obj=_obj;
	}


	public void actionPerformed(ActionEvent e){
		final JComponent[] inputs=new JComponent[]{
				new JLabel("Please input the name of media group"),obj.nmedia
		};
		obj.nmedia.setText("");
		JOptionPane.showMessageDialog(null,inputs,"Search Media Group",JOptionPane.PLAIN_MESSAGE);
		String cmdsm="searchgroup "+obj.nmedia.getText();
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