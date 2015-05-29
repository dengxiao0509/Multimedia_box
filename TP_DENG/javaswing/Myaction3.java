package javaswing;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

//Myaction3.java : definition d'un action qui sert a exit;
public class Myaction3 extends AbstractAction {
	private static final long serialVersionUID = 1L;

	//constructor
	public  Myaction3(String name,String shortDescription){
		super(name);
		putValue(SHORT_DESCRIPTION,shortDescription);
		//putValue(MNEMONIC_KEY,mnemonic);
	}


	public void actionPerformed(ActionEvent e){
		System.exit(0);
	}
}
